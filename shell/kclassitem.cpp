#include "kclassitem.h"
#include <QStyleOption>
#include <QStyleOptionButton>
#include <QDebug>
#include <QPainter>
#include "../kstdafx.h"

KClassItem::KClassItem(QWidget* parent) : QPushButton(parent)
{
	setFlat(true);
}

KClassItem::~KClassItem()
{

}

QSize KClassItem::sizeHint() const
{
	return QSize(size().width(), LEFT_ITEM_HEIGHT);
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

// 0. normal״̬
// 1. hover��״̬�Ƕ������Ƶ�
// 2. checked��״̬Ҳ�Ƕ������Ƶ�
// 3��mousepress��״̬Ҫ���������� 

//--------------------����
//1��hover����һ���ɫ
//2. select����ɫ ��������ɫ
//3. ������� ѡ�и�������ɫ
void KClassItem::paintEvent(QPaintEvent* e)
{
	QPainter painter(this);


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

	QColor colorBK = Qt::gray;
	if (isChecked())
	{ 
		painter.fillRect(rect(), colorBK);
	}

	if (isHover(&option))
	{
		colorBK = Qt::red;
		painter.fillRect(rect(), colorBK);
	}

	QRect rectAll = rect();

	// ����ͼ��
	QPixmap pixMap = style()->standardPixmap(QStyle::SP_FileIcon);
	QRect rectIcon(0, 0, KStyle::dpiScaled(48), rectAll.height());
	painter.drawPixmap(rectIcon, pixMap);


	int nTextWidth = rect().width() - KStyle::dpiScaled(48);
	QString strText = "test";
	QRect rectText(KStyle::dpiScaled(48), 0, nTextWidth, KStyle::dpiScaled(48));
	QFont fontText;
	fontText.setPixelSize(20);
	painter.setFont(fontText);
	painter.drawText(rectText, strText, QTextOption(Qt::AlignCenter));
	

// 	QColor colorBackGroud = Qt::red;
// 	if (bIsHover)
// 		colorBackGroud = Qt::blue;
// 
// 	painter.fillRect(rect(), colorBackGroud);
}
