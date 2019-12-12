#ifndef KLEFTWIDGET_H
#define KLEFTWIDGET_H

#include <QWidget>

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
