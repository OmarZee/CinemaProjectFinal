#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include<QDebug>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->all_fields_error->setVisible(false);
    ui->label_age_error->setVisible(false);
    ui->label_pass_error->setVisible(false);
    ui->label_name_error->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{

    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString password2 = ui->lineEdit_re_pass->text();
    QString month = ui->month->currentText();
    QString day = ui->day->text();
    QString year = ui->year->text();
    QString gender;
    QString account_type;
    QString genre[6];
    bool username_check = false;
    bool pass_check = false;
    bool account_check = false;
    bool genre_check = false;
    bool gender_check = false;
    bool age_check = false;
    bool all_error = true;

    // Username Check
    for(int i=0;i<100;i++){
        if(username == usernames[i]){
            ui->label_name_error->setVisible(true);
            username_check = true;
            break;
        }
        else{
            ui->label_name_error->setVisible(false);
            username_check = false;
        }
    }
    // Password Check
    if(password != password2){
        ui->label_pass_error->setVisible(true);
        pass_check = true;
    }
    else{
        ui->label_pass_error->setVisible(false);
        pass_check = false;
    }
    // Check Age
    int year_number = year.toInt();
    int user_age = 2024 - year_number;
    if(user_age < 12){
        ui->label_age_error->setVisible(true);
        age_check = true;
    }
    else{
        ui->label_age_error->setVisible(false);
        age_check = false;
    }

    // Gender
    if(ui->male->isChecked()){
        gender = "male";
        gender_check = true;
    }
    else if(ui->female->isChecked()){
        gender = "female";
        gender_check = true;
    }
    // Account Type
    if(ui->user->isChecked()){
        account_type = "user";
        account_check = true;
    }
    else if(ui->admin->isChecked()){
        account_type = "admin";
        account_check = true;
    }

    // Genres
    if(ui->Action->isChecked()){
        genre[0] = "Action";
        genre_check = true;
    }
    if(ui->Comedy->isChecked()){
        genre[1] = "Comedy";
        genre_check = true;
    }
    if(ui->Horror->isChecked()){
        genre[2] = "Horror";
        genre_check = true;
    }
    if(ui->Romance->isChecked()){
        genre[3] = "Action";
        genre_check = true;
    }
    if(ui->Drama->isChecked()){
        genre[4] = "Comedy";
        genre_check = true;
    }
    if(ui->Other->isChecked()){
        genre[5] = "Horror";
        genre_check = true;
    }

    // All fields check
    if(username_check || !genre_check || !account_check || !gender_check || age_check){
        ui->all_fields_error->setVisible(true);
        all_error = true;
    }
    else{
        all_error = false;
    }
    if(!all_error)
    {
        ui->all_fields_error->setVisible(false);
        all_error = false;
        usernames[usersCount] = username;
        ages[usersCount] = user_age;
        passwords[usersCount] = password;
        usersCount++;
        hide();

        WelcomeWindow* welcome_window = new WelcomeWindow;
        welcome_window->set_Name_Age(username,QString::number(user_age));
        welcome_window->show();
    }




}

