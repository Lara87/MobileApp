#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <titleapp.h>
#include <numberphone.h>
#include <modelphone.h>
#include <service.h>
#include <tariff.h>
#include <payment.h>
#include <client.h>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QIcon>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonClient_clicked();//кнопка перехода в меню - данные о владельце

    void on_pushButtonNumberPhone_clicked();//кнопка перехода в меню - номер телефона

    void on_pushButtonService_clicked();//кнопка перехода в меню - услуги

    void on_pushButtonTariff_clicked();//кнопка перехода в меню - тариф

    void on_pushButtonPayment_clicked();//кнопка перехода в меню - платеж

    void on_pushButtonModelPhone_clicked();//кнопка перехода в меню - модель телефона

private:
    Ui::MainWindow *ui;

    TitleApp *titleA;//титульник - создали объект нового окна от TitleApp

    Client *clPhone;//клиент - создали объект нового окна от Client

    NumberPhone *numPhone;//номер телефона  - создали объект нового окна от NumberPhone

    ModelPhone *modPhone;//модель телефона - создали объект нового окна от ModelPhone

    Service *servPhone;//услуга - создали объект нового окна от Service

    Tariff *tPhone;//тариф - создали объект нового окна от Tariff

    Payment *payPhone;//платеж - создали объект нового окна от Payment
};

#endif // MAINWINDOW_H
