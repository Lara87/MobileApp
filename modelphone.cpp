#include "modelphone.h"
#include "ui_modelphone.h"
#include <QMessageBox>
#include <QRadioButton>
#include "QDebug"
#include <QString>
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

ModelPhone::ModelPhone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelPhone)
{
    ui->setupUi(this);

    /*иконка для кнопки назад*/
    QIcon exit(":/icons/exit.png");
    ui->pushButtonBack6->setIcon(exit);

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

    ui->pushButtonBack6->setToolTip("Назад");

                               /*стилизация кнопок*/
    ui->pushButtonBack6->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                       "border-radius: 15px;border-color: beige;"
                                       "font: bold 14px");

    ui->pushButtonSaveModelPh->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");
}

ModelPhone::~ModelPhone()
{
    delete ui;
}

void ModelPhone::on_pushButtonSaveModelPh_clicked()
{
    if(ui->radioButton_1->isChecked())//если выбрали этот радиобаттон, то кладем в переменную значение
    {
        modelPhone = "BlackBerry";
    }
    else if (ui->radioButton_2->isChecked()) {
        modelPhone ="Ericsson";
    }
    else if (ui->radioButton_3->isChecked()) {
        modelPhone="Fly";
    }
    else if (ui->radioButton_4->isChecked()) {
        modelPhone = "Apple";
    }
    else if (ui->radioButton_5->isChecked()) {
        modelPhone = "Alcatel";
    }
    else if (ui->radioButton_6->isChecked()) {
        modelPhone = "Acer";
    }
    else if (ui->radioButton_7->isChecked()) {
        modelPhone = "Huawei";
    }
    else if (ui->radioButton_8->isChecked()) {
        modelPhone = "Haier";
    }
    else if (ui->radioButton_9->isChecked()) {
        modelPhone = "Asus";
    }
    else if (ui->radioButton_10->isChecked()) {
        modelPhone = "Motorola";
    }
    else if (ui->radioButton_11->isChecked()) {
        modelPhone = "Nokia";
    }
    else if (ui->radioButton_12->isChecked()) {
        modelPhone = "Panasonic";
    }
    else if (ui->radioButton_13->isChecked()) {
        modelPhone = "Philips";
    }
    else if (ui->radioButton_14->isChecked()) {
        modelPhone = "Samsung";
    }
    else if (ui->radioButton_15->isChecked()) {
        modelPhone = "Siemens";
    }
    else if (ui->radioButton_16->isChecked()) {
        modelPhone = "Sony Ericsson";
    }
    else if (ui->radioButton_17->isChecked()) {
        modelPhone = "Xiaomi";
    }//если не выбрали ничего сообщение об ошибке
    else {
        QMessageBox messageError;
        messageError.setWindowTitle("Модель телефоноа");
        messageError.setText("Вы не выбрали ни одну модель телефона");
        messageError.setInformativeText("Выберете модель телефона");
        messageError.setStandardButtons(QMessageBox::Ok);
        messageError.setButtonText(QMessageBox::Ok, "Закрыть");
        messageError.setIcon(QMessageBox::Information);
        messageError.exec();
    }

/*если один из радиобатоннов выбран то */
    if((ui->radioButton_1->isChecked())||(ui->radioButton_2->isChecked())|| (ui->radioButton_3->isChecked())||(ui->radioButton_4->isChecked())||(ui->radioButton_5->isChecked())
            ||(ui->radioButton_6->isChecked())||(ui->radioButton_7->isChecked())||(ui->radioButton_8->isChecked())||(ui->radioButton_9->isChecked())||(ui->radioButton_10->isChecked())||(ui->radioButton_11->isChecked())
            ||(ui->radioButton_12->isChecked())||(ui->radioButton_13->isChecked())||(ui->radioButton_14->isChecked())||(ui->radioButton_15->isChecked())||(ui->radioButton_16->isChecked())||(ui->radioButton_17->isChecked())||(ui->radioButton_18->isChecked()))
      {
        /*открываем диалоговое окно, чтобы пользователь выбрал файл, куда сохранять данные*/
        QString nameClient = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QString(), QString("Все файлы (*.*)"));
        if(nameClient.isEmpty())
        {
            QMessageBox messageError;
            messageError.setWindowTitle("Модель телефона");
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
                                  xmlWriter.writeStartElement("Модель телефона");   // Записываем первый элемент с его именем
                                  xmlWriter.writeCharacters(modelPhone);
                                  xmlWriter.writeEndElement();        // Закрываем тег
                                  xmlWriter.writeEndDocument();// Завершаем запись в документ
                                }
                      client.close();

                      QMessageBox messageSave;
                      messageSave.setWindowTitle("Модель телефона");
                      messageSave.setText("Данные сохранены в файл");
                      messageSave.setIcon(QMessageBox::Warning);
                      messageSave.exec();

                      this->close();
                      emit openMainWindow();//создаем открытие след окна
                }

       }
}

void ModelPhone::on_pushButtonBack6_clicked()//кнопка назад - возврат в главное меню
{
    this->close();
    emit openMainWindow();//создаем открытие след окна
}
