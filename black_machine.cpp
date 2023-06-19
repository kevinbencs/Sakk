#include "black_machine.h"
#include <ctime>
#include <QFile>
#include <fstream>


///////////////////////////////////////
/// This is the machine
/// First I check there is check
/// After that, I check the possible steps and put them into the vector named v
/// Search which step has the max point (if there are more steps, I select one at random)
///////////////////////////////////////




Black_machine::Black_machine()
{

}

void Black_machine::step_bishop(Ui::Game *ui, int *datas, const int &moving, const int &coordinate,const int &WhiteOrBlackMachine)
{
    QImage* img;
    if(v1[moving][coordinate][0]==7){
        datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-8;
        if(WhiteOrBlackMachine==-1){
            img=new QImage("Gui/white_queen.png");
        }
        else{
            img=new QImage("Gui/black_queen.png");
        }
    }
    else{
        datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-1;
        if(WhiteOrBlackMachine==-1){
            img=new QImage("Gui/white_bishop.png");
        }
        else{
            img=new QImage("Gui/black_bishop.png");
        }
    }


    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;
    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}



void Black_machine::step_king(Ui::Game *ui, int *datas, const int &moving, const int &coordinate, const int &WhiteOrBlackMachine, bool &BlackKingRookDidNotMoveRight, bool &BlackKingRookDidNotMoveLeft)
{
    QImage* img;
    QImage *img2;
    QTableWidgetItem* picture2;

    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-10;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/white_king.png");
    }
    else{
        img=new QImage("Gui/black_king.png");
    }

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));

    if(v1[moving][coordinate][0]==0 && v1[moving][coordinate][1]==6 && BlackKingRookDidNotMoveRight){
        datas[5]=-5;
        datas[7]=0;
        if(WhiteOrBlackMachine==-1){
            img2=new QImage("Gui/white_rook.png");
        }
        else{
            img2=new QImage("Gui/black_rook.png");
        }
        picture2=new QTableWidgetItem;
        picture2->setData(Qt::DecorationRole, QPixmap::fromImage(*img2).scaled(70,70));
        ui->tableWidget->setItem(0,5,picture2);
        ui->tableWidget->setItem(0,7,new QTableWidgetItem(""));
    }

    if(v1[moving][coordinate][0]==0 && v1[moving][coordinate][1]==2 && BlackKingRookDidNotMoveRight){
        datas[3]=-5;
        datas[0]=0;
        if(WhiteOrBlackMachine==-1){
            img2=new QImage("Gui/white_rook.png");
        }
        else{
            img2=new QImage("Gui/black_rook.png");
        }
        picture2=new QTableWidgetItem;
        picture2->setData(Qt::DecorationRole, QPixmap::fromImage(*img2).scaled(70,70));
        ui->tableWidget->setItem(0,3,picture2);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(""));
    }



    BlackKingRookDidNotMoveLeft=false;
    BlackKingRookDidNotMoveRight=false;
}





void Black_machine::step_queen(Ui::Game *ui, int *datas, const int &moving, const int &coordinate,const int &WhiteOrBlackMachine)
{
    QImage* img;

    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-8;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/white_queen.png");
    }
    else{
        img=new QImage("Gui/black_queen.png");
    }



    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}


void Black_machine::step_rook(Ui::Game *ui, int *datas, const int &moving, const int &coordinate, const int &WhiteOrBlackMachine,bool &BlackKingRookDidNotMoveRight,bool &BlackKingRookDidNotMoveLeft)
{
    QImage* img;

    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-5;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/white_rook.png");
    }
    else{
        img=new QImage("Gui/black_rook.png");
    }

    if(v1[moving][0][1]==7 && v1[moving][0][0]==0){
        BlackKingRookDidNotMoveLeft=false;
    }
    if(v1[moving][0][1]==0 && v1[moving][0][0]==0){
        BlackKingRookDidNotMoveRight=false;
    }


    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}



void Black_machine::step_pawn(Ui::Game *ui, int *datas, const int &moving, const int &coordinate,const int &WhiteOrBlackMachine)
{
    QImage* img;

    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-3;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/white_pawn.png");
    }
    else{
        img=new QImage("Gui/black_pawn.png");
    }



    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}


void Black_machine::step_knight(Ui::Game *ui, int *datas, const int &moving, const int &coordinate, const int &WhiteOrBlackMachine)
{
    QImage* img;
    datas[v1[moving][coordinate][0]*8+v1[moving][coordinate][1]]=-4;
    datas[v1[moving][0][0]*8+v1[moving][0][1]]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/white_knight.png");
    }
    else{
        img=new QImage("Gui/black_knight.png");
    }



    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(v1[moving][coordinate][0],v1[moving][coordinate][1],picture);
    ui->tableWidget->setItem(v1[moving][0][0],v1[moving][0][1],new QTableWidgetItem(""));
}




////////////////////////////////
/// Check the possible steps and put them into the vector named v
//////////////////////////////////
void Black_machine::make_v(int *datas, int row , int column, const bool &BlackKingRookDidNotMoveRight, const bool &BlackKingRookDidNotMoveLeft)
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
        black_king.step_machine(datas,MoveAndPoint,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);

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



