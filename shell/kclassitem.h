#ifndef KCLASSITEM_H
#define KCLASSITEM_H

#include <QPushButton>

class KClassItem : public QPushButton
{
public:
	KClassItem(QWidget* parent = nullptr);
	~KClassItem();

// public:
// 	bool isPressed(QStyleOptionButton* option);
// 	bool isChecked(QStyleOptionButton* option);
// 	bool isHover(QStyleOptionButton* option);
// 	bool isAutoRaise(QStyleOptionButton* option);
public:
	virtual void paintEvent(QPaintEvent*) override;
};

#endif // KCLASSITEM_H
