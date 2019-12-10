#include "kviewer.h"
#include <QSplitter>
#include <QVBoxLayout>

KViewer::KViewer(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	m_splitter = new QSplitter(Qt::Horizontal, this);
	m_splitter->setHandleWidth(1);

	QWidget* w1 = new QWidget(this);
	w1->setStyleSheet("background-color: yellow");

	QWidget* w2 = new QWidget(this);
	w2->setStyleSheet("background-color: red");

	m_splitter->addWidget(w1);
	m_splitter->addWidget(w2);

	mainLayout->addWidget(m_splitter);
	setLayout(mainLayout);
}
