/*
 * QSteelWidget.cpp
 *
 *  Created on: 2011-05-07
 *      Author: onze
 */

#include <QtGui>
#include "QSteelWidget.h"

QSteelWidget::QSteelWidget(QWidget * parent) :
	QWidget(parent)
{
	QHBoxLayout * layout = new QHBoxLayout;
	setLayout(layout);

	QPlainTextEdit *editor = new QPlainTextEdit;
	layout->addWidget(editor);

}

QSteelWidget::~QSteelWidget()
{
}
