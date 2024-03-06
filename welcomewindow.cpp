#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include <QPixmap>
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Assignments/CinemaProject/743a9b5390c5957a6b3dc3a0879d4c40.jpg");
    ui->label_pic->setPixmap(pix.scaled(650,500));

}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::set_Name_Age(QString name, QString age){
    ui->label_out_name->setText(name);
    ui->label_age->setText(age);
}

void WelcomeWindow::on_pushButton_logout_clicked()
{
    hide();
    LoginWindow* login_window = new LoginWindow();
    login_window->show();
}

