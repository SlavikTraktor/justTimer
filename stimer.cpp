#include "stimer.h"
#include "ui_stimer.h"
#include <QDebug>

// Constructor
STimer::STimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::STimer)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    mini_timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(endOfTimer()));
    connect(mini_timer, SIGNAL(timeout()), this, SLOT(endOfMiniTimer()));

    setWindowState(Qt::WindowFullScreen);
}

// Destructor
STimer::~STimer()
{
    delete ui;
}

//Slots ********************************************************************

void STimer::on_pushButton_clicked()
{
    // Start timer button
    QTime g = QTime::fromString(ui->lineEdit->text(), "hh:mm:ss");
    ui->timeEdit->setTime(g);
    timer->start(g.msecsSinceStartOfDay());
    mini_timer->start(25);
}

void STimer::endOfTimer()
{
    // End of main timer
    timer->stop();
}

void STimer::endOfMiniTimer()
{
    // End of mini-timer
    if (timer->isActive())
    {
        ui->timeEdit->setTime(QTime::fromMSecsSinceStartOfDay(timer->remainingTime()));
    }
    else
    {
        ui->timeEdit->setTime(QTime::fromMSecsSinceStartOfDay(0));
        mini_timer->stop();
    }
}

void STimer::on_pushButton_3_clicked()
{
    // Quit button
    this->close();
}
