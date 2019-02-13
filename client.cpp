#include "client.h"
#include "ui_client.h"
#include <QObject>
#include <QApplication>
#include "QDebug"
#include "QRegExp"
#include <QRegExp>
#include <QRegularExpression>
#include <QString>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QStyle>
#include <QPushButton>

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    /*иконка для кнопки назад*/
    QIcon exit(":/icons/exit.png");
    ui->pushButtonBack6->setIcon(exit);

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

    ui->pushButtonBack6->setToolTip("Назад");
    ui->lineEditPasport->setToolTip("в формате 00 00 000000");
    ui->lineEditCodeDepartement->setToolTip("в формате 000-000");

                                  /*стилизация кнопок и окошек для ввода данных*/
    ui->lineEditName->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditAdress->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditPasport->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditIssuedBy->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditDateBirth->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditDateIssue->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditPlaceBirth->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->lineEditCodeDepartement->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->pushButtonBack6->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                       "border-radius: 15px;border-color: beige;"
                                       "font: bold 14px");
    ui->pushButtonSaveClient->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButtonSaveClient_clicked()//кнопка нажатия для сохранения всех данных в файл
{
    nameClient=ui->lineEditName->text();//ф.и.о. клиента
    dateBirth=ui->lineEditDateBirth->text();//дата рождения
    placeBirth=ui->lineEditPlaceBirth->text();//место рождения
    adress=ui->lineEditAdress->text();//адрес
    pasport=ui->lineEditPasport->text();//серия и номер паспорта
    issuedBy=ui->lineEditIssuedBy->text();//кем выдан
    dateIssue=ui->lineEditDateIssue->text();//когда выдан
    codeDepartament=ui->lineEditCodeDepartement->text();//код подразделения

    //если все введенные данные правильны
    if((testRegExpName(nameClient))&&(testRegExpDateBirth(dateBirth))&&(testRegExpPasport(pasport))&&(testRegExpDateBirth(dateIssue))&&(testRegExpCodeDepartament(codeDepartament)))
    {
        QFile client(nameClient);//создаем файл только для записи с названием ф.и.о. клиента полностью

        if(client.open(QIODevice::WriteOnly))
        {
               QXmlStreamWriter xmlWriter(&client);
               xmlWriter.setAutoFormatting(true);  // Устанавливаем автоформатирование текста
               xmlWriter.writeStartDocument();     // Запускаем запись в документ
               xmlWriter.writeStartElement("Данные о клиенте");   // Записываем первый элемент с его именем

               xmlWriter.writeStartElement("Ф.И.О. клиента");  // Записываем тег с именем
               xmlWriter.writeCharacters(ui->lineEditName->text());//Считали значение
               xmlWriter.writeEndElement();        // Закрываем тег

               xmlWriter.writeStartElement("Дата рождения");
               xmlWriter.writeCharacters(ui->lineEditDateBirth->text());
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeStartElement("Место рождения");
               xmlWriter.writeCharacters(ui->lineEditPlaceBirth->text());
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeStartElement("Адрес регистрации или место проживания");
               xmlWriter.writeCharacters(ui->lineEditAdress->text());
               xmlWriter.writeEndElement();// Закрываем тег
               /* Закрываем тег первого элемента: данные о клиенте */
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeStartElement("Паспортные данные клиента");

               xmlWriter.writeStartElement("Серия и номер паспорта");
               xmlWriter.writeCharacters(ui->lineEditPasport->text());
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeStartElement("Кем выдан");
               xmlWriter.writeCharacters(ui->lineEditIssuedBy->text());
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeStartElement("Дата выдачи");
               xmlWriter.writeCharacters(ui->lineEditDateIssue->text());
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeStartElement("Код подразделения");
               xmlWriter.writeCharacters(ui->lineEditCodeDepartement->text());
               xmlWriter.writeEndElement();// Закрываем тег

               xmlWriter.writeEndElement();// Закрываем тег               
               xmlWriter.writeEndDocument();//Завершаем запись в документ
        }

        client.close();//закрываем файл

        //выводим окно, что данные сохранены
               QMessageBox messageSave;
               messageSave.setWindowTitle("Данные о клиенте");
               messageSave.setText("Данные сохранены в файл");
               messageSave.setIcon(QMessageBox::Warning);
               messageSave.exec();

               this->close();//закрыли это окно
               emit openMainWindow();//создаем открытие след окна*/
               /*очищаем все поля*/
               ui->lineEditName->clear();
               ui->lineEditAdress->clear();
               ui->lineEditPasport->clear();
               ui->lineEditIssuedBy->clear();
               ui->lineEditDateBirth->clear();
               ui->lineEditDateIssue->clear();
               ui->lineEditPlaceBirth->clear();
               ui->lineEditCodeDepartement->clear();
}

    //если данные введены некорректно - выводим предупреждающее окно
    else
    {
        QMessageBox messageError;
        messageError.setWindowTitle("Данные о клиенте");
        messageError.setText("Неправильно введены данные");
        messageError.setInformativeText("Введите еще раз");
        messageError.setStandardButtons(QMessageBox::Ok);
        messageError.setButtonText(QMessageBox::Ok, "Закрыть");
        messageError.setIcon(QMessageBox::Information);
        messageError.exec();
    }
}