///////////////////////////////
/// Search the step which has the max point and put into vector named v1
///////////////////////////////
void Black_machine::max_point_move_search()
{
    int max=-1000;
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




/////////////////////////////////////
/// Search the max point of the opponent's step
/////////////////////////////////////
void Black_machine::minimum_point(int *datas, const bool &WhiteKingRookDidNotMoveRight, const bool &WhiteKingRookDidNotMoveLeft)
{
    int *datas1=new int[64];
    int f;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            *(datas1+i*8+j)=*(datas+i*8+j);
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            f=*(datas1+v[i][j][0]*8+v[i][j][1]);
            *(datas1+v[i][j][0]*8+v[i][j][1])=*(datas1+v[i][0][0]*8+v[i][0][1]);
            *(datas1+v[i][0][0]*8+v[i][0][1])=0;
            White_machine machine;
            v[i][j][2]-=machine.get_max_point(datas1,WhiteKingRookDidNotMoveRight,WhiteKingRookDidNotMoveLeft);
            *(datas1+v[i][0][0]*8+v[i][0][1])=*(datas1+v[i][j][0]*8+v[i][j][1]);
            *(datas1+v[i][j][0]*8+v[i][j][1])=f;
        }
    }

    delete [] datas1;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
/// The cells of table have point too
/// (because e.g. a knight on the center of the board is better, than a knight on the edge of the board.)
////////////////////////////////////////////////////////////////////////////////////////////////////
int Black_machine::get_point_of_table_helper(int* datas,const int &row, const int &column,const int &NewRow,const int &NewColumn)
{
    int point=0;
    int z=0;
    switch (*(datas+row*8+column)) {
    case -1:
        point=bishop_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case -3:
        point=pawn_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case -4:
        point=knight_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case -5:
        point=rook_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case -8:
        point=queen_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case -10:
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)!=0){
                    z++;
                }
            }
        }
        if(z>12){
            point=king1_data[NewRow][NewColumn]-bishop_data[row][column];
        }
        else{
            point=king2_data[NewRow][NewColumn]-bishop_data[row][column];
        }
        break;
    }

    return point;
}


void Black_machine::get_point_of_table(int *datas)
{
    for(int i=0;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            v[i][j][2]+=get_point_of_table_helper(datas,v[i][0][0],v[i][0][1],v[i][j][0],v[i][j][1]);
        }
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////
/// It is need in the minimum_point function of white machine "Search the max point of the opponent's step "
/////////////////////////////////////////////////////////////////////////////////////////////////
int Black_machine::get_max_point(int* datas, const int &BlackKingRookDidNotMoveRight, const int &BlackKingRookDidNotMoveLeft)
{
    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v(datas,i,j,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }
    }

    max_point_move_search();

    return v1[0][1][2];
}



void Black_machine::step(Ui::Game* ui, int* datas, int &BlackOrWhite, const int &WhiteOrBlackMachine, bool &BlackKingRookDidNotMoveRight, bool &BlackKingRookDidNotMoveLeft, const bool &WhiteKingRookDidNotMoveRight, const bool &WhiteKingRookDidNotMoveLeft)
{
    Check check;
    int moving,coordinate,t;
    srand(time(0));

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v(datas,i,j,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }
    }



    minimum_point(datas,WhiteKingRookDidNotMoveRight,WhiteKingRookDidNotMoveRight);

    QFile fout("f.txt");

    if(!fout.open(QFile::WriteOnly)){
        return;
    }

    QTextStream str(&fout);

    for(int i=0;i<v[0].size();i++){
        for(int j=0;j<v[0][i].size();j++){
            str<<v[0][i][j]<<" ";
        }
        str<<'\n';
    }
    str.flush();
    fout.close();

    get_point_of_table(datas);
    max_point_move_search();

    moving=rand()%v1.size();
    t=v1[moving].size();
    if(v1[moving].size()-1>0){
        coordinate=rand()%(v1[moving].size()-1)+1;

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-1){
            step_bishop(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-5){
            step_rook(ui,datas,moving,coordinate,WhiteOrBlackMachine,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-10){
            step_king(ui,datas,moving,coordinate,WhiteOrBlackMachine,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-8){
            step_queen(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-3){
            step_pawn(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-4){
            step_knight(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        check.green_cell_disappear(ui);
        BlackOrWhite=1;
    }

}







void Black_machine::make_v_check(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, const int &row, const int &column, const bool &BlackKingRookDidNotMoveRight, const bool &BlackKingRookDidNotMoveLeft)
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
        black_king.step_machine(datas,MoveAndPoint,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);

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






void Black_machine::step_check(Ui::Game* ui, int* datas, int &BlackOrWhite, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, const int &WhiteOrBlackMachine, bool &BlackKingRookDidNotMoveRight, bool &BlackKingRookDidNotMoveLeft, const bool &WhiteKingRookDidNotMoveRight, const bool &WhiteKingRookDidNotMoveLeft)
{
    Check check;
    int moving,coordinate,t;
    srand(time(0));

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v_check(datas, AttackerRow,AttackerColumn, KnightBishop,i,j,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }
    }
    minimum_point(datas,WhiteKingRookDidNotMoveRight,WhiteKingRookDidNotMoveLeft);
    max_point_move_search();

    moving=rand()%v1.size();
    t=v1[moving].size();
    if(v1[moving].size()-1>0){
        coordinate=rand()%(v1[moving].size()-1)+1;

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-1){
            step_bishop(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-5){
            step_rook(ui,datas,moving,coordinate,WhiteOrBlackMachine,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-10){
            step_king(ui,datas,moving,coordinate,WhiteOrBlackMachine,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-8){
            step_queen(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-3){
            step_pawn(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        if(datas[v1[moving][0][0]*8+v1[moving][0][1]]==-4){
            step_knight(ui,datas,moving,coordinate,WhiteOrBlackMachine);
        }

        check.green_cell_disappear(ui);
        BlackOrWhite=1;

        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
}



