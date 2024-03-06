#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QDialog
{
    Q_OBJECT;

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

public slots:
    void set_Name_Age(QString name, QString age);

private slots:
    void on_pushButton_logout_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H
