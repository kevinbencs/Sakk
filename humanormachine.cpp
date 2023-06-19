#include "humanormachine.h"
#include "ui_humanormachine.h"
#include <fstream>

/////////////////////////////////////////////////////////////
/// HumanOrMachine::HumanOrMachine
/// You can select who you want to play against: machine or human
////////////////////////////////////////////////////////////

HumanOrMachine::HumanOrMachine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HumanOrMachine)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("Gui/Chess.jpg"));

    ///////////////////////////////////////////////////////
    /// This is the menu
    //////////////////////////////////////////////////////

    menuBar=new QMenuBar();
    menu=new QMenu("Sötét téma");
    Action=new QAction("Bekapcsol");
    menu->addAction(Action);
    menuBar->addMenu(menu);

    this->layout()->setMenuBar(menuBar);
    connect(Action,&QAction::triggered,this,&HumanOrMachine::on_Action_triggered);

    ///////////////////////////////////////////////////////////////
    /// Loading the theme of appearance
    //////////////////////////////////////////////////////////////

    std::ifstream in("Theme");
    in>>theme;
    in.close();

    if(theme==0){
        qApp->setStyleSheet("HumanOrMachine{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("HumanOrMachine{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
    }
}

///////////////////////////////////////////////////////////////
/// This is the menu where you can select the window appearance.
//////////////////////////////////////////////////////////////
void HumanOrMachine::on_Action_triggered()
{
    if(Action->text()=="Bekapcsol"){
        qApp->setStyleSheet("HumanOrMachine{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
        theme=0;
    }
    else{
        qApp->setStyleSheet("HumanOrMachine{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;
    out.close();
}

HumanOrMachine::~HumanOrMachine()
{
    delete ui;
}

////////////////////////////////////////
/// Play against human
///////////////////////////////////////
void HumanOrMachine::on_pushButton_clicked()
{
    hide();
    Game game;
    game.table(0,0);
    game.show();
    game.exec();
}

////////////////////////////////////////
/// Play against machine
////////////////////////////////////////
void HumanOrMachine::on_pushButton_2_clicked()
{
    hide();
    Difficulty difficulty;
    difficulty.show();
    difficulty.exec();
}

