#include "kclassitem.h"
#include <QStyleOption>
#include <QStyleOptionButton>
#include <QDebug>
#include <QPainter>
KClassItem::KClassItem(QWidget* parent) : QPushButton(parent)
{
	setFlat(true);
}

KClassItem::~KClassItem()
{

}

bool isPressed(QStyleOptionButton* option)
{
	return option->state & QStyle::State_Sunken;
}
// 
// bool KClassItem::isChecked(QStyleOptionButton* option)
// {
// 	return option->state & QStyle::State_On;
// }
// 
bool isHover(QStyleOptionButton* option)
{
	return option->state & QStyle::State_MouseOver;
}
// 
// bool KClassItem::isAutoRaise(QStyleOptionButton* option)
// {
// 	return option->state & QStyle::State_AutoRaise;
// }
// 
// bool isNormal(QStyleOptionButton* option)
// {
// 	return option->state & QStyle::State_Off;
// }

// 0. normal状态
// 1. hover的状态是独立绘制的
// 2. checked的状态也是独立绘制的
// 3。mousepress的状态要独立绘制下 
void KClassItem::paintEvent(QPaintEvent* e)
{
	QStyleOptionButton option;
	initStyleOption(&option);

	qDebug() << "---------------------" << endl;
//	this->isDown()
	bool bIsChecked = isChecked();
	if (bIsChecked)
	{
		qDebug()<<"is checked"<<endl;
	}
	else
	{
		qDebug() << "is unchecked" << endl;
	}

	bool bIsHover = isHover(&option);
	if (bIsHover)
	{
		qDebug() << "is hover" << endl;
	}
	else
	{
		qDebug() << "is unhover" << endl;
	}

	bool bIsPress = isPressed(&option);
	if (bIsPress)
	{
		qDebug() << "is press" << endl;
	}
	else
	{
		qDebug() << "is unpress" << endl;
	}


	QPainter painter(this);
	painter.fillRect(rect(), Qt::red);
}
