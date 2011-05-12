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
	QWidget(parent), mEngine(0)
{
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAutoFillBackground(false);
	setMinimumSize(320, 240);

	mCameraRotationDelta = .35f * Ogre::Math::PI / 180.f;
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

void QSteelWidget::initSteel()
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
	mEngine->camera()->setMode(Steel::Camera::TARGET);
}

void QSteelWidget::mousePressEvent(QMouseEvent *e)
{
	cout << "QSteelWidget::mousePressEvent" << endl;
	mLastMousePos = mLastMousePressPos = e->pos();

}

void QSteelWidget::mouseReleaseEvent(QMouseEvent *e)
{
	cout << "QSteelWidget::mouseReleaseEvent" << endl;
	mLastMousePos = e->pos();

}

void QSteelWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPoint delta = e->pos() - mLastMousePos;
	if (e->buttons().testFlag(Qt::LeftButton))
	{

	}
	else if (e->buttons().testFlag(Qt::MiddleButton))
	{
		if (e->modifiers().testFlag(Qt::ControlModifier))//zoom
		{
			cout<<float(e->y())/float(mLastMousePos.y())<<endl;
			mEngine ->camera()->zoom(0.f, delta.y()/float(mLastMousePos.y()));
		}
		else //rotation

		{
			mEngine->camera()->rotateAroundTarget(-mCameraRotationDelta * float(delta.x()));
			mEngine->camera()->pitchAroundTarget(-mCameraRotationDelta * float(delta.y()));
		}
	}
	mLastMousePos = e->pos();
}

void QSteelWidget::wheelEvent(QWheelEvent *e)
{
	cout << "QSteelWidget::wheelEvent" << endl;

}
