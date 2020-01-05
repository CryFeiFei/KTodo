#include "kleftwidget.h"

#include <QButtonGroup>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QPainter>

#include "shell/kclassitem.h"
#include "kstdafx.h"

KLeftWidgetSep::KLeftWidgetSep(QWidget* parent /* = nullptr */) : QWidget(parent)
{
	setMinimumHeight(KStyle::dpiScaled(LEFT_ITEM_HEIGHT) / 2);
}

KLeftWidgetSep::~KLeftWidgetSep()
{

}

QSize KLeftWidgetSep::sizeHint() const
{
	return QSize(rect().width(), KStyle::dpiScaled(LEFT_ITEM_HEIGHT) / 2);
}

void KLeftWidgetSep::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::green);
	QPen pen;
	pen.setColor(Qt::red);

	painter.setPen(pen);

	painter.drawLine(0, KStyle::dpiScaled(LEFT_ITEM_HEIGHT) / 4, sizeHint().width(), KStyle::dpiScaled(LEFT_ITEM_HEIGHT) / 4);
}

//-------------------------------

KLeftWidget::KLeftWidget(QWidget *parent) : QWidget(parent)
{
	QScrollArea* scrollArea = new QScrollArea(this);
	scrollArea->setFrameShape(QFrame::NoFrame); //这个去除掉滚动条的边框，要不然每次内边都有个1px的空白

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	//---------------------
	QWidget* innerWidget = new QWidget(this);

	KClassItem* button1 = new KClassItem(this);
	button1->setText("1");
	button1->setCheckable(true);

	KClassItem* button2 = new KClassItem(this);
	button2->setText("2");
	button2->setCheckable(true);

	KClassItem* button3 = new KClassItem(this);
	button3->setText("3");
	button3->setCheckable(true);

	KClassItem* button4 = new KClassItem(this);
	button4->setText("4");
	button4->setCheckable(true);

	KClassItem* button5 = new KClassItem(this);
	button5->setText("5");
	button5->setCheckable(true);

	KClassItem* button6 = new KClassItem(this);
	button6->setText("5");
	button6->setCheckable(true);

	KClassItem* button7 = new KClassItem(this);
	button7->setText("5");
	button7->setCheckable(true);

	KClassItem* button8 = new KClassItem(this);
	button8->setText("5");
	button8->setCheckable(true);

	KLeftWidgetSep* sep = new KLeftWidgetSep(this);

	//just 互斥
	QButtonGroup* btnGroup = new QButtonGroup(this);
	btnGroup->setExclusive(true);
	btnGroup->addButton(button1);
	btnGroup->addButton(button2);
	btnGroup->addButton(button3);
	btnGroup->addButton(button4);
	btnGroup->addButton(button5);
	btnGroup->addButton(button6);
	btnGroup->addButton(button7);
	btnGroup->addButton(button8);

	QVBoxLayout* itemsLayout = new QVBoxLayout(this);
	itemsLayout->setContentsMargins(0, 0, 0, 0);
	itemsLayout->addWidget(button1);
	itemsLayout->addWidget(button2);
	itemsLayout->addWidget(button3);
	itemsLayout->addWidget(button4);
	itemsLayout->addWidget(button5);
	itemsLayout->addWidget(sep);
	itemsLayout->addWidget(button6);
	itemsLayout->addWidget(button7);
	itemsLayout->addWidget(button8);
	itemsLayout->addStretch();

	innerWidget->setLayout(itemsLayout);

	scrollArea->setWidget(innerWidget);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea->setWidgetResizable(true);
	scrollArea->setFrameShape(QFrame::NoFrame);
	//-----------------
	mainLayout->addWidget(scrollArea);
	setLayout(mainLayout);
	setMaximumWidth(KStyle::dpiScaled(LEFT_MAXWIDTH));
}

QSize KLeftWidget::minimumSizeHint() const
{
	return QSize(KStyle::dpiScaled(LEFT_MINIWIDTH), KStyle::dpiScaled(LEFT_MINIHEIGHT));
}

