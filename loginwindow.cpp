#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Login_button_clicked()
{
    WelcomeWindow* welcome_window = new WelcomeWindow(this);
    for(int i=0;i<100;i++){
        if((usernames[i] == ui->lineEdit_username->text()) && (passwords[i] == ui->lineEdit_password->text())){
            ui->label_error->setVisible(false);
            hide();
            QString age_string = QString::number(ages[i]);
            welcome_window->set_Name_Age(usernames[i], age_string);
            welcome_window->show();
            break;
        }
        else{
            ui->label_error->setVisible(true);
        }
    }
}


void LoginWindow::on_Register_button_clicked()
{
    hide();
    RegisterWindow* register_window = new RegisterWindow(this);
    register_window->show();

}

