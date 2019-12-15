#ifndef KLEFTWIDGET_H
#define KLEFTWIDGET_H

#include <QWidget>

class KLeftWidgetSep : public QWidget
{
	Q_OBJECT
public:
	explicit KLeftWidgetSep(QWidget* parent = nullptr);
	~KLeftWidgetSep();

public:
	QSize sizeHint() const override;

public:
	void paintEvent(QPaintEvent* event) override;
};

class KLeftWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KLeftWidget(QWidget *parent = nullptr);

	QSize minimumSizeHint() const override;

signals:

public slots:
};

#endif // KLEFTWIDGET_H
