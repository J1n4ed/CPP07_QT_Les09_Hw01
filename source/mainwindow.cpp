#include "../headers/mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    about = new About(this);

    mo_about.setFileName(":/images/cat");
    ui->lb_image->setMovie(&mo_about);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    ui->pb_stop->setEnabled(false);

    connect(udpWorker, &UDPworker::sig_sendDataToGUI, this, &MainWindow::DisplayData);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [&]
    {
        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        if (sendTime)
        {
            QDateTime dateTime = QDateTime::currentDateTime();
            outStr << dateTime;
        }
        else if (!sendTime)
        {
             outStr << ui->le_data->text();
        }

        udpWorker->SendDatagram(dataToSend);
        timer->start(TIMER_DELAY);

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
    ui->pb_start->setEnabled(false);
    ui->pb_stop->setEnabled(true);

    ui->rb_send_text->setEnabled(false);
    ui->rb_send_time->setEnabled(false);

    ui->le_data->setEnabled(false);

    ui->lb_status->setText("СТАТУС: РАБОТАЕТ");

    mo_about.start(); // when CONNECTED
}


void MainWindow::DisplayData(QByteArray data, QString address, uint32_t size)
{
    counterPck++;

    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    QString displayText;


    QDataStream inStr(&data, QIODevice::ReadOnly);


    if (sendTime)
    {
        QDateTime dateTime;
        inStr >> dateTime;
        displayText = "Текущее время: " + dateTime.toString() + ". Принято пакетов " + QString::number(counterPck);
    }
    else if (!sendTime)
    {
        QString rcvText;
        inStr >> rcvText;
        displayText = "Получена строка: " + rcvText + ", адрес: " + address + ", размер сообщения: " + QString::number(size) + ". Принято пакетов " + QString::number(counterPck);
    }

    ui->te_result->append(displayText);
}



void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
    ui->pb_start->setEnabled(true);
    ui->pb_stop->setEnabled(false);

    ui->rb_send_text->setEnabled(true);
    ui->rb_send_time->setEnabled(true);

    if (ui->rb_send_text->isChecked())
    {
        ui->le_data->setEnabled(true);
    }

    ui->lb_status->setText("СТАТУС: ОТСАНОВЛЕНО");

    mo_about.stop();
}

void MainWindow::on_pb_about_clicked()
{
    about->show();
}


void MainWindow::on_pb_exit_clicked()
{
    this->close();
}


void MainWindow::on_rb_send_time_clicked()
{
    sendTime = true;
    ui->le_data->setEnabled(false);
}


void MainWindow::on_rb_send_text_clicked()
{
    sendTime = false;
    ui->le_data->setEnabled(true);
}

