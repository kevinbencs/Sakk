#include "black_machine.h"
#include <ctime>

Black_machine::Black_machine()
{

}





void Black_machine::step_bishop(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    QImage* img;
    if(v1[moving][coordinate][0]==7){
        datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-8;
        img=new QImage("Gui/black_queen.png");
    }
    else{
        datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-1;
        img=new QImage("Gui/black_bishop.png");
    }


    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;
    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}




void Black_machine::step_king(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-10;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_king.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}





void Black_machine::step_queen(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-8;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_queen.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}


void Black_machine::step_rook(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-5;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_rook.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}



void Black_machine::step_pawn(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-3;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_pawn.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}


void Black_machine::step_knight(Ui::Game *ui, int *datas, const int &moving, const int &coordinate)
{
    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-4;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    QImage* img=new QImage("Gui/black_knight.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
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
        black_bishop.step_machine(datas,row,column,MoveAndPoint);

        break;
    case -10:
        black_king.step_machine(datas,MoveAndPoint);

        break;
    case -8:
        black_queen.step_machine(datas,row,column,MoveAndPoint);

        break;
    case -5:
        black_rook.step_machine(datas,row,column,MoveAndPoint);

        break;
    case -3:
        black_pawn.step_machine(datas,row,column,MoveAndPoint);

        break;
    case -4:
        black_knight.step_machine(datas,row,column,MoveAndPoint);

        break;
    }

    if(MoveAndPoint.size()>1){
        v.push_back(MoveAndPoint);
    }
}




void Black_machine::max_point_move_search()
{
    int max=-1;
    std::vector<std::vector<int>> MoveAndPoint;
    std::vector<int> coordinate;

    MoveAndPoint.push_back(coordinate);
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            if(v[i][j][2]>max){
                max=v[i][j][2];
                coordinate.clear();
                MoveAndPoint.clear();
                v1.clear();
                coordinate.push_back(v[i][0][0]);
                coordinate.push_back(v[i][0][1]);
                MoveAndPoint.push_back(coordinate);

                coordinate.clear();

                coordinate.push_back(v[i][j][0]);
                coordinate.push_back(v[i][j][1]);
                coordinate.push_back(v[i][j][2]);
                MoveAndPoint.push_back(coordinate);
                v1.push_back(MoveAndPoint);

            }
            else{
                if(v[i][j][2]==max){
                    if(v[i][0][0]==MoveAndPoint[0][0] && v[i][0][1]==MoveAndPoint[0][1]){
                        coordinate.clear();
                        coordinate.push_back(v[i][j][0]);
                        coordinate.push_back(v[i][j][1]);
                        coordinate.push_back(v[i][j][2]);
                        MoveAndPoint.push_back(coordinate);
                        v1.pop_back();
                        v1.push_back(MoveAndPoint);
                        coordinate.clear();
                    }
                    else{
                        coordinate.clear();
                        MoveAndPoint.clear();
                        coordinate.push_back(v[i][0][0]);
                        coordinate.push_back(v[i][0][1]);
                        MoveAndPoint.push_back(coordinate);

                        coordinate.clear();

                        coordinate.push_back(v[i][j][0]);
                        coordinate.push_back(v[i][j][1]);
                        coordinate.push_back(v[i][j][2]);
                        MoveAndPoint.push_back(coordinate);
                        v1.push_back(MoveAndPoint);
                        coordinate.clear();
                    }
                }
            }
        }
    }
}





void Black_machine::minimum_point(int *datas)
{
    White_machine machine;
    int *datas1=new int[64];
    int z;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            *(datas1+i*8+j)=*(datas+i*8+j);
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            *(datas1+v[i][j][0]*8+v[i][j][1])=*(datas1+v[i][0][0]*8+v[i][0][1]);
            *(datas1+v[i][0][0]*8+v[i][0][1])=0;
            z=machine.get_max_point(datas1);
            v[i][j][2]-=z;
            *(datas1+v[i][0][0]*8+v[i][0][1])=*(datas1+v[i][j][0]*8+v[i][j][1]);
            *(datas1+v[i][j][0]*8+v[i][j][1])=0;
        }
    }

    delete [] datas1;
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
    minimum_point(datas);
    max_point_move_search();

    moving=rand()%v1.size();
    t=v1[moving].size();
    if(v1[moving].size()-1>0){
        coordinate=rand()%(v1[moving].size()-1)+1;

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-1){
            step_bishop(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-10){
            step_king(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-8){
            step_queen(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-5){
            step_rook(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-3){
            step_pawn(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-4){
            step_knight(ui,datas,moving,coordinate);
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
    case -8:
        black_queen.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;
    case -5:
        black_rook.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;
    case -3:
        black_pawn.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

        break;
    case -4:
        black_knight.step_check_machine(datas,AttackerRow,AttackerColumn,KnightBishop,MoveAndPoint,row,column);

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
    minimum_point(datas);
    max_point_move_search();

    moving=rand()%v1.size();
    t=v1[moving].size();
    if(v1[moving].size()-1>0){
        coordinate=rand()%(v1[moving].size()-1)+1;

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-1){
            step_bishop(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-10){
            step_king(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-8){
            step_queen(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-5){
            step_rook(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-3){
            step_pawn(ui,datas,moving,coordinate);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-4){
            step_knight(ui,datas,moving,coordinate);
        }

        check.green_cell_disappear(ui);
        BlackOrWhite=1;

        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
}



