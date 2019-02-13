#include "service.h"
#include "ui_service.h"
#include <QRadioButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QCheckBox>
#include <QList>
#include <QDebug>
#include <QGroupBox>
#include <QStyle>
#include <QStringList>

Service::Service(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Service)
{
    ui->setupUi(this);

    /*иконка для кнопки назад*/
    QIcon exit(":/icons/exit.png");
    ui->pushButtonBack2->setIcon(exit);

    ui->pushButtonBack2->setToolTip("Назад");

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);


    this->setStyleSheet("background-color:rgb(240, 240, 240)");//установить для этого окна стиль

                        /*стили для кнопок*/
    ui->pushButtonBack2->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                       "border-radius: 15px;border-color: beige;"
                                       "font: bold 14px");
    ui->pushButtonService->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");
}

Service::~Service()
{
    delete ui;
}

void Service::on_pushButtonService_clicked()//сохранение данных
{
    QString nameClient = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QString(), QString("Все файлы (*.*)"));
    if(nameClient.isEmpty())
    {
        QMessageBox messageError;
        messageError.setWindowTitle("Оказанная услуга");
        messageError.setText("Вы не выбрали файл для сохранения данных");
        messageError.setInformativeText("Выберете файл");
        messageError.setStandardButtons(QMessageBox::Ok);
        messageError.setButtonText(QMessageBox::Ok, "Закрыть");
        messageError.setIcon(QMessageBox::Information);
        messageError.exec();
    }
    else {
        QList<QCheckBox *> allButtons = ui->groupBox->findChildren<QCheckBox *>();//положили все checkbox в list
        for(int i = 0; i < allButtons.size(); i++)
        {
             if(allButtons.at(i)->isChecked())
           {
                 services = allButtons.value(i)->text();
                 if (nameClient != " ")
                    {
                      QFile client(nameClient);
                      if(client.open(QIODevice::Append))
                         {
                           QXmlStreamWriter xmlWriter(&client);
                           xmlWriter.setAutoFormatting(true);  // Устанавливаем автоформатирование текста
                           xmlWriter.writeStartDocument();     // Запускаем запись в документ
                           xmlWriter.writeStartElement("Оказанная услуга");   // Записываем первый элемент с его именем
                           xmlWriter.writeCharacters(services);
                           xmlWriter.writeEndElement();        // Закрываем тег
                           xmlWriter.writeEndDocument();//Завершаем запись в документ
                          }
                      client.close();//закрыли файловый поток
                     }
              }
           }
                QMessageBox messageSave;
                messageSave.setWindowTitle("Оказанная услуга");
                messageSave.setText("Данные сохранены в файл");
                messageSave.setIcon(QMessageBox::Warning);
                messageSave.exec();

             this->close();
             emit openMainWindow();//создаем открытие след окна

    }
}


void Service::on_pushButtonBack2_clicked()//кнопка назад в главное меню
{
    this->close();
    emit openMainWindow();//создаем открытие след окна
}
