#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "kviewer.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	KViewer* view = new KViewer(this);
	setCentralWidget(view);
}

MainWindow::~MainWindow()
{
	delete ui;
}

// void MainWindow::paintEvent(QPaintEvent *e)
// {
// 	QPainter p(this);
// 	p.setRenderHint(QPainter::Antialiasing);
// 	int m_persent = 35;//绘制的环的比例
// 	int m_rotateAngle = 360*m_persent/100;
// 	int side = qMin(width(), height());
// 	QRectF outRect(0, 0, side, side);//矩形长宽为窗口的长宽
// 	QRectF inRect(20, 20, side-40, side-40);
// 	QString valueStr = QString("%1%").arg(QString::number(m_persent));
// 
// 	//画外圆
// 	p.setPen(Qt::NoPen);
// 	p.setBrush(QBrush(QColor(97, 117, 118)));
// 	p.drawEllipse(outRect);
// 	//画内圆
// 	p.setBrush(QBrush(QColor(255, 107, 107)));
// 	p.drawPie(outRect, (90-m_rotateAngle)*16, m_rotateAngle*16);
// 	//画遮罩，遮罩颜色为窗口颜色
// 	p.setBrush(palette().window().color());
// 	p.drawEllipse(inRect);
// 	//画文字
// 	QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
// 	p.setFont(f);
// 	p.setFont(f);
// 	p.setPen(QColor("#555555"));
// 	p.drawText(inRect, Qt::AlignCenter, valueStr);
// }
