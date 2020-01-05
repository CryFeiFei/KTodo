#include "ktodolistmodel.h"
#include <QFileIconProvider>

#include <QTextEdit>
#include <QLineEdit>
#include <QDebug>

void RightModelDel::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	if (index.column() == 1)
	{

	}
	return QStyledItemDelegate::paint(painter, option, index);
}

void RightModelDel::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	if (!editor)
		return;

	if (index.column() == 1)
	{
		QString str = index.model()->data(index, Qt::DisplayRole).toString();
		QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
		//	qDebug()<<lineEdit->placeholderText()<<endl;
		lineEdit->insert(str);
		lineEdit->setPlaceholderText(str);
	}
}

void RightModelDel::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	if (index.column() == 1)
	{
		QLineEdit* textEdit = static_cast<QLineEdit*>(editor);
		QString strText = textEdit->text();
		model->setData(index, strText, Qt::EditRole);
	}
}

void RightModelDel::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	editor->setGeometry(option.rect);
}

QWidget* RightModelDel::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	if (index.column() == 1)
	{
		QLineEdit* textEdit = new QLineEdit(parent);
		return textEdit;
	}
	else
	{
		return createEditor(parent, option, index);
	}
}

void RightModelDel::commitAndCloseEditor()
{

}

// 单击可编辑
// void YourView::mousePressEvent(QMouseEvent* event)
// {
// 	if (event->button() == Qt::LeftButton) {
// 		QModelIndex index = indexAt(event->pos());
// 		if (index.column() == 0) { // column you want to use for one click
// 			edit(index);
// 		}
// 	}
// 	QTreeView::mousePressEvent(event);
// }

//-------------------------------------------


KTodoListModel::KTodoListModel(QObject* parent) : QAbstractItemModel(parent)
{
	QStringList listTest;
	listTest = QStringList() << QString::fromLatin1("test1")
		<< QString::fromLatin1("test2")<<QString::fromLatin1("test3") << QString::fromLatin1("test4");

	QStringList listTest2;
	listTest2 = QStringList() << QString::fromLatin1("test2")
		<< QString::fromLatin1("test2") << QString::fromLatin1("test3") << QString::fromLatin1("test4");

	QStringList listTest3;
	listTest3 = QStringList() << QString::fromLatin1("test3")
		<< QString::fromLatin1("test2") << QString::fromLatin1("test3") << QString::fromLatin1("test4");

	QStringList listTest4;
	listTest4 = QStringList() << QString::fromLatin1("test4")
		<< QString::fromLatin1("test2") << QString::fromLatin1("test3") << QString::fromLatin1("test4");

	QStringList listTest5;
	listTest5 = QStringList() << QString::fromLatin1("test5")
		<< QString::fromLatin1("test2") << QString::fromLatin1("test3") << QString::fromLatin1("test4");


	m_todoList.push_back(listTest);
	m_todoList.push_back(listTest2);
	m_todoList.push_back(listTest3);
	m_todoList.push_back(listTest4);
	m_todoList.push_back(listTest5);
}

KTodoListModel::~KTodoListModel()
{

}

int KTodoListModel::rowCount(const QModelIndex& parent) const
{
	if (!m_todoList.isEmpty())
	{
		return m_todoList.size();
	}

	return 0;
}

int KTodoListModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant KTodoListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal)
	{
		if (role != Qt::DisplayRole)
			return QVariant();

		switch (section)
		{
		case 0:
			return QVariant(QObject::tr("Name"));
		case 1:
			return QVariant(QObject::tr("Size"));
		case 2:
			return QVariant(QObject::tr("Type"));
		case 3:
			return QVariant(QObject::tr("ModifiedData"));
		}
	}
	return QVariant("");
}

QVariant KTodoListModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid() || index.model() != this)
		return QVariant();
// 	KFileItemNode* itemNode = _nodeFromIndex(index);
// 	QFileInfo fileInfo(itemNode->m_fileName);
	int nIndex = index.row();

	//第一列文字
	if (role == Qt::DisplayRole && index.column() == 0)
	{
		return QVariant(m_todoList.at(nIndex).at(0));
	}

	//第一列图标
	if (role == Qt::DecorationRole && index.column() == 0)
	{
		QFileIconProvider fileIconProvider;
		QIcon ico = fileIconProvider.icon(QFileIconProvider::File);
		return ico;
	}

	//第二列大小
	if (index.column() == 1 && role == Qt::DisplayRole)
	{
// 		if (fileInfo.isDir())
// 			return QVariant();
// 
// 		if (!fileInfo.isDir()/* && fileInfo.fileName() != QObject::tr("Size")*/)
// 		{
// 			qint64 nSize = fileInfo.size();
// 			return QVariant(nSize);
// 		}
		return QVariant(m_todoList.at(nIndex).at(1));
	}

	//第三列类型 类型
	if (index.column() == 2 && role == Qt::DisplayRole)
	{
//		if (fileInfo.isDir())
			return QVariant(m_todoList.at(nIndex).at(2));
//		else
//			return QVariant(fileInfo.suffix());
	}

	// 第四列 修改时间
	if (index.column() == 3 && role == Qt::DisplayRole)
	{
//		QString modifiedData = fileInfo.lastModified().toString(Qt::SystemLocaleDate);
		return QVariant(m_todoList.at(nIndex).at(3));
	}

	return QVariant();
}

QModelIndex KTodoListModel::parent(const QModelIndex& index) const
{
	return QModelIndex();
}

QModelIndex KTodoListModel::index(int row, int column, const QModelIndex& parent) const
{
	if (!parent.isValid() && column < 4)
	{
// 		KFileItemNode* childNode = m_rootNode->m_children.value(row);
// 		if (!childNode)
// 			return QModelIndex();
		QString str = m_todoList.at(row).at(column);
		return createIndex(row, column, &str);
	}
	return QModelIndex();
}

bool KTodoListModel::setData(const QModelIndex& index, const QVariant& value, int role/* = Qt::EditRole*/)
{
	if (!value.isValid())
		return false;

	if (index.column() == 1 && role == Qt::EditRole)
	{
		QString strText = value.toString();
		QStringList listTest = m_todoList.at(index.row());

		qDebug() << listTest << endl;
			
		listTest.replace(index.column(), strText);

		m_todoList[index.row()] = listTest;

		qDebug() << listTest << endl;
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

Qt::ItemFlags KTodoListModel::flags(const QModelIndex& index) const
{
	Qt::ItemFlags flags = QAbstractItemModel::flags(index);
//	if (index.row() != index.column()) 
//	{
		flags |= Qt::ItemIsEditable;
//	}
	return flags;
}
