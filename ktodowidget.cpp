#include "ktodowidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include "kstdafx.h"
#include <QDebug>

#include <QListView>
#include <QTableWidget>
#include <QAbstractItemDelegate>
#include "shell/model/ktodolistmodel.h"
#include <QTextEdit>


KTodoWidget::KTodoWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	QLabel* label = new QLabel("123", this);
//	mainLayout->addWidget(label);

	QTableView* rightView = new QTableView(this);
	KTodoListModel* rightModel = new KTodoListModel(this);
	rightView->setModel(rightModel);

	RightModelDel* del = new RightModelDel(this);
	rightView->setItemDelegate(del);
//	rightView->setModel(rightModel);

	mainLayout->addWidget(rightView);


	setLayout(mainLayout);
}
