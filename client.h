#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QXmlStreamWriter>//поделючаем директиву для работы с XML
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QFile>


namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

    QFile client;//

    QString nameClient, dateBirth, placeBirth, adress, pasport, issuedBy, dateIssue, codeDepartament;//переменные строкового типа

private:
    Ui::Client *ui;

    bool testRegExpName(QString fr);//для ФИО регулярное выражение
    bool testRegExpDateBirth(QString fr);//дата рождения и даты выдачи паспорта регулярное выражение
    bool testRegExpPasport(QString fr);//паспорт номер и серия регулярное выражение
    bool testRegExpCodeDepartament(QString fr);//код подразделения регулярное выражение

signals:
    void openMainWindow();//открытие главного окна - меню

private slots:
    void on_pushButtonSaveClient_clicked();//кнопка нажатия для сохранения
    void on_pushButtonBack6_clicked();//кнопка нажатия - назад в главное меню
};

#endif // CLIENT_H
