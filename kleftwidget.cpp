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

	//------------------

	KClassItem* button1 = new KClassItem(this);
//	button1->setText("1");
	button1->setCheckable(true);

	QPushButton* button2 = new QPushButton(this);
	button2->setText("2");
	button2->setCheckable(true);

	//just 互斥
	QButtonGroup* btnGroup = new QButtonGroup(this);
	btnGroup->setExclusive(true);
	btnGroup->addButton(button1);
	btnGroup->addButton(button2);

	QVBoxLayout* itemsLayout = new QVBoxLayout(this);
	itemsLayout->setContentsMargins(0, 0, 0, 0);
	itemsLayout->addWidget(button1);
	itemsLayout->addWidget(button2);

	scrollArea->setLayout(itemsLayout);

	//-----------------
	mainLayout->addWidget(scrollArea);
	setLayout(mainLayout);
	setMaximumWidth(LEFT_MAXWIDTH);
}

QSize KLeftWidget::minimumSizeHint() const
{
	return QSize(LEFT_MINIWIDTH, size().height());
}

