#include "payment.h"
#include "ui_payment.h"
#include <QRegularExpression>
#include <QFileDialog>
#include <QMessageBox>

Payment::Payment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);

    /*иконка для кнопки назад*/
    QIcon exit(":/icons/exit.png");
    ui->pushButtonBack3->setIcon(exit);

    ui->lineEditPayment->setToolTip("в формате: 000 руб.");

    /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

    ui->pushButtonBack3->setToolTip("Назад");

    ui->lineEditPayment->setStyleSheet("border-radius: 15px;border-style: solid; border-width:2px; border-color: #7B68EE");
    ui->pushButtonBack3->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                       "border-radius: 15px;border-color: beige;"
                                       "font: bold 14px");
    ui->pushButtonSavePay->setStyleSheet("background-color: #7B68EE; border-style: outset;border-width: 3px;"
                                            "border-radius: 15px;border-color: beige;"
                                            "font: bold 14px");

}

Payment::~Payment()
{
    delete ui;
}

void Payment::on_pushButtonSavePay_clicked()
{
    payPhone=ui->lineEditPayment->text();

    if(testRegExpPayment(payPhone))
    {
        QString nameClient = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QString(), QString("Все файлы (*.*)"));
        if(nameClient.isEmpty())
        {
            QMessageBox messageError;
            messageError.setWindowTitle("Сумма платежа");
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
                xmlWriter.writeStartElement("Сумма платежа");   // Записываем первый элемент с его именем
                xmlWriter.writeCharacters(ui->lineEditPayment->text());
                xmlWriter.writeEndElement();        // Закрываем тег
                xmlWriter.writeEndDocument();//* Завершаем запись в документ
             }

         client.close();

                QMessageBox messageSave;
                messageSave.setWindowTitle("Сумма платежа");
                messageSave.setText("Данные сохранены в файл");
                messageSave.setIcon(QMessageBox::Warning);
                messageSave.exec();

                this->close();
                emit openMainWindow();//создаем открытие след окна
           }
       }
     else
     {
         QMessageBox messageError;
         messageError.setWindowTitle("Сумма платежа");
         messageError.setText("Неправильно введены данные");
         messageError.setInformativeText("Введите еще раз");
         messageError.setStandardButtons(QMessageBox::Ok);
         messageError.setButtonText(QMessageBox::Ok, "Закрыть");
         messageError.setIcon(QMessageBox::Information);
         messageError.exec();
         ui->lineEditPayment->clear();
     }

}

bool Payment::testRegExpPayment(QString fr)//регулярное выражение для суммы платежа - формат "ххх руб."
{
    QRegularExpression reg("^[\\d\\s]+?руб\\.$");//цифры, пробел +руб.
    QRegularExpressionMatch match = reg.match(fr);//объект, кот хранит информацию о проверке на соответствие
        if(match.hasMatch())//если соответствие найдено?
        {
            return true;
        }
            else return false;
}

void Payment::on_pushButtonBack3_clicked()//назад в главное меню
{
    this->close();
    emit openMainWindow();//создаем открытие след окна
}
