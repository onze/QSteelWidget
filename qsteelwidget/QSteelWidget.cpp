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

#include <OgreSceneNode.h>
#include <OgreMeshManager.h>
#include <OgreEntity.h>

#include <X11/Xlib.h>

#include <steeltypes.h>
#include <Debug.h>

#include "QSteelWidget.h"
#include "QtOgreConversions.h"

#include "unittests.h"

QSteelWidget::QSteelWidget(QWidget * parent) :
	QWidget(parent), Ogre::LogListener(), mIsSteelReady(false), mEngine(0), mIsInputGrabbed(false), mTimer(0),
			mLevelName(""), mProjectRootdir("./"), mSelectionTranslated(false), mSelectionRotated(false),
			mTransformationMode(QSteelWidget::TM_TRANSLATION)
{
	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAutoFillBackground(false);
	setMinimumSize(320, 240);
	setFocusPolicy(Qt::StrongFocus);
	setAcceptDrops(true);

	//quick unit tests
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

void QSteelWidget::addResourceLocation(QString path, QString type, QString resGroup)
{
	if (mEngine == NULL)
		quickLog("could not add resource location {path:" + path + ", type:" + type + ", res group:" + resGroup + "}.");
	else
		Ogre::ResourceGroupManager::getSingletonPtr()->addResourceLocation(	convert(path),
																			convert(type),
																			convert(resGroup),
																			false);
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

unsigned long QSteelWidget::createThing(QString meshName, QVector3D pos, QVector4D rot)
{
	quickLog("QSteelWidget::createThing(meshName=" + meshName
	         + " pos="+ QString("(x=%1, y=%2, z=%3)").arg(pos.x()).arg(pos.y()).arg(pos.z())
	         + " rot="+ QString("(x=%1, y=%2, z=%3, w=%4)").arg(rot.x()).arg(rot.y()).arg(rot.z()).arg(rot.w()));
	if (mLevel == NULL)
	{
		quickLog("mLevel == NULL !");
		return 0L;
	}
	Ogre::Quaternion r = mEngine->camera()->camNode()->getOrientation();
	Steel::ThingId id = mLevel->newThing(convert(meshName), convert(pos), convert(rot));
	update();
	quickLog("");
	return (unsigned long) id;
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
	emit onSteelClosing(this);
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

void QSteelWidget::initSteel()
{
	cout << "QSteelWidget::initSteel()" << endl;

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

	mEngine->embeddedInit("plugins.cfg", widgetHandle.toStdString(), width(), height(), "qsteelwidget.log", this);
	Steel::Debug::log("steel widget ready.").endl();
	if (!(mProjectRootdir == "./" && mLevelName == ""))
		setLevel(QString(mProjectRootdir.c_str()), QString(mLevelName.c_str()));
	mIsSteelReady = true;
	emit onSteelReady();
}

void QSteelWidget::keyPressEvent(QKeyEvent *e)
{
	//	cout<<"QSteelWidget::keyPressEvent"<<endl;
	if (mIsInputGrabbed)
	{
		OIS::KeyEvent evt = qtToOisKeyEvent(e);
		mEngine->inputMan()->keyPressed(evt);
		e->accept();
	}
}

void QSteelWidget::keyReleaseEvent(QKeyEvent *e)
{
	cout << "QSteelWidget::keyReleaseEvent" << endl;
	if (mIsInputGrabbed)
	{
		OIS::KeyEvent evt = qtToOisKeyEvent(e);
		mEngine->inputMan()->keyReleased(evt);
	}
	else
	{
		switch (e->key())
		{
			case Qt::Key_R:
				mTransformationMode = QSteelWidget::TM_ROTATION;
				quickLog("QSteelWidget::keyReleaseEvent(): switched to rotation mode.");
				break;
			case Qt::Key_S:
				mTransformationMode = QSteelWidget::TM_SCALE;
				quickLog("QSteelWidget::keyReleaseEvent(): switched to scale mode.");
				break;
			case Qt::Key_T:
				mTransformationMode = QSteelWidget::TM_TRANSLATION;
				quickLog("QSteelWidget::keyReleaseEvent(): switched to translation mode.");
				break;
			case Qt::Key_Delete:
				if (mEngine->hasSelection())
				{
					quickLog("QSteelWidget::keyReleaseEvent(): deleting selection.");
					mEngine->deleteSelection();
					update();
				}
				else
				{
					quickLog("QSteelWidget::keyReleaseEvent(): no selection to delete.");
				}

				break;
			default:
				break;
		}
	}
	e->accept();
}

void QSteelWidget::messageLogged(	const Ogre::String &message,
									Ogre::LogMessageLevel lml,
									bool maskDebug,
									const Ogre::String &logName)
{
	emit onNewLogLine(convert(message));
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

void QSteelWidget::removeResourceLocation(QString path, QString resGroup)
{
	if (mEngine == NULL)
		quickLog("could not remove resource group \'" + resGroup + "\': engine is already deleted.");
	else
		Ogre::ResourceGroupManager::getSingletonPtr()->removeResourceLocation(convert(path), convert(resGroup));
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
	else
	{
		list<Steel::ModelId> selection;
		mEngine->pickThings(selection, e->x(), e->y());
		mEngine->setSelectedThings(selection, true);
		emit
		onThingsSelected(QList<Steel::ModelId>::fromStdList(selection));
		update();
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
	else
	{
		if (mSelectionTranslated)
		{
			std::list<Steel::ThingId> sel = mEngine->selection();
			for (std::list<Steel::ThingId>::iterator it = sel.begin(); it != sel.end(); ++it)
				emit onThingUpdated(*it, "position", convert(mLevel->getThing(*it)->ogreModel()->position()));
			mSelectionTranslated = false;
		}
		if (mSelectionRotated)
		{
			std::list<Steel::ThingId> sel = mEngine->selection();
			for (std::list<Steel::ThingId>::iterator it = sel.begin(); it != sel.end(); ++it)
				emit onThingUpdated(*it, "rotation", convert(mLevel->getThing(*it)->ogreModel()->rotation()));
			mSelectionRotated = false;
		}
	}
	mLastMousePosition = e->pos();
	e->accept();
}

void QSteelWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
	if (mIsInputGrabbed)
		stopEngineMode();// start editor mode
	else
		startEngineMode();// stop editor mode

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
		if (mEngine->hasSelection())
		{
			Ogre::Real _x = float(mLastMousePosition.x());
			Ogre::Real _y = float(mLastMousePosition.y());
			Ogre::Real x = float(e->x());
			Ogre::Real y = float(e->y());
			Ogre::Real w = float(width());
			Ogre::Real h = float(height());
			switch (mTransformationMode)
			{
				case QSteelWidget::TM_TRANSLATION:
					if (e->modifiers() & Qt::ShiftModifier)
					{
						//translation along y
						Ogre::Vector3 selectionPos = mEngine->selectionPosition();
						//I have not found a faster way to do this:
						//first I build a plan with the camera orientation as normal (but vertical).
						Ogre::Vector3 normal = mEngine->camera()->camNode()->getOrientation() * Ogre::Vector3::UNIT_Z;
						normal.y = .0f;
						Ogre::Plane plane = Ogre::Plane(normal, Ogre::Vector3::ZERO);
						//and since I don't know how to compute the distance to feed it, I let it at (0,0,0).
						//ask IT its distance to where I wanted to put it (the selection),
						Ogre::Real dist = plane.getDistance(selectionPos);
						//and build a new one there. suboptimal =/
						plane = Ogre::Plane(normal, dist);
						//						plane.normalise();
						//the idea here is to move the selection on a plane perpendicular to the camera view.
						//we want a vector of the translation from src to dst, where src is where a ray cast from the camera
						//and passing by the last mouse coordinates hits the mentionned plane, and dst is the same with a ray
						//passing through the current mouse coordinates.
						Ogre::Ray ray = mEngine->camera()->cam()->getCameraToViewportRay(_x / w, _y / h);
						std::pair<bool, Ogre::Real> result = ray.intersects(plane);
						if (result.first)
						{
							//							quickLog("1");
							Ogre::Vector3 src = ray.getPoint(result.second);
							//then we do the same with the new coordinates on the viewport
							ray = mEngine->camera()->cam()->getCameraToViewportRay(x / w, y / h);
							result = ray.intersects(plane);
							if (result.first)
							{
								//								quickLog("2");
								Ogre::Vector3 dst = ray.getPoint(result.second);
								//finally, we translate the selection according to the vector given by substracting two points.
								Ogre::Vector3 t = dst - src;
								t.y = t.y > 10.f ? .0f : t.y < -10.f ? 0.f : t.y;
								mEngine->translateSelection(Ogre::Vector3::UNIT_Y * t);
								mSelectionTranslated = true;
								update();
							}
						}

					}
					else
					{
						Ogre::Vector3 selectionPos = mEngine->selectionPosition();
						Ogre::Plane plane = Ogre::Plane(Ogre::Vector3::UNIT_Y, selectionPos.y);
						plane.normalise();
						//what we want is a vector of translation from the selection's position to a new one.
						//first we see where falls a ray that we cast from the cam to the last coordinates on the viewport
						//(the idea is to cast a ray from the camera to a horizontal plane at the base of the selection)
						Ogre::Ray ray = mEngine->camera()->cam()->getCameraToViewportRay(_x / w, _y / h);
						std::pair<bool, Ogre::Real> result = ray.intersects(plane);
						if (result.first)
						{
							Ogre::Vector3 src = ray.getPoint(result.second);
							//then we do the same with the new coordinates on the viewport
							ray = mEngine->camera()->cam()->getCameraToViewportRay(x / w, y / h);
							result = ray.intersects(plane);
							if (result.first)
							{
								Ogre::Vector3 dst = ray.getPoint(result.second);
								//finally, we translate the selection according to the vector given by substracting two points.
								Ogre::Vector3 t = dst - src;
								//just making sure we have an horizontal translation (should be useless since plane is horizontal)
								t.y = 0.f;
								mEngine->translateSelection(t);
								mSelectionTranslated = true;
								update();
							}
						}

					}
					break;
				case QSteelWidget::TM_ROTATION:

					if (e->modifiers() & Qt::ShiftModifier)
					{
						quickLog("rotation with shift modifier is not implemented yet !");
					}
					else
					{
						Ogre::Vector3 r = Ogre::Vector3(.0f, 180.f * (x - _x) / (w / 2.f), .0f);
						mEngine->rotateSelection(r);
						mSelectionRotated = true;
						update();
					}
					break;
				default:
					break;
			}
		}
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

QVector3D QSteelWidget::thingPosition(unsigned long id)
{
	if (mLevel == NULL)
	{
		quickLog("QSteelWidget::thingPosition(): no level loaded.");
		return QVector3D();
	}
	Steel::Thing *t = mLevel->getThing((Steel::ThingId) id);
	if (t == NULL)
	{
		quickLog("QSteelWidget::thingPosition(): no thing for id " + QString::number(id) + ".");
		return QVector3D();
	}
	//TODO: return a Descriptor instead ?
	Steel::OgreModel *model = t->ogreModel();

	if (model == NULL)
	{
		quickLog("QSteelWidget::thingPosition(): no OgreModel for thing" + QString::number(id) + ".");
		return QVector3D();
	}

	return convert(model->position());
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

