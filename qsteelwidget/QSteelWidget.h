/*
 * QtOgreWidget.h
 *
 *  Created on: 2011-05-07
 *      Author: onze
 */

#ifndef QSteelWidget_H
#define QSteelWidget_H

#include <QList>
#include <QVector3D>
#include <QVector4D>
#include <QWidget>
#include <OgreLog.h>

#include <Engine.h>

class QSteelWidget: public QWidget, Ogre::LogListener
{
Q_OBJECT
public:
	QSteelWidget(QWidget * parent = 0L);
	virtual ~QSteelWidget();
	/**
	 * allows loading from the given folder (path).
	 * type should probably be FileSystem.
	 */
	void addResourceLocation(QString path, QString type, QString resGroup);
	///Instanciates a new Thing at the dropping position. All required resources are expected to be ready.
	unsigned long createThing(QString meshName, QVector3D pos, QVector4D rot,bool involvesNewResources=false);
	inline bool isSteelReady()
	{
		return mIsSteelReady;
	}
	;
	/**
	 * Called at first apparition in a qt app.
	 * @param e
	 */
	virtual void showEvent(QShowEvent *e);
	/**
	 * refresh.
	 * @param e
	 */
	virtual void paintEvent(QPaintEvent *e);
	virtual QPaintEngine *paintEngine() const;
	virtual void resizeEvent(QResizeEvent *e);
	virtual void dragEnterEvent(QDragEnterEvent *e);
	virtual void dragMoveEvent(QDragMoveEvent *e);
	virtual void dropEvent(QDropEvent *e);
	virtual void messageLogged(	const Ogre::String &message,
								Ogre::LogMessageLevel lml,
								bool maskDebug,
								const Ogre::String &logName);
	void closeEvent(QCloseEvent *e);
	/**
	 * removes the location from the resource group from ogre resourceManager.
	 * @param path
	 * @param resGroup
	 */
	void removeResourceLocation(QString path, QString resGroup);
	/**
	 * sets the current level the widget is dealing with.
	 * @param name: name of the level.
	 */
	void setLevel(QString projectRootdir, QString levelName);
	QVector3D dropTargetPosition(QVector3D delta);
	QVector4D dropTargetRotation();
	QVector3D thingPosition(unsigned long id);

	QVector3D cameraPosition();
	void cameraPosition(QVector3D pos);
	QVector4D cameraRotation();
	void cameraRotation(QVector4D rot);

public slots:
	virtual void moveEvent(QMoveEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *e);
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseReleaseEvent(QMouseEvent *e);
	virtual void keyPressEvent(QKeyEvent *e);
	virtual void keyReleaseEvent(QKeyEvent *e);
	virtual void mouseDoubleClickEvent(QMouseEvent *e);
	virtual void wheelEvent(QWheelEvent *e);

	/**
	 * engine mode only.
	 * this is called at regular interval to update the engine.
	 */
	void engineModeUpdate(void);

signals:
	///emitted when steel has been initialised and is ready.
	void onSteelReady();
	///emitted when steel is about to be closed.
	void onSteelClosing(QSteelWidget *);
	/**
	 * emitted when ogre logs area written.
	 * @param line: the line of log.
	 */
	void onNewLogLine(QString line);
	/**
	 * emitted in response to a dropEvent, if it contains an url.
	 * @param url: the url dropped in the widget.
	 */
	void onItemDropped(QString url);
	///emitted when a Thin has been deleted
	void onThingsDeleted(QList<unsigned long> ids);
	///emitted when the user clicks on the viewport. The parameter 'selection' is a QList of ids of selected things.
	void onThingsSelected(QList<unsigned long> selection);
	/**
	 * emitted when a Thing's instance hgas a property changed because of editing (position, rotation, etc)
	 * @param id
	 * @param property
	 * @param value
	 */
	void onThingUpdated(unsigned long id, QString property, QVector3D value);
	void onThingUpdated(unsigned long id, QString property, QVector4D value);

protected:
	inline void quickLog(std::string s)
	{
		Ogre::LogManager::getSingletonPtr()->logMessage(s);
	}
	inline void quickLog(QString s)
	{
		quickLog(s.toStdString());
	}
	inline void quickLog(const char *s)
	{
		quickLog(QString(s).toStdString());
	}
	inline void quickLog(Ogre::Vector3 v)
	{
		quickLog(Ogre::StringConverter::toString(v));
	}
	OIS::MouseEvent qtToOisMouseEvent(QMouseEvent *e);
	OIS::KeyEvent qtToOisKeyEvent(QKeyEvent *e);
	///setup the engine.
	void initSteel(void);
	///input is grabbed and dispatched to the engine.
	void startEngineMode(void);
	///engine is on pause.
	void stopEngineMode(void);
	///grab inputs (game mode)
	void grabInputs(void);
	///release inputs /editor mode
	void releaseInputs(void);
	bool mIsSteelReady;
	Steel::Engine *mEngine;
	bool mIsInputGrabbed;
	QPoint mLastMousePosition;
	QTimer *mTimer;
	Steel::Level *mLevel;
	Ogre::String mLevelName, mProjectRootdir;
	/**
	 * switched to true during a mouseMove, to indicate that the selection has been translated and need an update
	 * in weld internals.
	 */
	bool mSelectionTranslated;
	///Same as mSelectionTranslated, but with rotation.
	bool mSelectionRotated;
	enum TransformationMode
	{
		TM_TRANSLATION, TM_ROTATION, TM_SCALE
	};
	///one of the TransformationMode enum values.
	TransformationMode mTransformationMode;
	///true during a selection translation/rotation/scaling.
	bool mIsTransformingSelection;
	///switched to true during transformation of a selection, when the right mouse button is pressed.
	bool mIsSelectionTransformingAborted;
	///selection goes back to there when a translation is aborted.
	Ogre::Vector3 mSelectionPosBeforeTransformation;

};
#endif // QtOgreWidget_H
