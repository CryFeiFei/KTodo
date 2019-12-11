#include "kleftwidget.h"

#include <QButtonGroup>
#include <QVBoxLayout>

#include <QPushButton>

#include "shell/kclassitem.h"

KLeftWidget::KLeftWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	QButtonGroup* btnGroup = new QButtonGroup(this);
	btnGroup->setExclusive(true);

	KClassItem* button1 = new KClassItem(this);
//	button1->setText("1");
	button1->setCheckable(true);

	QPushButton* button2 = new QPushButton(this);
	button2->setText("2");
	button2->setCheckable(true);

	btnGroup->addButton(button1);
	btnGroup->addButton(button2);

	mainLayout->addWidget(button1);
	mainLayout->addWidget(button2);

	setLayout(mainLayout);
}
