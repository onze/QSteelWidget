/*
 * QtOgreWidget.h
 *
 *  Created on: 2011-05-07
 *      Author: onze
 */

#ifndef QSteelWidget_H
#define QSteelWidget_H

#include <QWidget>
#include <OgreLog.h>

#include <Engine.h>

class QSteelWidget: public QWidget,Ogre::LogListener
{
Q_OBJECT
public:
	QSteelWidget(QWidget * parent = 0L);
	virtual ~QSteelWidget();
	/**
	 * First apparition.
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
	void onNewLogLine(QString line);
//	void onNewLogLine();
protected:
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
	Steel::Engine *mEngine;
	bool mIsInputGrabbed;
	QPoint mLastMousePosition;
	QTimer *mTimer;

};
#endif // QtOgreWidget_H
