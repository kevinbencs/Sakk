#include "white_or_black.h"
#include "ui_white_or_black.h"
#include <fstream>
#include <ctime>


//////////////////////////////////////////////////
/// Select the color (white or black) when you play against thw machine
//////////////////////////////////////////////////


White_or_black::White_or_black(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::White_or_black)
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
    connect(Action,&QAction::triggered,this,&White_or_black::on_Action_triggered);

    ///////////////////////////////////////////////////////////////
    /// Loading the theme of appearance
    //////////////////////////////////////////////////////////////

    std::ifstream in("Theme");
    in>>theme;
    in.close();

    if(theme==0){
        qApp->setStyleSheet("White_or_black{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_3->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->label->setText("<p align=center><span style= color:white;font-size:24pt><b>Melyik szeretnél lenni:<b><span><p>");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("White_or_black{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_3->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->label->setText("<p align=center><span style= color:black;font-size:24pt><b>Melyik szeretnél lenni:<b><span><p>");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
    }
}


///////////////////////////////////////////////////////////////
/// This is the menu where you can select the window appearance.
///////////////////////////////////////////////////////////////
void White_or_black::on_Action_triggered()
{
    if(Action->text()=="Bekapcsol"){
        qApp->setStyleSheet("White_or_black{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_3->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->label->setText("<p align=center><span style= color:white;font-size:24pt><b>Melyik szeretnél lenni:<b><span><p>");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
        theme=0;
    }
    else{
        qApp->setStyleSheet("White_or_black{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_2->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->pushButton_3->setStyleSheet("border-color: rgb(81%,80%,80%); background-color: rgb(81%,80%,80%); color: black");
        ui->label->setText("<p align=center><span style= color:black;font-size:24pt><b>Melyik szeretnél lenni:<b><span><p>");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;
    out.close();
}



void White_or_black::set_difficulty_level(int difficulty_level)
{
    this->difficulty_level=difficulty_level;
}


White_or_black::~White_or_black()
{
    delete ui;
}

/////////////////////////
/// Select the white pieces
/////////////////////////
void White_or_black::on_pushButton_clicked()
{
    hide();
    Game game;
    game.table(difficulty_level,1);
    game.show();
    game.exec();
}

/////////////////////////
/// Select the black pieces
/////////////////////////
void White_or_black::on_pushButton_2_clicked()
{
    Game game;
    hide();
    game.table(difficulty_level,-1);
    game.show();
    game.exec();
}

/////////////////////////
/// Random choice
/////////////////////////
void White_or_black::on_pushButton_3_clicked()
{
    Game game;
    hide();
    srand(time(0));
    if(rand()%2==1){
        game.table(difficulty_level,1);
    }
    else{
        game.table(difficulty_level,-1);
    }
    game.show();
    game.exec();
}

