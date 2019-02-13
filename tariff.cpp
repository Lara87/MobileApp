#include "tariff.h"
#include "ui_tariff.h"
#include <QComboBox>
#include <QFileDialog>
#include <QList>
#include <QRadioButton>
#include <QTextEdit>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <iostream>

Tariff::Tariff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tariff)
{
    ui->setupUi(this);

    ui->pushButtonBack1->setToolTip("Назад");

    /*иконка для кнопки назад*/
    QIcon exit(":/icons/exit.png");
    ui->pushButtonBack1->setIcon(exit);

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

    this->setStyleSheet("background-color:rgb(240, 240, 240)");//установили стиль для данного окна


    /*стилизация кнопок*/
    ui->pushButtonBack1->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                       "border-radius: 15px;border-color: beige;"
                                       "font: bold 14px");
    ui->pushButtonSaveTariff->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");
    ui->pushButtonDetailedTariff->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");
}

Tariff::~Tariff()
{
    delete ui;
}

void Tariff::on_pushButtonSaveTariff_clicked()//кнопка сохранения данных
{
    /*если выбран радиобатон, то в переменную кладем название тарифа */
    if(ui->radioButtonVse1->isChecked())
    {
        tariff = "ВСЁмоё1";
    }
    else if (ui->radioButtonVse2->isChecked()) {
        tariff ="ВСЁмоё2";
    }
    else if (ui->radioButtonVse3->isChecked()) {
        tariff="ВСЁмоё3";
    }
    else if (ui->radioButtonVse4->isChecked()) {
        tariff = "ВСЁмоё4";
    }
    else if (ui->radioButtonSovsemVse->isChecked()) {
        tariff = "Совсем ВСЁмоё";
    }
    else if (ui->radioButtonVseshechka->isChecked()) {
        tariff = "Всёшечка";
    }
    else {
        QMessageBox messageError;//окно - сообщение об ошибке
        messageError.setWindowTitle("Тариф");
        messageError.setText("Вы не выбрали ни одного тарифа");
        messageError.setInformativeText("Выберете тариф");
        messageError.setStandardButtons(QMessageBox::Ok);
        messageError.setButtonText(QMessageBox::Ok, "Закрыть");
        messageError.setIcon(QMessageBox::Information);
        messageError.exec();
    }
/*если один из радиобатонов выбран*/
    if((ui->radioButtonVse1->isChecked())||(ui->radioButtonVse2->isChecked())|| (ui->radioButtonVse3->isChecked())||(ui->radioButtonVse4->isChecked())||(ui->radioButtonSovsemVse->isChecked())
            ||(ui->radioButtonVseshechka->isChecked()))
      {
        QString nameClient = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QString(), QString("Все файлы (*.*)"));//открываем даилоговое окно для выбора файла для сохранения данных
        if(nameClient.isEmpty())
        {
            QMessageBox messageError;
            messageError.setWindowTitle("Тариф");
            messageError.setText("Вы не выбрали файл для сохранения данных");
            messageError.setInformativeText("Выберете файл");
            messageError.setStandardButtons(QMessageBox::Ok);
            messageError.setButtonText(QMessageBox::Ok, "Закрыть");
            messageError.setIcon(QMessageBox::Information);
            messageError.exec();
        }
            else
                {
                     QFile client(nameClient);//создали файл
                        if(client.open(QIODevice::Append | QIODevice::ReadWrite | QIODevice::Text))//добавляем в существующий файл данные, не затирая предыдущие
                              {
                                  QXmlStreamWriter xmlWriter(&client);
                                  xmlWriter.setAutoFormatting(true);// Устанавливаем автоформатирование текста
                                  xmlWriter.writeStartDocument();// Запускаем запись в документ
                                  xmlWriter.writeStartElement("Тариф");// Записываем первый элемент с его именем
                                  xmlWriter.writeCharacters(tariff);
                                  xmlWriter.writeEndElement();// Закрываем тег
                                  xmlWriter.writeEndDocument();//Завершаем запись в документ
                                }
                        client.close();
                }

                        QMessageBox messageSave;//окно - данные сохранены
                        messageSave.setWindowTitle("Тариф");
                        messageSave.setText("Данные сохранены в файл");
                        messageSave.setIcon(QMessageBox::Warning);
                        messageSave.exec();
             }
                      this->close();
                      emit openMainWindow();//создаем открытие след окна
}


