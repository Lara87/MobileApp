#ifndef SERVICE_H
#define SERVICE_H

#include <QWidget>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

namespace Ui {
class Service;
}

class Service : public QWidget
{
    Q_OBJECT

public:
    explicit Service(QWidget *parent = nullptr);
    ~Service();

    QString services;

private:
    Ui::Service *ui;

signals:
    void openMainWindow();//открытие главного окна
private slots:
    void on_pushButtonService_clicked();//кнопка сохранения данных
    void on_pushButtonBack2_clicked();//кнопка возврат в главное меню
};

#endif // SERVICE_H
