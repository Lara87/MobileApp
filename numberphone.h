#ifndef NUMBERPHONE_H
#define NUMBERPHONE_H

#include <QWidget>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

namespace Ui {
class NumberPhone;
}

class NumberPhone : public QWidget
{
    Q_OBJECT

public:
    explicit NumberPhone(QWidget *parent = nullptr);
    ~NumberPhone();

    QString numberPhone;

private slots:

    void on_pushButtonSaveNumPhone_clicked();//сохранение данных

    void on_pushButtonBack4_clicked();//переход в главное меню

private:
    Ui::NumberPhone *ui;
    bool testRegExpNumberPhone(QString fr);//регулярка для номера телефона

signals:
    void openMainWindow();//открытие главного окна

};

#endif // NUMBERPHONE_H
