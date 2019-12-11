#include "kviewer.h"
#include <QSplitter>
#include <QVBoxLayout>

#include "kleftwidget.h"
#include "ktodowidget.h"

KViewer::KViewer(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	m_splitter = new QSplitter(Qt::Horizontal, this);

	KLeftWidget* leftWidget = new KLeftWidget(this);
	leftWidget->setStyleSheet("background-color: yellow");

	KTodoWidget* todoWidget = new KTodoWidget(this);
//	todoWidget->setStyleSheet("background-color: red");

	m_splitter->addWidget(leftWidget);
	m_splitter->addWidget(todoWidget);

	m_splitter->setHandleWidth(0);
	m_splitter->setStretchFactor(1, 1);

	mainLayout->addWidget(m_splitter);
	setLayout(mainLayout);
}
