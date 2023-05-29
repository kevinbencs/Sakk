#include "black_machine.h"
#include <ctime>

Black_machine::Black_machine()
{

}





void Black_machine::step_bishop(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v[moving][coordinate][0]*8+v[moving][coordinate][1]]=-1;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_bishop.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v[moving][coordinate][0],v[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));
}




void Black_machine::step_king(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v[moving][coordinate][0]*8+v[moving][coordinate][1]]=-10;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_king.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v[moving][coordinate][0],v[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));
}





void Black_machine::step_queen(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v[moving][coordinate][0]*8+v[moving][coordinate][1]]=-8;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_queen.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v[moving][coordinate][0],v[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));
}


void Black_machine::step_rook(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v[moving][coordinate][0]*8+v[moving][coordinate][1]]=-5;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_rook.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v[moving][coordinate][0],v[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));
}



void Black_machine::step_pawn(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v[moving][coordinate][0]*8+v[moving][coordinate][1]]=-3;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_pawn.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v[moving][coordinate][0],v[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));
}


void Black_machine::make_v(int *datas, int row ,int column)
{
    Black_bishop black_bishop;
    Black_king black_king;
    Black_knight black_knight;
    Black_pawn black_pawn;
    Black_queen black_queen;
    Black_rook black_rook;

    std::vector<std::vector<int>> MoveAndPoint;
    std::vector<int> coordinate;
    coordinate.push_back(row);
    coordinate.push_back(column);
    MoveAndPoint.push_back(coordinate);

    switch (*(datas+row*8+column)){
    case -1:
        black_bishop.step_down_left_machine(datas,row,column,MoveAndPoint);
        black_bishop.step_down_machine(datas,row,column,MoveAndPoint);
        black_bishop.step_down_right_machine(datas,row,column,MoveAndPoint);

        break;
    case -10:
        black_king.step_machine(datas,MoveAndPoint);

        break;
    /*case -8:
        black_queen.step_machine(datas,row,column,MoveAndPoint);

        break;*/
    case -5:
        black_rook.step_machine(datas,row,column,MoveAndPoint);

        break;
    case -3:
        black_pawn.step_machine(datas,row,column,MoveAndPoint);

        break;
    }

    if(MoveAndPoint.size()>1){
        v.push_back(MoveAndPoint);
    }
}




void Black_machine::step(Ui::Game* ui, int* datas, int &BlackOrWhite)
{
    Check check;
    int moving,coordinate,t;
    srand(time(0));

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v(datas,i,j);
        }
    }

    moving=rand()%v.size();
    t=v[moving].size();
    if(v[moving].size()-1>0){
        coordinate=rand()%(v[moving].size()-1)+1;

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-1){
            step_bishop(ui,datas,moving,coordinate);
        }

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-10){
            step_king(ui,datas,moving,coordinate);
        }

        /*if(datas[v[moving][0][0]*8+v[moving][0][1]]==-8){
            step_queen(ui,datas,moving,coordinate);
        }*/

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-5){
            step_rook(ui,datas,moving,coordinate);
        }

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-3){
            step_pawn(ui,datas,moving,coordinate);
        }

        check.green_cell_disappear(ui);
        BlackOrWhite=1;
    }
}







void Black_machine::make_v_check(int *datas, const int &AttackerRow,const int &AttackerColumn,const int &KnightBishop,const int &row, const int &column)
{
    Black_bishop black_bishop;
    Black_king black_king;
    Black_knight black_knight;
    Black_pawn black_pawn;
    Black_queen black_queen;
    Black_rook black_rook;


    std::vector<std::vector<int>> MoveAndPoint;
    std::vector<int> coordinate;
    coordinate.push_back(row);
    coordinate.push_back(column);
    MoveAndPoint.push_back(coordinate);

    switch (*(datas+row*8+column)){
    case -1:
        black_bishop.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;
    case -10:
        black_king.step_machine(datas,MoveAndPoint);

        break;
    /*case -8:
        black_queen.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;*/
    case -5:
        black_rook.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;
    case -3:
        black_pawn.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;
    }

    if(MoveAndPoint.size()>1){
        v.push_back(MoveAndPoint);
    }
}




void Black_machine::step_check(Ui::Game* ui, int* datas, int &BlackOrWhite, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    Check check;
    int moving,coordinate,t;
    srand(time(0));

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v_check(datas, AttackerRow,AttackerColumn, KnightBishop,i,j);
        }
    }


    moving=rand()%v.size();
    t=v[moving].size();
    if(v[moving].size()-1>0){
        coordinate=rand()%(v[moving].size()-1)+1;

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-1){
            step_bishop(ui,datas,moving,coordinate);
        }

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-10){
            step_king(ui,datas,moving,coordinate);
        }

        /*if(datas[v[moving][0][0]*8+v[moving][0][1]]==-8){
            step_queen(ui,datas,moving,coordinate);
        }*/

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-5){
            step_rook(ui,datas,moving,coordinate);
        }

        if(datas[v[moving][0][0]*8+v[moving][0][1]]==-3){
            step_pawn(ui,datas,moving,coordinate);
        }

        check.green_cell_disappear(ui);
        BlackOrWhite=1;

        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
}



