#include "numberphone.h"
#include "ui_numberphone.h"
#include <QObject>
#include <QApplication>
#include "QDebug"
#include <QRegExp>
#include <QRegularExpression>
#include <QString>
#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>


NumberPhone::NumberPhone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberPhone)
{
    ui->setupUi(this);  

    /*иконка для кнопки назад*/
    QIcon exit(":/icons/exit.png");
    ui->pushButtonBack4->setIcon(exit);

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

    ui->pushButtonBack4->setToolTip("Назад");


                           /*стилизация кнопок*/
    ui->pushButtonBack4->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                       "border-radius: 15px;border-color: beige;"
                                       "font: bold 14px");

    ui->pushButtonSaveNumPhone->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");
    ui->lineEditNumPhone->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");


}

NumberPhone::~NumberPhone()
{
    delete ui;
}

void NumberPhone::on_pushButtonSaveNumPhone_clicked()//кнопка для сохранения введенных данных
{
    numberPhone=ui->lineEditNumPhone->text();

    if(testRegExpNumberPhone(numberPhone))
    {
        QString nameClient = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QString(), QString("Все файлы (*.*)"));
        if(nameClient.isEmpty())
        {
            QMessageBox messageError;
            messageError.setWindowTitle("Номер телефона");
            messageError.setText("Вы не выбрали файл для сохранения данных");
            messageError.setInformativeText("Выберете файл");
            messageError.setStandardButtons(QMessageBox::Ok);
            messageError.setButtonText(QMessageBox::Ok, "Закрыть");
            messageError.setIcon(QMessageBox::Information);
            messageError.exec();
        }
        else if (nameClient != " ")
        {
            QFile client(nameClient);
            if(client.open(QIODevice::Append))
            {
                QXmlStreamWriter xmlWriter(&client);
                xmlWriter.setAutoFormatting(true);  // Устанавливаем автоформатирование текста
                xmlWriter.writeStartDocument();     // Запускаем запись в документ
                xmlWriter.writeStartElement("Номер телефона");   // Записываем первый элемент с его именем
                xmlWriter.writeCharacters(ui->lineEditNumPhone->text());
                xmlWriter.writeEndElement();        // Закрываем тег

                /* Завершаем запись в документ
                 * */
                xmlWriter.writeEndDocument();
            }

         client.close();

                QMessageBox messageSave;
                messageSave.setWindowTitle("Номер телефона");
                messageSave.setText("Данные сохранены в файл");
                messageSave.setIcon(QMessageBox::Warning);
                messageSave.exec();

                this->close();
                emit openMainWindow();//создаем открытие след окна
           }

     else
     {
         QMessageBox messageError;
         messageError.setWindowTitle("Номер телефона");
         messageError.setText("Неправильно введены данные");
         messageError.setInformativeText("Введите еще раз");
         messageError.setStandardButtons(QMessageBox::Ok);
         messageError.setButtonText(QMessageBox::Ok, "Закрыть");
         messageError.setIcon(QMessageBox::Information);
         messageError.exec();
         ui->lineEditNumPhone->clear();
     }
   }
}

bool NumberPhone::testRegExpNumberPhone(QString fr)//регулярка для номера телефона
{
    QRegularExpression reg("^((8|\\+7)[\\- ]?)?(\\(?\\d{3}\\)?[\\- ]?)?[\\d\\- ]{7,10}$");//
    QRegularExpressionMatch match = reg.match(fr);//объект, кот хранит информацию о проверке на соответствие
        if(match.hasMatch())//если соответствие найдено
        {
            return true;
        }
            else return false;
}


void NumberPhone::on_pushButtonBack4_clicked()//кнопка назад в главное меню
{
    this->close();
    emit openMainWindow();//создаем открытие след окна
}
