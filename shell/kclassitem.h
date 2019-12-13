#ifndef KCLASSITEM_H
#define KCLASSITEM_H

#include <QPushButton>
#include <QIcon>
#include <QString>

class KClassItem : public QPushButton
{
public:
	KClassItem(QWidget* parent = nullptr);
	~KClassItem();

public:
	QSize sizeHint() const override;
	virtual void paintEvent(QPaintEvent*) override;

private:
	QString m_text;
	QPixmap m_pixmap;
};

#endif // KCLASSITEM_H
