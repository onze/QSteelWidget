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
#include <OgreLogManager.h>
#include <X11/Xlib.h>

#include "QSteelWidget.h"

#include "QtOgreConversions.h"

#include "unittests.h"

QSteelWidget::QSteelWidget(QWidget * parent) :
	QWidget(parent), mIsSteelReady(false), mEngine(0), mIsInputGrabbed(false), mTimer(0), mLevelName(""),
			mProjectRootdir("./")
{
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAutoFillBackground(false);
	setMinimumSize(320, 240);

	setAcceptDrops(true);

	unitMain();
}

QSteelWidget::~QSteelWidget()
{
	if (mEngine)
	{
		mEngine->shutdown();
		delete mEngine;
	}
}

unsigned long QSteelWidget::addInanimate(QString meshName, QVector3D pos, QVector4D rot)
{
	quickLog("QSteelWidget::drop_inanimate(meshName=" + meshName + " dropTargetDist="
			+ QString("(%1, %2, %3)").arg(pos.x()).arg(pos.y()).arg(pos.z()));
	if (mLevel == NULL)
	{
		quickLog("mLevel == NULL !");
		return 0L;
	}
	Ogre::Quaternion r = mEngine->camera()->camNode()->getOrientation();
	if(r!=convert(rot))
	{
		cout<<"blem !"
				<<"cam quat:"<<Ogre::StringConverter::toString(r)
				<<" -> as vec4: "
				<<toString(convert(r))<<endl
				<<"given vec4:"
				<<toString(rot)
				<<" -> as quat: "<<Ogre::StringConverter::toString(convert(rot))<<endl;
	}
	unsigned long id = mLevel->createInanimate(q2o_string(meshName), convert(pos), convert(rot));
	update();
	return id;
}


QVector3D QSteelWidget::cameraPosition()
{
	return convert(mEngine->camera()->camNode()->getPosition());
}

void QSteelWidget::cameraPosition(QVector3D pos)
{
	mEngine->camera()->camNode()->setPosition(convert(pos));
}

QVector4D QSteelWidget::cameraRotation()
{
	return convert(mEngine->camera()->camNode()->getOrientation());
}

void QSteelWidget::cameraRotation(QVector4D rot)
{
	mEngine->camera()->camNode()->setOrientation(convert(rot));
}


QVector3D QSteelWidget::dropTargetPosition(QVector3D delta)
{
	if (mEngine == NULL)
		return QVector3D();
	Ogre::Vector3 pos = mEngine->camera()->camNode()->getPosition();
	pos += mEngine->camera()->camNode()->getOrientation() * convert(delta);
	return convert(pos);
}

QVector4D QSteelWidget::dropTargetRotation()
{
	return convert(mEngine->camera()->camNode()->getOrientation());
}

void QSteelWidget::closeEvent(QCloseEvent *e)
{
	if (mEngine)
		mEngine->shutdown();
	e->accept();
}

void QSteelWidget::dragEnterEvent(QDragEnterEvent *e)
{
	e->setAccepted(true);
}

void QSteelWidget::dragMoveEvent(QDragMoveEvent *e)
{
	e->setAccepted(true);
}

void QSteelWidget::dropEvent(QDropEvent *e)
{
	if (e->mimeData()->hasUrls())
	{
		QList<QUrl> urlList = e->mimeData()->urls();
		if (urlList.size() > 0)
		{
			quickLog(Ogre::String(urlList[0].toString().toStdString()));
			emit onItemDropped(QString(urlList[0].toString().toStdString().c_str()));
		}
	}
	e->setAccepted(true);
}

void QSteelWidget::engineModeUpdate(void)
{
	if (!mEngine->mainLoop(true))
		stopEngineMode();
}

void QSteelWidget::grabInputs(void)
{
	mIsInputGrabbed = true;
	grabMouse();
	setCursor(QCursor(Qt::BlankCursor));
	setMouseTracking(true);
	grabKeyboard();

}

QVector3D QSteelWidget::inanimatePosition(unsigned long id)
{
	if (mLevel == NULL)
	{
		quickLog("QSteelWidget::inanimatePosition(): no level loaded.");
		return QVector3D();
	}
	Steel::Inanimate *ina = mLevel->getInanimate(id);
	if (ina == NULL)
	{
		quickLog("QSteelWidget::inanimatePosition(): no inanimate for id " + QString::number(id) + ".");
		return QVector3D();
	}
	//TODO: return a Descriptor instead ?
	//	Ogre::Vector3 oPos=ina->node()->getPosition();
	//	QVector3D qPos(oPos.x,oPos.y,oPos.z);
	//	return qPos;
	return convert(ina->node()->getPosition());
}

