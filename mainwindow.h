#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class NetworkPinger;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void pingHappened(bool isGood);
signals:
    void requestPause(bool pause);
private:
    int _bad=0;
    int _good=0;
    Ui::MainWindow *ui;
    NetworkPinger* _pinger=nullptr;
    int _dcInARow=0;
};

#endif // MAINWINDOW_H
