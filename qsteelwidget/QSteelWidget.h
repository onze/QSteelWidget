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
#include <QWidget>
#include <OgreLog.h>

#include <Engine.h>

class QSteelWidget: public QWidget, Ogre::LogListener
{
Q_OBJECT
public:
	QSteelWidget(QWidget * parent = 0L);
	virtual ~QSteelWidget();
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
	 * sets the current level the widget is dealing with.
	 * @param name: name of the level.
	 */
	void setLevel(QString projectRootdir, QString levelName);
	/**
	 * Instanciates a new Thing at the dropping position. All required resources are expected to be ready.
	 */
	unsigned long createThing(QString meshName, QVector3D pos, QVector4D rot);
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
	/**
	 * emitted when steel has been initialised and is ready.
	 */
	void onSteelReady();
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
	/**
	 * emitted when the user clicks on the viewport. The parameter 'selection' is a QList of ids of selected things.
	 */
	void onThingsSelected(QList<unsigned long> selection);

protected:
	inline Ogre::String q2o_string(QString s)
	{
		return Ogre::String(s.toStdString().c_str());
	}
	;
	inline QString o2q_string(Ogre::String s)
	{
		return QString(s.c_str());
	}
	;
	inline void quickLog(std::string s)
	{
		Ogre::LogManager::getSingletonPtr()->logMessage(s);
	}
	;
	inline void quickLog(QString s)
	{
		quickLog(s.toStdString());
	}
	;
	inline void quickLog(const char *s)
	{
		quickLog(QString(s).toStdString());
	}
	;
	OIS::MouseEvent qtToOisMouseEvent(QMouseEvent *e);
	OIS::KeyEvent qtToOisKeyEvent(QKeyEvent *e);
	/**
	 * setup the engine.
	 */
	void initSteel(void);

	/**
	 * input is grabbed and dispatched to the engine.
	 */
	void startEngineMode(void);

	/**
	 * engine is on pause.
	 */
	void stopEngineMode(void);

	/**
	 * grab inputs (game mode)
	 */
	void grabInputs(void);

	/**
	 * release inputs /editor mode
	 */
	void releaseInputs(void);
	bool mIsSteelReady;
	Steel::Engine *mEngine;
	bool mIsInputGrabbed;
	QPoint mLastMousePosition;
	QTimer *mTimer;
	Steel::Level *mLevel;
	Ogre::String mLevelName, mProjectRootdir;

};
#endif // QtOgreWidget_H
