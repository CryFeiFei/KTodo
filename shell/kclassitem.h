#ifndef KCLASSITEM_H
#define KCLASSITEM_H

#include <QPushButton>

class KClassItem : public QPushButton
{
public:
	KClassItem(QWidget* parent = nullptr);
	~KClassItem();

public:
	QSize sizeHint() const override;
	virtual void paintEvent(QPaintEvent*) override;
};

#endif // KCLASSITEM_H
