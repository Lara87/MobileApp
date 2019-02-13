#include "titleapp.h"
#include "ui_titleapp.h"
#include <QKeyEvent>
#include <QDebug>
#include <QIcon>

TitleApp::TitleApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleApp)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color:rgb(240, 240, 240)");//установить для этого объекта цвет

             /*иконка для окна*/
    QIcon pic(":/icons/img_476114.png");
    this->setWindowIcon(pic);

}

TitleApp::~TitleApp()
{
    delete ui;

}

void TitleApp::keyPressEvent(QKeyEvent *ev)//переход в главное меню по нажатию Enter
{
    switch (ev->key())
    {
        case Qt::Key_Return:
        {
            this->close();
            emit openMainWindow();
        }
        break;

        default:
             {
        qDebug()<<"ERORR";
             }
    }
}
