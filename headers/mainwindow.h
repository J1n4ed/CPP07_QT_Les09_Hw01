#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMovie>

#include "UdpWorker.h"
#include "about.h"

#define TIMER_DELAY 1000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_start_clicked();
    void DisplayData(QByteArray data, QString, uint32_t);
    void on_pb_stop_clicked();
    void on_pb_about_clicked();
    void on_pb_exit_clicked();
    void on_rb_send_time_clicked();
    void on_rb_send_text_clicked();
    void on_pb_send_string_clicked();

signals:

    void signal_sendStringTime();

private:

    Ui::MainWindow * ui;
    QTimer * timer;
    UDPworker * udpWorker;
    About * about;
    QMovie mo_about;
    uint32_t counterPck = 0;
    bool sendTime = true;

    void dataSorter(QNetworkDatagram data);

};
#endif // MAINWINDOW_H
