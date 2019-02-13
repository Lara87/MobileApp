#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRegExp"
#include "QDebug"
#include "numberphone.h"
#include "modelphone.h"
#include "service.h"
#include "tariff.h"
#include "payment.h"
#include <QStyle>
#include <QIcon>
#include <QApplication>
#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{  
    ui->setupUi(this);


                                   /*стилизация для кнопок*/


    ui->pushButtonClient->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                        "border-radius: 15px;border-color: beige;"
                                        "font: bold 14px; min-width: 15em;"
                                        "min-height: 2em;padding: 6px;");

    ui->pushButtonTariff->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                        "border-radius: 15px;border-color: beige;"
                                        "font: bold 14px; min-width: 15em;"
                                        "min-height: 2em;padding: 6px;");

    ui->pushButtonPayment->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                         "border-radius: 15px;border-color: beige;"
                                         "font: bold 14px; min-width: 15em;"
                                         "min-height: 2em;padding: 6px;");

    ui->pushButtonService->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                         "border-radius: 15px;border-color: beige;"
                                         "font: bold 14px; min-width: 15em;"
                                         "min-height: 2em;padding: 6px;");

    ui->pushButtonModelPhone->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px; min-width: 15em;"
                                            "min-height: 2em;padding: 6px;");

    ui->pushButtonNumberPhone->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                             "border-radius: 15px;border-color: beige;"
                                             "font: bold 14px; min-width: 15em;"
                                             "min-height: 2em;padding: 6px;");


    this->setStyleSheet("background-color:#f2f3f4");

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

    /*титульный лист*/
    titleA = new TitleApp();//выделили память под новый объект
    connect(titleA, &TitleApp::openMainWindow, this, &MainWindow::show);//подключили сигнал
    //кто,        что            -       этот объект - метод
    titleA->show();

    /*номер телефона*/
    numPhone = new NumberPhone();//выделили память под новый объект
    connect(numPhone, &NumberPhone::openMainWindow, this, &MainWindow::show);

    /*модель телефона*/
    modPhone = new ModelPhone();//выделили память под новый объект
    connect(modPhone, &ModelPhone::openMainWindow, this, &MainWindow::show);//подключили сигнал
            //кто,        что            -       этот объект - метод

    /*данные о клиенте*/
    clPhone = new Client();//выделили память под новый объект
    connect(clPhone, &Client::openMainWindow, this, &MainWindow::show);//подключили сигнал
    //кто,        что            -       этот объект - метод

    /*платеж*/
    payPhone = new Payment();//выделили память под новый объект
    connect(payPhone, &Payment::openMainWindow, this, &MainWindow::show);//подключили сигнал
    //кто,        что            -       этот объект - метод

    /*услуга*/
    servPhone = new Service();//выделили память под новый объект
    connect(servPhone, &Service::openMainWindow, this, &MainWindow::show);//подключили сигнал
    //кто,        что            -       этот объект - метод

    /*тариф*/
    tPhone = new Tariff();//выделили память под новый объект
    connect(tPhone, &Tariff::openMainWindow, this, &MainWindow::show);//подключили сигнал
    //кто,        что            -       этот объект - метод


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonNumberPhone_clicked()//кнопка для перехода в раздел номер телефона
{
    numPhone->show();//открытие окна - показ
    this->close();//закрыли объект в котором находимся
}

void MainWindow::on_pushButtonClient_clicked()//кнопка для перехода в раздел данные о клиенте
{
    clPhone->show();//открытие окна - показ
    this->close();//закрыли объект в котором находимся

}

void MainWindow::on_pushButtonService_clicked()//кнопка для перехода в раздел услуги
{
    servPhone->show();//открытие окна - показ
    this->close();//закрыли объект в котором находимся
}


void MainWindow::on_pushButtonTariff_clicked()//кнопка для перехода в раздел тариф
{
    tPhone->show();//открытие окна - показ
    this->close();//закрыли объект в котором находимся
}

void MainWindow::on_pushButtonPayment_clicked()//кнопка для перехода в раздел платеж
{
    payPhone->show();//открытие окна - показ
    this->close();//закрыли объект в котором находимся
}

void MainWindow::on_pushButtonModelPhone_clicked()//кнопка для перехода в раздел модель телефона
{
    modPhone->show();//открытие окна - показ
    this->close();//закрыли объект в котором находимся
}


