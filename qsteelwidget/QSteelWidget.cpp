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

class equals
{
public:
	equals(int _v) :
		v(_v)
	{
	}
	;
	bool operator()(const int& value)
	{
		return value == v;
	}
protected:
	int v;
};

QSteelWidget::QSteelWidget(QWidget * parent) :
	QWidget(parent), mEngine(0)
{
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAutoFillBackground(false);
	setMinimumSize(320, 240);

	mKeysPressed = std::list<int>();

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(engineModeUpdate()));

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
	update();
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
	//to keep last
	mLastMousePosition = e->pos();
}

void QSteelWidget::mouseReleaseEvent(QMouseEvent *e)
{
	//to keep last
	mLastMousePosition = e->pos();
}

void QSteelWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
	cout << "QSteelWidget::doubleClickEvent " << isInputGrabbed << endl;
	if (isInputGrabbed)
		stopEngineMode();// and start editor mode
	else
		startEngineMode();// and stop editor mode
	//to keep last
	mLastMousePosition = e->pos();
}

void QSteelWidget::startEngineMode(void)
{
	grabInputs();
	timer->start(int(1000.f / 60));
}

void QSteelWidget::stopEngineMode()
{
	releaseInputs();
	timer->stop();
}

void QSteelWidget::engineModeUpdate(void)
{
	float dx = .0f, dy = .0f, dz = .0f, speed = 2.f;
//	cout << "keys: ";
	for (list<int>::iterator it = mKeysPressed.begin(); it != mKeysPressed.end(); ++it)
	{
//		cout << *it << " ";
		switch (*it)
		{
			case Qt::Key_W:
				dz -= speed;
				break;
			case Qt::Key_A:
				dx -= speed;
				break;
			case Qt::Key_S:
				dz += speed;
				break;
			case Qt::Key_D:
				dx += speed;
				break;
			case Qt::Key_Space:
				dy += speed;
				break;
			case Qt::Key_Shift:
				dy -= speed;
				break;
			case Qt::Key_Escape:
				stopEngineMode();
				break;
			default:
				break;
		}
	}
//	cout << endl;
	mEngine->camera()->translate(dx, dy, dz);

}

void QSteelWidget::grabInputs(void)
{
	isInputGrabbed = true;
	grabMouse();
	setCursor(QCursor(Qt::BlankCursor));
	setMouseTracking(true);
	grabKeyboard();

}

void QSteelWidget::releaseInputs(void)
{
	isInputGrabbed = false;
	releaseMouse();
	setCursor(QCursor(Qt::ArrowCursor));
	setMouseTracking(false);
	releaseKeyboard();
}

void QSteelWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPoint move = e->pos() - mLastMousePosition;
	cout << "QSteelWidget::mouseMoveEvent():" << " x:" << e->x() << " y:" << e->y() << " dx:" << move.x() << " dy:"
			<< move.y() << endl;
	if (isInputGrabbed)
	{
		mEngine->camera()->lookTowards(-float(move.y()), -float(move.x()), .0f, .1f);
		QPoint newpos = QPoint(width() / 2, height() / 2);
		QCursor::setPos(mapToGlobal(newpos));
		mLastMousePosition = newpos;
	}
	else
	{
		//to keep last
		mLastMousePosition = e->pos();
	}
	mEngine->update();
}

void QSteelWidget::wheelEvent(QWheelEvent *e)
{
	//to keep last
	mLastMousePosition = e->pos();
}

void QSteelWidget::keyPressEvent(QKeyEvent *e)
{
	if (isInputGrabbed)
	{
		mKeysPressed.push_front(e->key());
		mKeysPressed.unique();
	}
}

void QSteelWidget::keyReleaseEvent(QKeyEvent *e)
{
	mKeysPressed.remove_if(equals(e->key()));
}