void QSteelWidget::initSteel()
{
	cout << "QSteelWidget::initSteel()" << endl;
	Ogre::Log *defaultLog = (new Ogre::LogManager())->createLog("ogre_log.log", true, false, true);
	defaultLog->addListener(this);

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
	//read here for more: http://www.ogre3d.org/forums/viewtopic.php?f=2&p=311635#p311635
	XSync(xInfo.display(), False);

#endif

	mEngine->embeddedInit("plugins.cfg", widgetHandle.toStdString(), width(), height(), defaultLog->getName());
	defaultLog->logMessage("steel widget ready.");
	if (!(mProjectRootdir == "./" && mLevelName == ""))
		setLevel(QString(mProjectRootdir.c_str()), QString(mLevelName.c_str()));
	mIsSteelReady = true;
	emit onSteelReady();
}

void QSteelWidget::keyPressEvent(QKeyEvent *e)
{
	//	cout<<"QSteelWidget::keyPressEvent"<<endl;
	OIS::KeyEvent evt = qtToOisKeyEvent(e);
	mEngine->inputMan()->keyPressed(evt);
	e->accept();
}

void QSteelWidget::keyReleaseEvent(QKeyEvent *e)
{
	//	cout<<"QSteelWidget::keyReleaseEvent"<<endl;
	OIS::KeyEvent evt = qtToOisKeyEvent(e);
	mEngine->inputMan()->keyReleased(evt);
	e->accept();
}

void QSteelWidget::messageLogged(	const Ogre::String &message,
									Ogre::LogMessageLevel lml,
									bool maskDebug,
									const Ogre::String &logName)
{
	emit onNewLogLine(QString(message.c_str()));
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

void QSteelWidget::paintEvent(QPaintEvent *e)
{
	if (mEngine)
		mEngine->redraw();
	e->accept();
}

QPaintEngine *QSteelWidget::paintEngine() const
{
	return 0;
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
	if (mIsInputGrabbed)
		stopEngineMode();// and start editor mode
	else
		startEngineMode();// and stop editor mode

	//to keep last
	mLastMousePosition = e->pos();
	e->accept();
}

void QSteelWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPoint move = e->pos() - mLastMousePosition;

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

OIS::MouseEvent QSteelWidget::qtToOisMouseEvent(QMouseEvent *e)
{
	QPoint move = e->pos() - mLastMousePosition;
	OIS::MouseState ms = OIS::MouseState();
	ms.X.rel = move.x();
	ms.Y.rel = move.y();

	QPoint abspos = mapToGlobal(e->pos());
	ms.X.abs = abspos.x();
	ms.Y.abs = abspos.y();

	OIS::MouseEvent evt = OIS::MouseEvent(mEngine->inputMan()->mouse(), ms);
	return evt;
}

void QSteelWidget::releaseInputs(void)
{
	mIsInputGrabbed = false;
	releaseMouse();
	setCursor(QCursor(Qt::ArrowCursor));
	setMouseTracking(false);
	releaseKeyboard();
}

void QSteelWidget::setLevel(QString projectRootdir, QString levelName)
{
	cout
			<< (("QSteelWidget::setLevel(projectRootdir:" + projectRootdir + ", levelName=" + levelName + ")").toStdString())
			<< endl;
	mProjectRootdir = Ogre::String(projectRootdir.toStdString().c_str());
	mLevelName = Ogre::String(levelName.toStdString().c_str());
	if (mEngine)
	{
		mEngine->setRootdir(Ogre::String(projectRootdir.toStdString().c_str()));
		mLevel = mEngine->createLevel(Ogre::String(levelName.toStdString().c_str()));
	}
	else
	{
		cout << "WARNING: there's no engine yet." << endl;
	}
}

void QSteelWidget::showEvent(QShowEvent *e)
{
	QWidget::showEvent(e);
	if (e->isAccepted())
	{
		if (mEngine)
			mEngine->redraw();
		else
			initSteel();
	}
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
	mTimer->start(1000.f / 60.f);
}

void QSteelWidget::stopEngineMode()
{
	if (!mIsInputGrabbed)
		return;
	releaseInputs();
	mEngine->abortMainLoop();
	//	mEngine->releaseInputs();
	mTimer->stop();
	disconnect(mTimer, SIGNAL(timeout()), this, SLOT(engineModeUpdate()));
	delete mTimer;
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
			keycode = OIS::KC_ESCAPE;
			break;
		default:
			break;
	}
	OIS::KeyEvent evt(mEngine->inputMan()->keyboard(), keycode, 0);
	return evt;
}

