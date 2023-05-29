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
            datas[i*8+j]=0;
            /*if(i==6){
                QImage* img=new QImage("Gui/white_bishop.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);

                datas[i*8+j]=1;

            }
            if(i==1){
                QImage* img=new QImage("Gui/black_bishop.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=-1;

            }*/

            if(i==7 && (j==0 || j==7)){
                QImage* img=new QImage("Gui/white_rook.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=5;
            }
            if(i==0 && (j==0 || j==7)){
                QImage* img=new QImage("Gui/black_rook.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=-5;

            }

            /*if(i==0 && (j==1 || j==6)){
                QImage* img=new QImage("Gui/black_knight.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=-4;

            }*/

            /*if(i==7 && (j==1 || j==6)){
                QImage* img=new QImage("Gui/white_knight.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=4;
            }*/

            if(i==0 && (j==2 || j==5)){
                QImage* img=new QImage("Gui/black_pawn.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=-3;
            }

            if(i==7 && (j==2 || j==5)){
                QImage* img=new QImage("Gui/white_pawn.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=3;
            }

            /*if(i==0 && j==3){
                QImage* img=new QImage("Gui/black_queen.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=-8;
            }*/

            /*if(i==7 && j==3){
                QImage* img=new QImage("Gui/white_queen.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=8;
            }*/

            if(i==7 && j==4){
                QImage* img=new QImage("Gui/white_king.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=10;
            }

            if(i==0 && j==4){
                QImage* img=new QImage("Gui/black_king.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
                datas[i*8+j]=-10;
            }
        }
    }







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
        if(ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Sakk<b><span><p>"){
            ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakk<b><span><p>");
        }
        if(ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>"){
            ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>");
        }
        if(ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>"){
            ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>");
        }
        theme=0;
    }
    else{
        qApp->setStyleSheet("Game{border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%)}");
        ui->pushButton->setStyleSheet("");
        ui->pushButton_2->setStyleSheet("");
        Action->setText("Bekapcsol");
        menuBar->setStyleSheet("border-color: rgb(90%,90%,90%); background-color: rgb(90%,90%,90%); color: rgb(0%,0%,0%)");
        if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Sakk<b><span><p>"){
            ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakk<b><span><p>");
        }
        if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>"){
            ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>");
        }
        if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>"){
            ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>");
        }
        theme=1;
    }

    std::ofstream out("Theme");
    out<<theme;

    out.close();
}



Game::~Game()
{

    delete[] datas;
    delete ui;
}



