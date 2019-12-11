#include "ktodowidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include "kstdafx.h"
#include <QDebug>

KTodoWidget::KTodoWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	QLabel* label = new QLabel("123", this);
	mainLayout->addWidget(label);

	double dd = dpiScaled(1);
	qDebug() << "--------------" << dd << endl;

	setStyleSheet("background-color: blue");

	setLayout(mainLayout);
}
