/*
 * QtOgreWidget.h
 *
 *  Created on: 2011-05-07
 *      Author: onze
 */

#ifndef QSteelWidget_H
#define QSteelWidget_H

#include <QWidget>

#include <Engine.h>

class QSteelWidget: public QWidget
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

protected:

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
	bool isInputGrabbed;
	QPoint mLastMousePosition;
	QTimer *timer;
	std::list<int> mKeysPressed;

};
#endif // QtOgreWidget_H
