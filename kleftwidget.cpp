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
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	//------------------

	KClassItem* button1 = new KClassItem(this);
//	button1->setText("1");
	button1->setCheckable(true);

	QPushButton* button2 = new QPushButton(this);
	button2->setText("2");
	button2->setCheckable(true);

	//just »¥³â
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

