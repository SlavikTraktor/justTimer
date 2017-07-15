#ifndef STIMER_H
#define STIMER_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class STimer;
}

class STimer : public QMainWindow
{
    Q_OBJECT

public:
    explicit STimer(QWidget *parent = 0);
    ~STimer();
    QTimer *timer;

private slots:
    void on_pushButton_clicked();
    void endOfTimer();

private:

    Ui::STimer *ui;
};

#endif // STIMER_H
