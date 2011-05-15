/*
 * QSteelWidget.cpp
 *
 *  Created on: 2011-05-07
 *      Author: onze
 */

#include <iostream>

using namespace std;

#include <QtGui>
#include <QX11Info>
#include <QWidget>
#include <OgreMath.h>
#include <X11/Xlib.h>

#include <Camera.h>

#include "QSteelWidget.h"

QSteelWidget::QSteelWidget(QWidget * parent) :
	QWidget(parent), mEngine(0), mIsInputGrabbed(false), mTimer(0)
{
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAutoFillBackground(false);
	setMinimumSize(320, 240);

}

QSteelWidget::~QSteelWidget()
{
	delete mEngine;
}

void QSteelWidget::showEvent(QShowEvent *e)
{
	QWidget::showEvent(e);
	if (e->isAccepted() && !mEngine)
	{
		initSteel();
	}
}

void QSteelWidget::paintEvent(QPaintEvent *e)
{
	if (mEngine)
		mEngine->update();
	e->accept();
}

QPaintEngine *QSteelWidget::paintEngine() const
{
	return 0;
}

void QSteelWidget::moveEvent(QMoveEvent *e)
{
	QWidget::moveEvent(e);

	if (e->isAccepted())
	{
		if (mEngine)
			mEngine->resizeWindow(width(), height());
		update();
	}
}

void QSteelWidget::resizeEvent(QResizeEvent *e)
{
	QWidget::resizeEvent(e);

	if (e->isAccepted() && mEngine)
	{
		const QSize &newSize = e->size();
		mEngine->resizeWindow(newSize.width(), newSize.height());
		update();
	}
}

void QSteelWidget::initSteel(void)
{
	mEngine = new Steel::Engine();

#if defined(Q_WS_WIN) || defined(Q_WS_MAC)

	QString widgetHandle=QString::number((size_t)((HWND)winId()));

#else
	//GLX: poslong:posint:poslong (display*:screen:windowHandle)
	QX11Info xInfo = x11Info();

	QString widgetHandle("");
	widgetHandle += QString::number(xInfo.appScreen());
	widgetHandle += ":";
	widgetHandle += QString::number(xInfo.screen());
	widgetHandle += ":";
	widgetHandle += QString::number(winId());

	//the window won't be initialised properly until it has been mapped(shown), giving the error about the wrong
	//screen/server. You can delay creation of the ogre window until the first paint event, since the window will have
	//been completely initialised by then. Alternativly you can create a function to create the renderwindow, and
	//manually XMapWindow yourself before creating the ogre window.
	//read here for more explanations: http://www.ogre3d.org/forums/viewtopic.php?f=2&p=311635#p311635
	XSync(xInfo.display(), False);

#endif

	mEngine->embeddedInit("plugins.cfg", widgetHandle.toStdString(), width(), height());
}

void QSteelWidget::mousePressEvent(QMouseEvent *e)
{
	if (mIsInputGrabbed)
	{
		//to keep last
		OIS::MouseEvent evt = qtToOisMouseEvent(e);
		OIS::MouseButtonID btn = OIS::MB_Left;
		switch (e->button())
		{
			case Qt::LeftButton:
				btn = OIS::MB_Left;
				break;
			case Qt::MiddleButton:
				btn = OIS::MB_Middle;
				break;
			case Qt::RightButton:
				btn = OIS::MB_Right;
				break;
			default:
				e->accept();
				return;
		}
		mEngine->inputMan()->mousePressed(evt, btn);
	}
	mLastMousePosition = e->pos();
	e->accept();
}

void QSteelWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (mIsInputGrabbed)
	{
		//to keep last
		OIS::MouseEvent evt = qtToOisMouseEvent(e);
		OIS::MouseButtonID btn = OIS::MB_Left;
		switch (e->button())
		{
			case Qt::LeftButton:
				btn = OIS::MB_Left;
				break;
			case Qt::MiddleButton:
				btn = OIS::MB_Middle;
				break;
			case Qt::RightButton:
				btn = OIS::MB_Right;
				break;
			default:
				e->accept();
				return;
		}
		mEngine->inputMan()->mouseReleased(evt, btn);
	}
	mLastMousePosition = e->pos();
	e->accept();
}

void QSteelWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
	cout << endl << "QSteelWidget::doubleClickEvent " << mIsInputGrabbed << endl;
	if (mIsInputGrabbed)
		stopEngineMode();// and start editor mode
	else
		startEngineMode();// and stop editor mode

	//to keep last
	mLastMousePosition = e->pos();
	e->accept();
}

void QSteelWidget::startEngineMode(void)
{
	if (mIsInputGrabbed)
		return;
	grabInputs();
	//OIS being screwed up by Qt, we have to manually grab mouse and keyboard and
	//forward their events to the engine's inputManager.
	//	mEngine->grabInputs();
	mTimer = new QTimer(this);
	connect(mTimer, SIGNAL(timeout()), this, SLOT(engineModeUpdate()));
	mTimer->start(int(1000.f / 60.f));
}

void QSteelWidget::stopEngineMode()
{
	if (!mIsInputGrabbed)
		return;
	releaseInputs();
	//	mEngine->releaseInputs();
	mTimer->stop();
	disconnect(mTimer, SIGNAL(timeout()), this, SLOT(engineModeUpdate()));
	delete mTimer;
}

void QSteelWidget::engineModeUpdate(void)
{
	mEngine->update();
}

void QSteelWidget::grabInputs(void)
{
	mIsInputGrabbed = true;
	grabMouse();
	setCursor(QCursor(Qt::BlankCursor));
	setMouseTracking(true);
	grabKeyboard();

}

void QSteelWidget::releaseInputs(void)
{
	mIsInputGrabbed = false;
	releaseMouse();
	setCursor(QCursor(Qt::ArrowCursor));
	setMouseTracking(false);
	releaseKeyboard();
}

OIS::MouseEvent QSteelWidget::qtToOisMouseEvent(QMouseEvent *e)
{
	QPoint move = e->pos() - mLastMousePosition;
	OIS::MouseState ms = OIS::MouseState();
	ms.X.rel = move.x();
	ms.Y.rel = move.y();

	QPoint abspos=mapToGlobal(e->pos());
	ms.X.abs = abspos.x();
	ms.Y.abs = abspos.y();

	OIS::MouseEvent evt = OIS::MouseEvent(mEngine->inputMan()->mouse(), ms);
	return evt;
}

void QSteelWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPoint move = e->pos() - mLastMousePosition;
	cout << "QSteelWidget::mouseMoveEvent():" << " x:" << e->x() << " y:" << e->y() << " dx:" << move.x() << " dy:"
			<< move.y() << endl;
	if (mIsInputGrabbed)
	{
		OIS::MouseEvent evt = qtToOisMouseEvent(e);
		mEngine->inputMan()->mouseMoved(evt);

		QPoint pos(min(max(0, e->x()), width()), min(max(0, e->y()), height()));
		QCursor::setPos(mapToGlobal(pos));

		mLastMousePosition = pos;
	}
	else
	{
		//to keep last
		mLastMousePosition = e->pos();
	}
	e->accept();
}

void QSteelWidget::wheelEvent(QWheelEvent *e)
{
	//to keep last
	mLastMousePosition = e->pos();
}
OIS::KeyEvent QSteelWidget::qtToOisKeyEvent(QKeyEvent *e)
{
	OIS::KeyCode keycode = OIS::KC_ESCAPE;
	switch (e->key())
	{
		case Qt::Key_W:
			keycode = OIS::KC_W;
			break;
		case Qt::Key_A:
			keycode = OIS::KC_A;
			break;
		case Qt::Key_S:
			keycode = OIS::KC_S;
			break;
		case Qt::Key_D:
			keycode = OIS::KC_D;
			break;
		case Qt::Key_Space:
			keycode = OIS::KC_SPACE;
			break;
		case Qt::Key_Shift:
			keycode = OIS::KC_LSHIFT;
			break;
		case Qt::Key_Escape:
			stopEngineMode();
			keycode = OIS::KC_ESCAPE;
			break;
		default:
			break;
	}
	OIS::KeyEvent evt(mEngine->inputMan()->keyboard(), keycode, 0);
	return evt;
}

void QSteelWidget::keyPressEvent(QKeyEvent *e)
{
	e->accept();
	OIS::KeyEvent evt = qtToOisKeyEvent(e);
	mEngine->inputMan()->keyPressed(evt);
}

void QSteelWidget::keyReleaseEvent(QKeyEvent *e)
{
	e->accept();
	OIS::KeyEvent evt = qtToOisKeyEvent(e);
	mEngine->inputMan()->keyReleased(evt);
}

