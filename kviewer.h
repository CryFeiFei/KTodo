#ifndef KVIEWER_H
#define KVIEWER_H

#include <QWidget>
#include <QSplitter>


class KViewer : public QWidget
{
	Q_OBJECT
public:
	explicit KViewer(QWidget *parent = nullptr);

signals:

public slots:


private:
	QSplitter* m_splitter;
};

#endif // KVIEWER_H
