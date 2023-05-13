#include "game.h"
#include "ui_game.h"
#include <QFile>
#include <QIcon>
#include <QTableWidgetItem>

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{

    qApp->setStyleSheet("QDialog{border-color: rgb(0, 0, 0); background-color: rgb(21%,20%,20%)}");
    //qApp->setStyleSheet("QDialog{border-color: rgb(0, 0, 0)}");
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    setWindowIcon(QIcon("Gui/Chess.jpg"));
    for(int i=0;i<8;i++){
        ui->tableWidget->setColumnWidth(i,80);
        ui->tableWidget->setRowHeight(i,80);
    }

    setWindowFlags(Qt::Window);


    for(int i=0;i<8;i++){
        for(int j=0; j<8;j++){
            if(i==6){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(1)));
            }/*
            if(i==1){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-1)));
            }

            if(i==7 && (j==0 || j==7)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(5)));
            }*/
            if(i==0 && (j==0 || j==7)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-5)));
            }

            /*if(i==0 && (j==1 || j==6)){
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
            }*/
        }
    }

    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(-8)));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(-10)));

    //ui->tableWidget->setItem(7,3,new QTableWidgetItem(QString::number(8)));
    ui->tableWidget->setItem(7,4,new QTableWidgetItem(QString::number(10)));

   /* QImage* img=new QImage("Gui/black_bishop.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));*/

    //ui->tableWidget->setItem(1,1,picture);




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


   /* for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ui->tableWidget->item(i,j)->setFlags(Qt::NoItemFlags);
        }
    }*/



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
                ui->tableWidget->item(i,j)->setBackground(Qt::gray);
            }
        }
    }
    str>>BlackOrWhite;

    str.flush();
    in.close();
}






void Game::on_tableWidget_cellClicked(int row, int column)
{
    Check check;


    if(ui->label->text()=="<p align=center><span style= font-size:22pt><b>Sakk<b><span><p>"){
        if(BlackOrWhite==1){
            if((piece==10 || ui->tableWidget->item(row,column)->text()=="10")){
                White_king white_king;
                white_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);

            }
            if(KnightAndBishop==0){
                if(piece==5 || ui->tableWidget->item(row,column)->text()=="5"){
                    White_rook white_rook;
                    white_rook.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==3 || ui->tableWidget->item(row,column)->text()=="3"){
                    White_pawn white_pawn;
                    white_pawn.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==8 || ui->tableWidget->item(row,column)->text()=="8"){
                    White_queen white_queen;
                    white_queen.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==4 || ui->tableWidget->item(row,column)->text()=="4"){
                    White_knight white_knight;
                    white_knight.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==1 || ui->tableWidget->item(row,column)->text()=="1"){
                    White_bishop white_bishop;
                    white_bishop.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }

            }
            else{
                if(piece==5 || ui->tableWidget->item(row,column)->text()=="5"){
                    White_rook white_rook;
                    white_rook.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==3 || ui->tableWidget->item(row,column)->text()=="3"){
                    White_pawn white_pawn;
                    white_pawn.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==8 || ui->tableWidget->item(row,column)->text()=="8"){
                    White_queen white_queen;
                    white_queen.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==1 || ui->tableWidget->item(row,column)->text()=="1"){
                    White_bishop white_bishop;
                    white_bishop.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
            }

        }


        if((piece==-10 || ui->tableWidget->item(row,column)->text()=="-10") && BlackOrWhite==-1){
            Black_king black_king;
            black_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }


    }
    else{
        if((piece==1 || ui->tableWidget->item(row,column)->text()=="1") && BlackOrWhite==1){
            White_bishop white_bishop;
            white_bishop.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==-1 || ui->tableWidget->item(row,column)->text()=="-1") && BlackOrWhite==-1){
            Black_bishop black_bishop;
            black_bishop.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==3 || ui->tableWidget->item(row,column)->text()=="3") && BlackOrWhite==1){
            White_pawn white_pawn;
            white_pawn.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==-3 || ui->tableWidget->item(row,column)->text()=="-3") && BlackOrWhite==-1){
            Black_pawn black_pawn;
            black_pawn.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==5 || ui->tableWidget->item(row,column)->text()=="5") && BlackOrWhite==1){
            White_rook white_rook;
            white_rook.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==-5 || ui->tableWidget->item(row,column)->text()=="-5") && BlackOrWhite==-1){
            Black_rook black_rook;
            black_rook.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==8 || ui->tableWidget->item(row,column)->text()=="8") && BlackOrWhite==1){
            White_queen white_queen;
            white_queen.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==-8 || ui->tableWidget->item(row,column)->text()=="-8") && BlackOrWhite==-1){
            Black_queen black_queen;
            black_queen.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==4 || ui->tableWidget->item(row,column)->text()=="4") && BlackOrWhite==1){
            White_knight white_knight;
            white_knight.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==-4 || ui->tableWidget->item(row,column)->text()=="-4") && BlackOrWhite==-1){
            Black_knight black_knight;
            black_knight.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==10 || ui->tableWidget->item(row,column)->text()=="10") && BlackOrWhite==1){
            White_king white_king;
            white_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }

        if((piece==-10 || ui->tableWidget->item(row,column)->text()=="-10") && BlackOrWhite==-1){
            Black_king black_king;
            black_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite);
        }


    }

    if(BlackOrWhite==-1){
        for(int i=0;i<8 ;i++){
            for(int j=0;j<8;j++){
                if(ui->tableWidget->item(i,j)->text()=="-10"){
                    king_column=j;
                    king_row=i;
                }
            }
        }
    }

    if(BlackOrWhite==1){
        for(int i=0;i<8 ;i++){
            for(int j=0;j<8;j++){
                if(ui->tableWidget->item(i,j)->text()=="10"){
                    king_column=j;
                    king_row=i;
                }
            }
        }
    }



    if(check.king_check(ui,BlackOrWhite,king_row,king_column,AttackerRow,AttackerColumn,KnightAndBishop)){
        ui->label->setText("<p align=center><span style= font-size:22pt><b>Sakk<b><span><p>");
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

        str<<'\n';

    }
    str<<BlackOrWhite;

    str.flush();
    out.close();
}

