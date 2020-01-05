#ifndef KTODOLISTMODEL_H
#define KTODOLISTMODEL_H

#include <QAbstractItemModel>
#include <QAbstractItemDelegate>
#include <QStyledItemDelegate>

class RightModelDel : public QStyledItemDelegate
{
public:

	using QStyledItemDelegate::QStyledItemDelegate;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index);

	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index);


	void setEditorData(QWidget* editor, const QModelIndex& index) const override;
	void setModelData(QWidget* editor, QAbstractItemModel* model,
		const QModelIndex& index) const override;

	void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

public slots:
	void commitAndCloseEditor();
};

class KTodoListModel : public QAbstractItemModel
{
public:
	KTodoListModel(QObject* parent);
	~KTodoListModel();

public:
	virtual int rowCount(const QModelIndex& parent) const;
	virtual int columnCount(const QModelIndex& parent) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	virtual QVariant data(const QModelIndex& index, int role) const;
	virtual QModelIndex parent(const QModelIndex& index) const;
	virtual QModelIndex index(int row, int column, const QModelIndex& parent) const;

	//bianji
	Qt::ItemFlags flags(const QModelIndex& index) const;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

private:
	QVector<QStringList> m_todoList;
};

#endif // KTODOLISTMODEL_H
