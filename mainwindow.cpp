#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networkpinger.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _pinger=new NetworkPinger();
    connect(_pinger,&NetworkPinger::connectionHit,
            this,&MainWindow::pingHappened);
    connect(this,&MainWindow::requestPause,
            _pinger,&NetworkPinger::pause);

    _pinger->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pingHappened(bool isGood)
{
    if (isGood)
    {
        _dcInARow=0;
        ui->numConn->setText(QString::number(++_good));

    }
    else
    {
        _dcInARow++;
        ui->numDc->setText(QString::number(++_bad));
    }
    ui->dcStreak->setText(QString::number(_dcInARow));
    if (_dcInARow>5)
    {
        _dcInARow=0;
        _pinger->blockSignals(true);
        emit requestPause(true);
        ui->dcStreak->setText("Restarting network...");
        system("networksetup -setairportpower \"Wi-Fi\" off");
        system("networksetup -setairportpower \"Wi-Fi\" on");
        QThread::sleep(5);
        ui->dcStreak->setText("Done");
        _pinger->blockSignals(false);
        emit requestPause(false);
    }
}
