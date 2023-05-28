#include "black_machine.h"
#include <ctime>

Black_machine::Black_machine()
{

}




void Black_machine::make_v(int *datas, int row ,int column)
{
    Black_bishop black_bishop;
    Black_king black_king;
    Black_knight black_knight;
    Black_pawn black_pawn;
    Black_queen black_queen;
    Black_rook black_rook;

    switch (*(datas+row*8+column)) {
    case -1:
        std::vector<std::vector<int>> MoveAndPoint;
        std::vector<int> coordinate;
        coordinate.push_back(row);
        coordinate.push_back(column);
        MoveAndPoint.push_back(coordinate);
        black_bishop.step_down_left_machine(datas,row,column,MoveAndPoint);
        black_bishop.step_down_machine(datas,row,column,MoveAndPoint);
        black_bishop.step_down_right_machine(datas,row,column,MoveAndPoint);

        if(MoveAndPoint.size()>1){
            v.push_back(MoveAndPoint);
        }

        break;
    }
}








void Black_machine::step(Ui::Game* ui, int* datas, int &BlackOrWhite)
{
    Check check;
    int moving,coordinate,row,column,t;
    srand(time(0));

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v(datas,i,j);
        }
    }
    moving=rand()%v.size();
    t=v[moving].size();
    coordinate=rand()%(v[moving].size()-1)+1;

    row=v[moving][coordinate][0];
    column=v[moving][coordinate][1];
    datas[row*8+column]=-1;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;


    QImage* img=new QImage("Gui/black_bishop.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(row,column,picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));

    check.green_cell_disappear(ui);
    BlackOrWhite=1;
}







void Black_machine::make_v_check(int *datas, const int &AttackerRow,const int &AttackerColumn,const int &KnightBishop)
{
    Black_bishop black_bishop;
    Black_king black_king;
    Black_knight black_knight;
    Black_pawn black_pawn;
    Black_queen black_queen;
    Black_rook black_rook;


    black_bishop.get_checkmate_CanMove_machine(datas,AttackerRow,AttackerColumn,KnightBishop,v);
}




void Black_machine::step_check(Ui::Game* ui, int* datas, int &BlackOrWhite, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    Check check;
    int moving,coordinate,row,column,t;
    srand(time(0));



    make_v_check(datas, AttackerRow,AttackerColumn, KnightBishop);

    moving=rand()%v.size();
    t=v[moving].size();
    coordinate=rand()%(v[moving].size()-1)+1;

    row=v[moving][coordinate][0];
    column=v[moving][coordinate][1];
    datas[row*8+column]=-1;
    datas[v[moving][0][0]*8+v[moving][0][1]]=0;


    QImage* img=new QImage("Gui/black_bishop.png");

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(row,column,picture);
    ui->tableWidget->setItem(v[moving][0][0],v[moving][0][1],new QTableWidgetItem(""));

    check.green_cell_disappear(ui);
    BlackOrWhite=1;


}



