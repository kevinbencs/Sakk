#include "white_or_black.h"
#include "ui_white_or_black.h"
#include <fstream>
#include <ctime>

White_or_black::White_or_black(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::White_or_black)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("Gui/Chess.jpg"));

    menuBar=new QMenuBar();
    menu=new QMenu("Sötét téma");
    Action=new QAction("Bekapcsol");
    menu->addAction(Action);
    menuBar->addMenu(menu);


    this->layout()->setMenuBar(menuBar);

    connect(Action,&QAction::triggered,this,&White_or_black::on_Action_triggered);

    std::ifstream in("Theme");
    in>>theme;

    in.close();

    if(theme==0){
        qApp->setStyleSheet("White_or_black{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("White_or_black{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("");
        ui->pushButton_2->setStyleSheet("");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
    }
}



void White_or_black::on_Action_triggered()
{
    if(Action->text()=="Bekapcsol"){
        qApp->setStyleSheet("White_or_black{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
        theme=0;
    }
    else{
        qApp->setStyleSheet("White_or_black{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("");
        ui->pushButton_2->setStyleSheet("");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;

    out.close();
}




White_or_black::~White_or_black()
{
    delete ui;
}

//white
void White_or_black::on_pushButton_clicked()
{
    Game game;
    hide();
    int WhiteOrBlack=1;
    game.show();
    game.exec();
}

//black
void White_or_black::on_pushButton_2_clicked()
{
    Game game;
    hide();
    int WhiteOrBlack=1;
    game.show();
    game.exec();
}


void White_or_black::on_pushButton_3_clicked()
{
    Game game;
    hide();
    srand(time(0));
    int WhiteOrBlack=rand()%2;
    game.show();
    game.exec();
}