void Tariff::on_pushButtonDetailedTariff_clicked()//кнопка подробнее о тарифе
{
    if(ui->radioButtonVse1->isChecked())
    {
            QFile descripTariff ("C:\\Qt\\QtProjects\\PracticeEx\\Vse1.html");//создали объект для файла QFile_название_путь с расширешением
               if (descripTariff.open(QIODevice::ReadOnly))  //открываем файл и только для чтения - флаг для открытия
               {
                   QTextStream stream (&descripTariff);//поток
                   tariff = stream.readAll();//здесь мы решаем как читать: полностью, построчно, посимвольно и преобразовали это в строку
                   ui->textEdit->setText(tariff);
               }
                descripTariff.close();
      }
    else if (ui->radioButtonVse2->isChecked()) {
    QFile descripTariff ("C:\\Qt\\QtProjects\\PracticeEx\\Vse2.html");//создали объект для файла QFile_название_путь с расширешением
       if (descripTariff.open(QIODevice::ReadOnly))  //открываем файл и только для чтения - флаг для открытия
       {
           QTextStream stream (&descripTariff);//поток
           tariff = stream.readAll();//здесь мы решаем как читать: полностью, построчно, посимвольно и преобразовали это в строку
           ui->textEdit->setText(tariff);
       }
        descripTariff.close();
}
    else if (ui->radioButtonVse3->isChecked()) {
        QFile descripTariff ("C:\\Qt\\QtProjects\\PracticeEx\\Vse3.html");//создали объект для файла QFile_название_путь с расширешением
           if (descripTariff.open(QIODevice::ReadOnly))  //открываем файл и только для чтения - флаг для открытия
           {
               QTextStream stream (&descripTariff);//поток
               tariff = stream.readAll();//здесь мы решаем как читать: полностью, построчно, посимвольно и преобразовали это в строку
               ui->textEdit->setText(tariff);
           }
            descripTariff.close();
    }
    else if (ui->radioButtonVse4->isChecked()) {
        QFile descripTariff ("C:\\Qt\\QtProjects\\PracticeEx\\Vse4.html");//создали объект для файла QFile_название_путь с расширешением
           if (descripTariff.open(QIODevice::ReadOnly))  //открываем файл и только для чтения - флаг для открытия
           {
               QTextStream stream (&descripTariff);//поток
               tariff = stream.readAll();//здесь мы решаем как читать: полностью, построчно, посимвольно и преобразовали это в строку
               ui->textEdit->setText(tariff);
           }
            descripTariff.close();
    }
    else if (ui->radioButtonSovsemVse->isChecked()) {
        QFile descripTariff ("C:\\Qt\\QtProjects\\PracticeEx\\SovsemVse.html");//создали объект для файла QFile_название_путь с расширешением
           if (descripTariff.open(QIODevice::ReadOnly))  //открываем файл и только для чтения - флаг для открытия
           {
               QTextStream stream (&descripTariff);//поток
               tariff = stream.readAll();//здесь мы решаем как читать: полностью, построчно, посимвольно и преобразовали это в строку
               ui->textEdit->setText(tariff);
           }
            descripTariff.close();
    }
    else if (ui->radioButtonVseshechka->isChecked()){
        QFile descripTariff ("C:\\Qt\\QtProjects\\PracticeEx\\Vseshechka.html");//создали объект для файла QFile_название_путь с расширешением
           if (descripTariff.open(QIODevice::ReadOnly))  //открываем файл и только для чтения - флаг для открытия
           {
               QTextStream stream (&descripTariff);//поток
               tariff = stream.readAll();//здесь мы решаем как читать: полностью, построчно, посимвольно и преобразовали это в строку
               ui->textEdit->setText(tariff);
           }
            descripTariff.close();
    }
}

void Tariff::on_pushButtonBack1_clicked()//кнопка - возврат в главное меню
{
    this->close();
    emit openMainWindow();//создаем открытие след окна
}
