#include "game.h"
#include "ui_game.h"
#include <QFile>

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    for(int i=0;i<8;i++){
        ui->tableWidget->setColumnWidth(i,80);
        ui->tableWidget->setRowHeight(i,80);
    }

    setWindowFlags(Qt::Window);


    for(int i=0;i<8;i++){
        for(int j=0; j<8;j++){
            if(i==6){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(1)));
            }
            if(i==1){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-1)));
            }

            if(i==7 && (j==0 || j==7)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(5)));
            }
            if(i==0 && (j==0 || j==7)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-5)));
            }

            if(i==0 && (j==1 || j==6)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-4)));
            }

            if(i==7 && (j==1 || j==6)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(4)));
            }

            if(i==0 && (j==2 || j==5)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-3)));
            }

            if(i==7 && (j==2 || j==5)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(3)));
            }
        }
    }

    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(-8)));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(-10)));

    ui->tableWidget->setItem(7,3,new QTableWidgetItem(QString::number(8)));
    ui->tableWidget->setItem(7,4,new QTableWidgetItem(QString::number(10)));


    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(!ui->tableWidget->item(i,j)){
               ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
            }
            if((i+j)%2==0){
                ui->tableWidget->item(i,j)->setBackground(Qt::gray);

            }
        }
    }






}

Game::~Game()
{
    delete ui;
}



void Game::saved_game_load()
{
    QFile in("Saved.txt");
    QTextStream str(&in);
    QString s;

    if(!in.open(QFile::ReadOnly)){
        return;
    }

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            str>>s;
            if(s!="0"){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(s));
            }
            else{
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
            }
            if((i+j)%2==0){
                ui->tableWidget->item(i,j)->setBackground(Qt::black);
            }
        }
    }
    str.flush();
    in.close();
}






void Game::on_tableWidget_cellClicked(int row, int column)
{

    if((piece==1 || ui->tableWidget->item(row,column)->text()=="1") && BlackOrWhite==1){
        White_bishop white_bishop;
        white_bishop.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
    }

    if((piece==-1 || ui->tableWidget->item(row,column)->text()=="-1") && BlackOrWhite==-1){
        Black_bishop black_bishop;
        black_bishop.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
    }

}




//new game
void Game::on_pushButton_clicked()
{
    hide();
    HumanOrMachine humanOrMachine;
    humanOrMachine.show();
    humanOrMachine.exec();
}


//save the game
void Game::on_pushButton_2_clicked()
{
    QFile out("Saved.txt");
    QTextStream str(&out);

    if(!out.open(QFile::WriteOnly)){
        return;
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(ui->tableWidget->item(i,j)->text()==""){
                str<<"0 ";
            }
            else{
                str<<ui->tableWidget->item(i,j)->text()+" ";
            }
        }
        if(i!=7){
            str<<'\n';
        }
    }

    str.flush();
    out.close();
}

