#include "ktodowidget.h"
#include <QVBoxLayout>
#include <QLabel>

KTodoWidget::KTodoWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	QLabel* label = new QLabel("123", this);
	mainLayout->addWidget(label);


	setStyleSheet("background-color: blue");

	setLayout(mainLayout);
}
