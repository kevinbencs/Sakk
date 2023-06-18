#ifndef WHITE_MACHINE_H
#define WHITE_MACHINE_H

#include "white_bishop.h"
#include "white_pawn.h"
#include "white_rook.h"
#include "white_knight.h"
#include "white_queen.h"
#include "white_king.h"
#include "black_machine.h"





class White_machine
{
public:
    White_machine();
    //void step(Ui::Game *ui, int *datas, int &BlackOrWhite, int &BlackKingRookDidNotMoveRight, int &BlackKingRookDidNotMoveLeft, int &WhiteKingRookDidNotMoveRight, int &WhiteKingRookDidNotMoveLeft);
    //void step_check(Ui::Game* ui, int* datas, int &BlackOrWhite, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop,int &WhiteKingRookDidNotMoveRight,int &WhiteKingRookDidNotMoveLeft);
    int get_max_point(int* datas,const bool &WhiteKingRookDidNotMoveRight,const bool &WhiteKingRookDidNotMoveLeft);


private:
    std::vector<std::vector<std::vector<int>>> v;
    std::vector<std::vector<std::vector<int>>> v1;
    void make_v(int *datas, int row ,int column,const bool &WhiteKingRookDidNotMoveRight,const bool &WhiteKingRookDidNotMoveLeft);
    //void make_v_check(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, const int &row, const int &column,int &WhiteKingRookDidNotMoveRight,int &WhiteKingRookDidNotMoveLeft);

    //void step_bishop(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    //void step_king(Ui::Game *ui, int *datas, const int &moving, const int &coordinate,int &WhiteKingRookDidNotMoveRight,int &WhiteKingRookDidNotMoveLeft);
    //void step_queen(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    //void step_rook(Ui::Game *ui, int *datas, const int &moving, const int &coordinate, int &WhiteKingRookDidNotMoveRight, int &WhiteKingRookDidNotMoveLeft);
    //void step_pawn(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    //void step_knight(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);

    void max_point_move_search();
    void minimum_point(int *datas, const bool &BlackKingRookDidNotMoveRight,const bool &BlackKingRookDidNotMoveLeft);
    void get_point_of_table(int *datas);
    int get_point_of_table_helper(int* datas, const int &row, const int &column, const int &NewRow, const int &NewColumn);


    const int king1_data[8][8]={
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-30,-40,-40,-50,-50,-40,-40,-30},
        {-20,-30,-30,-40,-40,-30,-30,-20},
        {-10,-20,-20,-20,-20,-20,-20,-10},
        {20, 20,  0,  0,  0,  0, 20, 20},
        {20, 30, 10,  0,  0, 10, 30, 20}
    };
    const int king2_data[8][8]={
        {-50,-40,-30,-20,-20,-30,-40,-50},
        {-30,-20,-10,  0,  0,-10,-20,-30},
        {-30,-10, 20, 30, 30, 20,-10,-30},
        {-30,-10, 30, 40, 40, 30,-10,-30,},
        {-30,-10, 30, 40, 40, 30,-10,-30},
        {-30,-10, 20, 30, 30, 20,-10,-30},
        {-30,-30,  0,  0,  0,  0,-30,-30},
        {-50,-30,-30,-30,-30,-30,-30,-50}
    };
    const int queen_data[8][8]={
        {-20,-10,-10, -5, -5,-10,-10,-20},
        {-10,  0,  0,  0,  0,  0,  0,-10},
        {-10,  0,  5,  5,  5,  5,  0,-10},
        { -5,  0,  5,  5,  5,  5,  0, -5},
        { 0,  0,  5,  5,  5,  5,  0, -5},
        {10,  5,  5,  5,  5,  5,  0,-10},
        {-10,  0,  5,  0,  0,  0,  0,-10},
        {-20,-10,-10, -5, -5,-10,-10,-20}
    };
    const int rook_data[8][8]={
        {0,  0,  0,  0,  0,  0,  0,  0},
        {5, 10, 10, 10, 10, 10, 10,  5},
        {-5,  0,  0,  0,  0,  0,  0, -5},
        {-5,  0,  0,  0,  0,  0,  0, -5},
        {-5,  0,  0,  0,  0,  0,  0, -5},
        {-5,  0,  0,  0,  0,  0,  0, -5},
        {-5,  0,  0,  0,  0,  0,  0, -5},
        {0,  0,  0,  5,  5,  0,  0,  0}
    };
    const int knight_data[8][8]={
        {-50,-40,-30,-30,-30,-30,-40,-50},
        {-40,-20,  0,  0,  0,  0,-20,-40},
        {-30,  0, 10, 15, 15, 10,  0,-30},
        {-30,  5, 15, 20, 20, 15,  5,-30},
        {-30,  0, 15, 20, 20, 15,  0,-30},
        {-30,  5, 10, 15, 15, 10,  5,-30},
        {-40,-20,  0,  5,  5,  0,-20,-40},
        {-50,-40,-30,-30,-30,-30,-40,-50}
    };
    const int pawn_data[8][8]={
        {0,  0,  0,  0,  0,  0,  0,  0},
        {50, 50, 50, 50, 50, 50, 50, 50},
        {10, 10, 20, 30, 30, 20, 10, 10},
        {5,  5, 10, 25, 25, 10,  5,  5},
        {0,  0,  0, 20, 20,  0,  0,  0},
        {5, -5,-10,  0,  0,-10, -5,  5},
        {5, 10, 10,-20,-20, 10, 10,  5},
        {0,  0,  0,  0,  0,  0,  0,  0}
    };
    const int bishop_data[8][8]={
        {-20,-10,-10,-10,-10,-10,-10,-20},
        {-10,  0,  0,  0,  0,  0,  0,-10},
        {-10,  0,  5, 10, 10,  5,  0,-10},
        {-10,  5,  5, 10, 10,  5,  5,-10},
        {-10,  0, 10, 10, 10, 10,  0,-10},
        {-10, 10, 10, 10, 10, 10, 10,-10},
        {-10,  5,  0,  0,  0,  0,  5,-10},
        {-20,-10,-10,-10,-10,-10,-10,-20}
    };
};

#endif // WHITE_MACHINE_H
