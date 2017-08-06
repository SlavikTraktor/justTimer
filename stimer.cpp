#include "stimer.h"
#include "ui_stimer.h"
#include <QDebug>

// Constructor
STimer::STimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::STimer),
    intermediate_value(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    mini_timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(endOfTimer()));
    connect(mini_timer, SIGNAL(timeout()), this, SLOT(endOfMiniTimer()));

    QFont mfont("", 150);

    ui->timeEdit->setFont(mfont);

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

    ui->pushButton_2->setEnabled(true);
}

void STimer::endOfTimer()
{
    // End of main timer
    ui->pushButton_2->setEnabled(false);
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
        if (!intermediate_value)
            ui->timeEdit->setTime(QTime::fromMSecsSinceStartOfDay(0));
        mini_timer->stop();
    }
}

void STimer::on_pushButton_3_clicked()
{
    // Quit button
    this->close();
}

void STimer::on_pushButton_2_clicked()
{
    // Stop button
    if (ui->pushButton_2->text() == "Stop")
    {
        ui->pushButton_2->setText("Resume");
        intermediate_value = timer->remainingTime();
        timer->stop();
    }
    else
    {
        ui->pushButton_2->setText("Stop");
        timer->start(intermediate_value);
        intermediate_value = 0;
        mini_timer->start(25);
    }
}
