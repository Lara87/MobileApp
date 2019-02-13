#ifndef TARIFF_H
#define TARIFF_H

#include <QWidget>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QComboBox>

namespace Ui {
class Tariff;
}

class Tariff : public QWidget
{
    Q_OBJECT

public:
    explicit Tariff(QWidget *parent = nullptr);
    ~Tariff();
    QString tariff;

private:
    Ui::Tariff *ui;

signals:
    void openMainWindow();//открытие главного окна
private slots:
    void on_pushButtonSaveTariff_clicked();//кнопка сохранения данных
    void on_pushButtonDetailedTariff_clicked();//кнопка детализация тарифа
    void on_pushButtonBack1_clicked();//кнопка возврат в главное меню
};

#endif // TARIFF_H
