#ifndef TITLEAPP_H
#define TITLEAPP_H
#include <QWidget>

namespace Ui {
class TitleApp;
}

class TitleApp : public QWidget
{
    Q_OBJECT

public:
    explicit TitleApp(QWidget *parent = 0);
    ~TitleApp();

private:
    Ui::TitleApp *ui;
    void keyPressEvent (QKeyEvent *);//переход в главное меню из титульника по нажатию кнопки Enter

signals:
    void openMainWindow();//открытие главного окна
};

#endif // TITLEAPP_H