void Game::saved_game_load()
{
    QFile in("Saved.txt");
    QTextStream str(&in);

    if(!in.open(QFile::ReadOnly)){
        return;
    }

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            str>>datas[i*8+j];
            if(datas[i*8+j]==1){
                QImage* img=new QImage("Gui/white_bishop.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==3){
                QImage* img=new QImage("Gui/white_pawn.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==4){
                QImage* img=new QImage("Gui/white_knight.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==5){
                QImage* img=new QImage("Gui/white_rook.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==8){
                QImage* img=new QImage("Gui/white_queen.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==10){
                QImage* img=new QImage("Gui/white_king.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==-1){
                QImage* img=new QImage("Gui/black_bishop.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==-3){
                QImage* img=new QImage("Gui/black_pawn.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==-4){
                QImage* img=new QImage("Gui/black_knight.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==-5){
                QImage* img=new QImage("Gui/black_rook.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==-8){
                QImage* img=new QImage("Gui/black_queen.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==-10){
                QImage* img=new QImage("Gui/black.png");

                QTableWidgetItem* picture=new QTableWidgetItem;
                picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
                ui->tableWidget->setItem(i,j,picture);
            }
            if(datas[i*8+j]==0){
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(""));
            }

        }
    }



    str>>BlackOrWhite;

    str.flush();
    in.close();

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




bool Game::get_White_CanMove()
{
    White_king white_king;
    White_queen white_queen;
    White_rook white_rook;
    White_pawn white_pawn;
    White_knight white_knight;
    White_bishop white_bishop;

    if(white_rook.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(white_queen.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(white_pawn.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(white_knight.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(white_bishop.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(white_king.get_CanMove(datas)){
        return true;
    }

    return false;
}





bool Game::get_Black_CanMove()
{
    Black_king black_king;
    Black_queen black_queen;
    Black_rook black_rook;
    Black_pawn black_pawn;
    Black_knight black_knight;
    Black_bishop black_bishop;

    if(black_rook.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(black_queen.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(black_pawn.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(black_knight.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(black_bishop.get_checkmate_CanMove(datas,AttackerRow,AttackerColumn,KnightAndBishop)){
        return true;
    }
    if(black_king.get_CanMove(datas)){
        return true;
    }

    return false;
}



bool Game::be_draw_white()
{
    White_king white_king;
    White_queen white_queen;
    White_rook white_rook;
    White_pawn white_pawn;
    White_knight white_knight;
    White_bishop white_bishop;

    if(white_rook.get_draw_CanMove(datas)){
        return true;
    }
    if(white_queen.get_draw_CanMove(datas)){
        return true;
    }
    if(white_pawn.get_draw_CanMove(datas)){
        return true;
    }
    if(white_knight.get_draw_CanMove(datas)){
        return true;
    }
    if(white_bishop.get_draw_CanMove(datas)){
        return true;
    }
    if(white_king.get_CanMove(datas)){
        return true;
    }

    return false;
}



bool Game::be_draw_black()
{
    Black_king black_king;
    Black_queen black_queen;
    Black_rook black_rook;
    Black_pawn black_pawn;
    Black_knight black_knight;
    Black_bishop black_bishop;

    if(black_rook.get_draw_CanMove(datas)){
        return true;
    }
    if(black_queen.get_draw_CanMove(datas)){
        return true;
    }
    if(black_pawn.get_draw_CanMove(datas)){
        return true;
    }
    if(black_knight.get_draw_CanMove(datas)){
        return true;
    }
    if(black_bishop.get_draw_CanMove(datas)){
        return true;
    }
    if(black_king.get_CanMove(datas)){
        return true;
    }

    return false;
}



bool Game::there_is_no_draw_and_checkmatt()
{
    if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>"){
        return false;
    }
    if(ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>"){
        return false;
    }
    if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>"){
        return false;
    }
    if(ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>"){
        return false;
    }

    return true;
}




void Game::on_tableWidget_cellClicked(int row, int column)
{
    Check check;
    Black_machine black_machine;


    if(there_is_no_draw_and_checkmatt()){
        if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Sakk<b><span><p>" || ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Sakk<b><span><p>"){
            if(BlackOrWhite==1){
                if((piece==10 || datas[row*8+column]==10)){
                    White_king white_king;
                    white_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight,datas);

                }
                if(KnightAndBishop==0){
                    if(piece==5 || datas[row*8+column]==5){
                        White_rook white_rook;
                        white_rook.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight,datas);
                    }
                    if(piece==3 || datas[row*8+column]==3){
                        White_pawn white_pawn;
                        white_pawn.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }
                    if(piece==8 || datas[row*8+column]==8){
                        White_queen white_queen;
                        white_queen.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }
                    if(piece==4 || datas[row*8+column]==4){
                        White_knight white_knight;
                        white_knight.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }
                    if(piece==1 || datas[row*8+column]==1){
                        White_bishop white_bishop;
                        white_bishop.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }

                }
                else{
                    if(piece==5 || datas[row*8+column]==5){
                        White_rook white_rook;
                        white_rook.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight,datas);
                    }
                    if(piece==3 || datas[row*8+column]==3){
                        White_pawn white_pawn;
                        white_pawn.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                    if(piece==8 || datas[row*8+column]==8){
                        White_queen white_queen;
                        white_queen.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                    if(piece==4 || datas[row*8+column]==4){
                        White_knight white_knight;
                        white_knight.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                    if(piece==1 || datas[row*8+column]==1){
                        White_bishop white_bishop;
                        white_bishop.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                }

            }
            else{
                if(piece==-10 || datas[row*8+column]==-10){
                    Black_king black_king;
                    black_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft,datas);
                }
                if(KnightAndBishop==0){
                    if(piece==-5 || datas[row*8+column]==-5){
                        Black_rook black_rook;
                        black_rook.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft,datas);
                    }
                    if(piece==-3 || datas[row*8+column]==-3){
                        Black_pawn black_pawn;
                        black_pawn.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }
                    if(piece==-8 || datas[row*8+column]==-8){
                        Black_queen black_queen;
                        black_queen.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }
                    if(piece==-4 || datas[row*8+column]==-4){
                        Black_knight black_knight;
                        black_knight.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }
                    if(piece==-1 || datas[row*8+column]==-1){
                        Black_bishop black_bishop;
                        black_bishop.check_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,king_row,king_column,datas);
                    }

                }
                else{
                    if(piece==-5 || datas[row*8+column]==-5){
                        Black_rook black_rook;
                        black_rook.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft,datas);
                    }
                    if(piece==-3 || datas[row*8+column]==-3){
                        Black_pawn black_pawn;
                        black_pawn.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                    if(piece==-8 || datas[row*8+column]==-8){
                        Black_queen black_queen;
                        black_queen.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                    if(piece==-4 || datas[row*8+column]==-4){
                        Black_knight black_knight;
                        black_knight.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                    if(piece==-1 || datas[row*8+column]==-1){
                        Black_bishop black_bishop;
                        black_bishop.check_knight_and_bishop_step(ui,row,column,piece,OldRow, OldColumn, AttackerRow, AttackerColumn,BlackOrWhite,datas);
                    }
                }
            }

        }
        else{
            if((piece==1 || datas[row*8+column]==1) && BlackOrWhite==1){
                White_bishop white_bishop;
                white_bishop.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==-1 || datas[row*8+column]==-1) && BlackOrWhite==-1){
                Black_bishop black_bishop;
                black_bishop.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==3 || datas[row*8+column]==3) && BlackOrWhite==1){
                White_pawn white_pawn;
                white_pawn.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==-3 || datas[row*8+column]==-3) && BlackOrWhite==-1){
                Black_pawn black_pawn;
                black_pawn.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==5 || datas[row*8+column]==5) && BlackOrWhite==1){
                White_rook white_rook;
                white_rook.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight,datas);
            }

            if((piece==-5 || datas[row*8+column]==-5) && BlackOrWhite==-1){
                Black_rook black_rook;
                black_rook.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft,datas);
            }

            if((piece==8 || datas[row*8+column]==8) && BlackOrWhite==1){
                White_queen white_queen;
                white_queen.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==-8 || datas[row*8+column]==-8) && BlackOrWhite==-1){
                Black_queen black_queen;
                black_queen.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==4 || datas[row*8+column]==4) && BlackOrWhite==1){
                White_knight white_knight;
                white_knight.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==-4 || datas[row*8+column]==-4) && BlackOrWhite==-1){
                Black_knight black_knight;
                black_knight.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas);
            }

            if((piece==10 || datas[row*8+column]==10) && BlackOrWhite==1){
                White_king white_king;
                white_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,WhiteKingRookDidNotMoveLeft,WhiteKingRookDidNotMoveRight,datas);
            }

            if((piece==-10 || datas[row*8+column]==-10) && BlackOrWhite==-1){
                Black_king black_king;
                black_king.step(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft,datas);
            }
        }

        if(BlackOrWhite==-1){
            for(int i=0;i<8 ;i++){
                for(int j=0;j<8;j++){
                    if(*(datas+i*8+j)==-10){
                        king_column=j;
                        king_row=i;
                    }
                }
            }
        }

        if(BlackOrWhite==1){
            for(int i=0;i<8 ;i++){
                for(int j=0;j<8;j++){
                    if(*(datas+i*8+j)==10){
                        king_column=j;
                        king_row=i;
                    }
                }
            }
        }



        if(check.king_check(datas,BlackOrWhite,king_row,king_column,AttackerRow,AttackerColumn,KnightAndBishop)){
            if(theme==0){
                ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakk<b><span><p>");
            }
            else{
                ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakk<b><span><p>");
            }

            //CHECKMATE
            if(BlackOrWhite==1 && !get_White_CanMove()){
                if(theme==0){
                    ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>");
                }
                else{
                    ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>");
                }
            }
            if(BlackOrWhite==-1 && !get_Black_CanMove()){
                if(theme==0){
                    ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>");
                }
                else{
                    ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>");
                }
            }
        }
        else{
            //Draw
            if(BlackOrWhite==1 && !be_draw_white()){
                if(theme==0){
                    ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>");
                }
                else{
                    ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>");
                }
            }
            if(BlackOrWhite==-1 && !be_draw_black()){
                if(theme==0){
                    ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>");
                }
                else{
                    ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>");
                }
            }
        }
    }

    if(there_is_no_draw_and_checkmatt()){
        if(ui->label->text()=="<p align=center><span style= color:white;font-size:22pt><b>Sakk<b><span><p>" || ui->label->text()=="<p align=center><span style= color:black;font-size:22pt><b>Sakk<b><span><p>"){
            if(BlackOrWhite==-1){
                black_machine.step_check(ui,datas,BlackOrWhite,AttackerRow,AttackerColumn,KnightAndBishop);
            }
        }
        else{
            if(BlackOrWhite==-1){
                black_machine.step(ui,datas,BlackOrWhite);
            }
        }
    }


    if(BlackOrWhite==-1){
        for(int i=0;i<8 ;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==-10){
                    king_column=j;
                    king_row=i;
                }
            }
        }
    }

    if(BlackOrWhite==1){
        for(int i=0;i<8 ;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==10){
                    king_column=j;
                    king_row=i;
                }
            }
        }
    }



    if(check.king_check(datas,BlackOrWhite,king_row,king_column,AttackerRow,AttackerColumn,KnightAndBishop)){
        if(theme==0){
            ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakk<b><span><p>");
        }
        else{
            ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakk<b><span><p>");
        }

        //CHECKMATE
        if(BlackOrWhite==1 && !get_White_CanMove()){
            if(theme==0){
                ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>");
            }
            else{
                ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>");
            }
        }
        if(BlackOrWhite==-1 && !get_Black_CanMove()){
            if(theme==0){
                ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Sakkmatt<b><span><p>");
            }
            else{
                ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Sakkmatt<b><span><p>");
            }
        }
    }
    else{
        //Draw
        if(BlackOrWhite==1 && !be_draw_white()){
            if(theme==0){
                ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>");
            }
            else{
                ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>");
            }
        }
        if(BlackOrWhite==-1 && !be_draw_black()){
            if(theme==0){
                ui->label->setText("<p align=center><span style= color:white;font-size:22pt><b>Döntetlen<b><span><p>");
            }
            else{
                ui->label->setText("<p align=center><span style= color:black;font-size:22pt><b>Döntetlen<b><span><p>");
            }
        }
    }


    std::ofstream out("kell.txt");

    for(int i=0;i<64;i++){
        if(i!=0 && i%8==0){
            out<<'\n';
        }
        out<<datas[i]<<' ';
    }
    out.close();

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ui->tableWidget->item(i,j)->setFlags(Qt::NoItemFlags);
        }
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
            if(*(datas+i*8+j)==0){
                str<<"0 ";
            }
            else{
                str<<*(datas+i*8+j)<<" ";
            }
        }

        str<<'\n';

    }
    str<<BlackOrWhite;

    str.flush();
    out.close();
}