bool Client::testRegExpCodeDepartament(QString fr)//регулярка для кода подразделения
{
    QRegularExpression reg("^[\\d]{3}\\-[\\d]{3}$");
    QRegularExpressionMatch match = reg.match(fr);//объект, кот хранит информацию о проверке на соответствие
    if (match.hasMatch())//если соответствие найдено
    {
        return true;
    }
    else return false;
}

bool Client::testRegExpPasport(QString fr)//регулярка для серия и номер паспорта
{
    QRegularExpression reg("^[\\d]{2}\\s[\\d]{2}\\s[\\d]{6}$");
    QRegularExpressionMatch match = reg.match(fr);//объект, кот хранит информацию о проверке на соответствие
    if (match.hasMatch())//если соответствие найдено
    {
        return true;
    }
    else return false;

}

bool Client::testRegExpDateBirth(QString fr)//регулярка для даты
{
    QRegularExpression reg("^(((0[1-9]|[12]\\d|3[01])\\.(0[13578]|1[02])\\.((19|[2-9]\\d)\\d{2}))|((0[1-9]|[12]\\d|30)\\.(0[13456789]|1[012])\\.((19|[2-9]\\d)\\d{2}))|((0[1-9]|1\\d|2[0-8])\\.02\\.((19|[2-9]\\d)\\d{2}))|(29\\.02\\.((1[6-9]|[2-9]\\d)(0[48]|[2468][048]|[13579][26])|((16|[2468][048]|[3579][26])00))))$");
    QRegularExpressionMatch match = reg.match(fr);//объект, кот хранит информацию о проверке на соответствие
    if (match.hasMatch())//если соответствие найдено
    {
        return true;
    }
    else return false;
}

bool Client::testRegExpName(QString fr)//регулярка для ф.и.о.
{
    QRegularExpression reg("^[\\D]{2,22}[\\s]?[\\D]{2,22}[\\s]?[\\D]{2,22}$");
    QRegularExpressionMatch match = reg.match(fr);//объект, кот хранит информацию о проверке на соответствие
    if (match.hasMatch())//если соответствие найдено
    {
        return true;
    }
    else return false;
}

void Client::on_pushButtonBack6_clicked()
{
    this->close();//окно данное закрываем
    emit openMainWindow();//создаем открытие предыдущего окна
    /*очищаем все поля*/
    ui->lineEditName->clear();
    ui->lineEditAdress->clear();
    ui->lineEditPasport->clear();
    ui->lineEditIssuedBy->clear();
    ui->lineEditDateBirth->clear();
    ui->lineEditDateIssue->clear();
    ui->lineEditPlaceBirth->clear();
    ui->lineEditCodeDepartement->clear();
}
