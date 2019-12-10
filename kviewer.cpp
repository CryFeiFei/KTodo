#include "kviewer.h"
#include <QSplitter>
#include <QVBoxLayout>

#include "ktodowidget.h"

KViewer::KViewer(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	m_splitter = new QSplitter(Qt::Horizontal, this);

	QWidget* w1 = new QWidget(this);
	w1->setStyleSheet("background-color: yellow");

	KTodoWidget* todoWidget = new KTodoWidget(this);
//	todoWidget->setStyleSheet("background-color: red");

	m_splitter->addWidget(w1);
	m_splitter->addWidget(todoWidget);

	m_splitter->setHandleWidth(1);
	m_splitter->setStretchFactor(1, 1);

	mainLayout->addWidget(m_splitter);
	setLayout(mainLayout);
}
