#include "stimer.h"
#include "ui_stimer.h"
#include <QDebug>

STimer::STimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::STimer)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(endOfTimer()));
}

STimer::~STimer()
{
    delete ui;
}

void STimer::on_pushButton_clicked()
{
    QTime g = QTime::fromString(ui->lineEdit->text(), "hh:mm:ss");
    qDebug() << ui->lineEdit->text() << "\n" << g.msecsSinceStartOfDay();
    ui->timeEdit->setTime(g);
    timer->start(g.msecsSinceStartOfDay());

}

void STimer::endOfTimer()
{
    ui->timeEdit->setTime(QTime::fromString("00:00:00", "hh:mm:ss"));
}
