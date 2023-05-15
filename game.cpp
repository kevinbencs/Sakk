#include "game.h"
#include "ui_game.h"
#include <QFile>
#include <QIcon>
#include <QTableWidgetItem>
#include <fstream>

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{


    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    setWindowIcon(QIcon("Gui/Chess.jpg"));
    for(int i=0;i<8;i++){
        ui->tableWidget->setColumnWidth(i,80);
        ui->tableWidget->setRowHeight(i,80);
    }

    setWindowFlags(Qt::Window);

    menuBar=new QMenuBar();
    menu=new QMenu("Sötét téma");
    Action=new QAction("Bekapcsol");
    menu->addAction(Action);
    menuBar->addMenu(menu);


    this->layout()->setMenuBar(menuBar);

    connect(Action,&QAction::triggered,this,&Game::on_Action_triggered);

    std::ifstream in("Theme");
    in>>theme;

    in.close();

    if(theme==0){
        qApp->setStyleSheet("Game{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
    }
    else{
        qApp->setStyleSheet("Game{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("");
        ui->pushButton_2->setStyleSheet("");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
    }


    for(int i=0;i<8;i++){
        for(int j=0; j<8;j++){
            /*if(i==6){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(1)));
            }
            if(i==1){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(-1)));
            }*/

            if(i==7 && (j==0 || j==7)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(5)));
            }
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
            }*/

            if(i==7 && (j==2 || j==5)){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(3)));
            }
        }
    }

    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(-8)));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(-10)));

    ui->tableWidget->setItem(7,3,new QTableWidgetItem(QString::number(8)));
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


    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ui->tableWidget->item(i,j)->setFlags(Qt::NoItemFlags);
        }
    }



}



void Game::on_Action_triggered()
{
    if(Action->text()=="Bekapcsol"){
        qApp->setStyleSheet("Game{border-color: rgb(19%,19%,19%); background-color: rgb(19%,19%,19%)}");
        ui->pushButton->setStyleSheet(" background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        ui->pushButton_2->setStyleSheet("border-color: rgb(31%,30%,30%); background-color: rgb(31%,30%,30%); color: rgb(80%,80%,80%)");
        Action->setText("Kikapcsol");
        menuBar->setStyleSheet("border-color: rgb(23%,23%,23%); background-color: rgb(23%,23%,23%); color: rgb(80%,80%,80%)");
        theme=0;
    }
    else{
        qApp->setStyleSheet("Game{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
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
                white_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);

            }
            if(KnightAndBishop==0){
                if(piece==5 || ui->tableWidget->item(row,column)->text()=="5"){
                    White_rook white_rook;
                    white_rook.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
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
                    white_rook.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
                }
                if(piece==3 || ui->tableWidget->item(row,column)->text()=="3"){
                    White_pawn white_pawn;
                    white_pawn.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==8 || ui->tableWidget->item(row,column)->text()=="8"){
                    White_queen white_queen;
                    white_queen.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==4 || ui->tableWidget->item(row,column)->text()=="4"){
                    White_knight white_knight;
                    white_knight.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==1 || ui->tableWidget->item(row,column)->text()=="1"){
                    White_bishop white_bishop;
                    white_bishop.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
            }

        }
        else{
            if(piece==-10 || ui->tableWidget->item(row,column)->text()=="-10"){
                Black_king black_king;
                black_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
            }
            if(KnightAndBishop==0){
                if(piece==-5 || ui->tableWidget->item(row,column)->text()=="-5"){
                    Black_rook black_rook;
                    black_rook.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
                }
                if(piece==-3 || ui->tableWidget->item(row,column)->text()=="-3"){
                    Black_pawn black_pawn;
                    black_pawn.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==-8 || ui->tableWidget->item(row,column)->text()=="-8"){
                    Black_queen black_queen;
                    black_queen.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==-4 || ui->tableWidget->item(row,column)->text()=="-4"){
                    Black_knight black_knight;
                    black_knight.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }
                if(piece==-1 || ui->tableWidget->item(row,column)->text()=="-1"){
                    Black_bishop black_bishop;
                    black_bishop.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column);
                }

            }
            else{
                if(piece==-5 || ui->tableWidget->item(row,column)->text()=="-5"){
                    Black_rook black_rook;
                    black_rook.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
                }
                if(piece==-3 || ui->tableWidget->item(row,column)->text()=="-3"){
                    Black_pawn black_pawn;
                    black_pawn.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==-8 || ui->tableWidget->item(row,column)->text()=="-8"){
                    Black_queen black_queen;
                    black_queen.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==-4 || ui->tableWidget->item(row,column)->text()=="-4"){
                    Black_knight black_knight;
                    black_knight.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
                if(piece==-1 || ui->tableWidget->item(row,column)->text()=="-1"){
                    Black_bishop black_bishop;
                    black_bishop.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite);
                }
            }
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
            white_rook.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
        }

        if((piece==-5 || ui->tableWidget->item(row,column)->text()=="-5") && BlackOrWhite==-1){
            Black_rook black_rook;
            black_rook.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
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
            white_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight);
        }

        if((piece==-10 || ui->tableWidget->item(row,column)->text()=="-10") && BlackOrWhite==-1){
            Black_king black_king;
            black_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
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

