#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

namespace Ui {
class Payment;
}

class Payment : public QWidget
{
    Q_OBJECT

public:
    explicit Payment(QWidget *parent = nullptr);
    ~Payment();
    QString payPhone;

private:
    Ui::Payment *ui;
    bool testRegExpPayment(QString fr);//регулярка для платежа

signals:
    void openMainWindow();//открытие главного окна
private slots:
    void on_pushButtonSavePay_clicked();//кнопка сохранения данных
    void on_pushButtonBack3_clicked();//возврат в главное меню
};

#endif // PAYMENT_H
