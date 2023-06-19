#include "white_machine.h"
#include <QFile>
#include <QTextStream>
#include <fstream>







White_machine::White_machine()
{

}


////////////////////////////////
/// Check the possible steps and put them into the vector named v
//////////////////////////////////
void White_machine::make_v(int *datas, int row , int column, const bool &WhiteKingRookDidNotMoveRight, const bool &WhiteKingRookDidNotMoveLeft)
{
    White_bishop white_bishop;
    White_king white_king;
    White_knight white_knight;
    White_pawn white_pawn;
    White_queen white_queen;
    White_rook white_rook;

    std::vector<std::vector<int>> MoveAndPoint;
    std::vector<int> coordinate;
    coordinate.push_back(row);
    coordinate.push_back(column);
    MoveAndPoint.push_back(coordinate);

    switch (*(datas+row*8+column)){
    case 1:
        white_bishop.step_machine(datas, row, column, MoveAndPoint);

        break;
    case 10:
        white_king.step_machine(datas,MoveAndPoint,WhiteKingRookDidNotMoveRight,WhiteKingRookDidNotMoveLeft);

        break;
    case 8:
        white_queen.step_machine(datas,row,column,MoveAndPoint);

        break;
    case 5:
        white_rook.step_machine(datas,row,column,MoveAndPoint);

        break;
    case 3:
        white_pawn.step_machine(datas,row,column,MoveAndPoint);

        break;
    case 4:
        white_knight.step_machine(datas,row,column,MoveAndPoint);

        break;
    }

    if(MoveAndPoint.size()>1){
        v.push_back(MoveAndPoint);
    }
}



///////////////////////////////
/// Search the step which has the max point and put into vector named v1
///////////////////////////////
void White_machine::max_point_move_search()
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
void White_machine::minimum_point(int *datas, const bool &BlackKingRookDidNotMoveRight, const bool &BlackKingRookDidNotMoveLeft)
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
            Black_machine machine;
            v[i][j][2]-=machine.get_max_point(datas1,BlackKingRookDidNotMoveRight,BlackKingRookDidNotMoveLeft);
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
int White_machine::get_point_of_table_helper(int* datas,const int &row, const int &column,const int &NewRow,const int &NewColumn)
{
    int point=0;
    switch (*(datas+row*8+column)) {
    case 1:
        point=bishop_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case 3:
        point=pawn_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case 4:
        point=knight_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case 5:
        point=rook_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case 8:
        point=queen_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    case 10:
        point=king1_data[NewRow][NewColumn]-bishop_data[row][column];
        break;
    }

    return point;
}


void White_machine::get_point_of_table(int *datas)
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
int White_machine::get_max_point(int* datas, const bool &WhiteKingRookDidNotMoveRight, const bool &WhiteKingRookDidNotMoveLeft)
{
    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            make_v(datas,i,j,WhiteKingRookDidNotMoveRight,WhiteKingRookDidNotMoveLeft);
        }
    }

    max_point_move_search();

    return v1[0][1][2];
}

