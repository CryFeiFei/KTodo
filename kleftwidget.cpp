#include "kleftwidget.h"

#include <QButtonGroup>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>

#include "shell/kclassitem.h"
#include "kstdafx.h"

KLeftWidget::KLeftWidget(QWidget *parent) : QWidget(parent)
{
	QScrollArea* scrollArea = new QScrollArea(this);
	scrollArea->setFrameShape(QFrame::NoFrame); //这个去除掉滚动条的边框，要不然每次内边都有个1px的空白

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	//------------------]
	QWidget* innerWidget = new QWidget(this);

	KClassItem* button1 = new KClassItem(this);
	button1->setText("1");
	button1->setCheckable(true);

	KClassItem* button2 = new KClassItem(this);
	button2->setText("2");
	button2->setCheckable(true);

	KClassItem* button3 = new KClassItem(this);
	button3->setText("2");
	button3->setCheckable(true);

	KClassItem* button4 = new KClassItem(this);
	button4->setText("2");
	button4->setCheckable(true);

	KClassItem* button5 = new KClassItem(this);
	button5->setText("2");
	button5->setCheckable(true);

	//just 互斥
	QButtonGroup* btnGroup = new QButtonGroup(this);
	btnGroup->setExclusive(true);
	btnGroup->addButton(button1);
	btnGroup->addButton(button2);

	QVBoxLayout* itemsLayout = new QVBoxLayout(this);
	itemsLayout->setContentsMargins(0, 0, 0, 0);
	itemsLayout->addWidget(button1);
	itemsLayout->addWidget(button2);
	itemsLayout->addWidget(button3);
	itemsLayout->addWidget(button4);
	itemsLayout->addWidget(button5);
	itemsLayout->addStretch();

	innerWidget->setLayout(itemsLayout);
	scrollArea->setWidget(innerWidget);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setWidgetResizable(true);
	//-----------------
	mainLayout->addWidget(scrollArea);
	setLayout(mainLayout);
	setMaximumWidth(LEFT_MAXWIDTH);
}

QSize KLeftWidget::minimumSizeHint() const
{
	return QSize(LEFT_MINIWIDTH, LEFT_MINIHEIGHT);
}

