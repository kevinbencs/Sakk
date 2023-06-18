#include "difficulty.h"
#include "ui_difficulty.h"
#include <fstream>

Difficulty::Difficulty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Difficulty)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
    setWindowIcon(QIcon("Gui/Chess.jpg"));

    menuBar=new QMenuBar();
    menu=new QMenu("Sötét téma");
    Action=new QAction("Bekapcsol");
    menu->addAction(Action);
    menuBar->addMenu(menu);


    this->layout()->setMenuBar(menuBar);
    connect(Action,&QAction::triggered,this,&Difficulty::on_Action_triggered);

    std::ifstream in("Theme");
    in>>theme;

    in.close();

    if(theme==0){
        qApp->setStyleSheet("Difficulty{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_3->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->label->setText("<p align=center><span style= color:white;font-size:24pt><b>Válassz nehézséget:<b><span><p>");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("Difficulty{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_3->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->label->setText("<p align=center><span style= color:black;font-size:24pt><b>Válassz nehézséget:<b><span><p>");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
    }
}



void Difficulty::on_Action_triggered()
{
    if(Action->text()=="Bekapcsol"){
        qApp->setStyleSheet("Difficulty{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_3->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->label->setText("<p align=center><span style= color:white;font-size:24pt><b>Válassz nehézséget:<b><span><p>");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
        theme=0;
    }
    else{
        qApp->setStyleSheet("Difficulty{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_3->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->label->setText("<p align=center><span style= color:black;font-size:24pt><b>Válassz nehézséget:<b><span><p>");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;

    out.close();
}




Difficulty::~Difficulty()
{
    delete ui;
}

//easy
void Difficulty::on_pushButton_clicked()
{
    hide();
    White_or_black white_or_black;
    white_or_black.set_difficulty_level(1);
    white_or_black.show();
    white_or_black.exec();
}

//medium
void Difficulty::on_pushButton_2_clicked()
{
    hide();
    White_or_black white_or_black;
    white_or_black.set_difficulty_level(2);
    white_or_black.show();
    white_or_black.exec();
}

//hard
void Difficulty::on_pushButton_3_clicked()
{
    hide();
    White_or_black white_or_black;
    white_or_black.set_difficulty_level(3);
    white_or_black.show();
    white_or_black.exec();
}

