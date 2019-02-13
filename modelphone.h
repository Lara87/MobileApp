#ifndef MODELPHONE_H
#define MODELPHONE_H
#include <QWidget>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

namespace Ui {
class ModelPhone;
}

class ModelPhone : public QWidget
{
    Q_OBJECT

public:
    explicit ModelPhone(QWidget *parent = nullptr);
    ~ModelPhone();

     QString modelPhone;//создала строковую переменную

private:
    Ui::ModelPhone *ui;

signals:
    void openMainWindow();//открытие главного окна
private slots:
    void on_pushButtonBack6_clicked();//переход назад в главное меню
    void on_pushButtonSaveModelPh_clicked();//сохранение данных
};

#endif // MODELPHONE_H
