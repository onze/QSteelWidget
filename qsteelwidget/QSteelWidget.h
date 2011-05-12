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
	virtual void wheelEvent(QWheelEvent *e);
	/**
	 * setup the engine.
	 */
	void initSteel();

protected:
	Steel::Engine *mEngine;
	float mCameraRotationDelta;
	QPoint mLastMousePos;

};
#endif // QtOgreWidget_H
