#ifndef CHECK_H
#define CHECK_H

#include "white_king.h"
#include "black_king.h"

class Check
{
public:
    Check();
    bool king_check(int *datas, const int &BlackOrWhite, const int &row, const int &column, int &AttackerRow, int &AttackerColumn, int &KnightAndBishop);

    bool white_king_right_check(int *datas, const int &row, const int &column);
    bool white_king_left_check(int *datas,const int &row, const int &column);
    bool white_king_down_check(int *datas, const int &row, const int &column);
    bool white_king_up_check(int *datas, const int &row, const int &column);
    bool white_king_right_down_check(int *datas, const int &row, const int &column);
    bool white_king_left_down_check(int *datas, const int &row, const int &column);
    bool white_king_right_up_check(int *datas, const int &row, const int &column);
    bool white_king_left_up_check(int *datas, const int &row, const int &column);

    bool black_queen_black_rook_right_check(int *datas, const int &row, const int &column);
    bool black_queen_black_rook_left_check(int *datas, const int &row, const int &column);
    bool black_queen_black_rook_down_check(int *datas, const int &row, const int &column);
    bool black_queen_black_rook_up_check(int *datas,const int &row, const int &column);
    bool black_queen_black_pawn_right_up_check(int *datas, const int &row, const int &column);
    bool black_queen_black_pawn_right_down_check(int *datas, const int &row, const int &column);
    bool black_queen_black_pawn_left_up_check(int *datas, const int &row, const int &column);
    bool black_queen_black_pawn_left_down_check(int *datas, const int &row, const int &column);

    bool step_white_up_and_down_check(int *datas, const int &row, const int &column);
    bool step_white_right_and_left_check(int *datas,const int &row, const int &column);
    bool step_white_right_up_and_left_down_check(int *datas,const int &row, const int &column);
    bool step_white_left_up_and_right_down_check(int *datas,const int &row, const int &column);
    bool step_white_knight_check(int *datas,const int &row, const int &column);

    bool black_king_right_check(int *datas, const int &row, const int &column);
    bool black_king_left_check(int *datas, const int &row, const int &column);
    bool black_king_down_check(int *datas,const int &row, const int &column);
    bool black_king_up_check(int *datas, const int &row, const int &column);
    bool black_king_right_down_check(int *datas,const int &row, const int &column);
    bool black_king_left_down_check(int *datas, const int &row, const int &column);
    bool black_king_right_up_check(int *datas,const int &row, const int &column);
    bool black_king_left_up_check(int *datas, const int &row, const int &column);

    bool white_queen_black_rook_right_check(int *datas,const int &row, const int &column);
    bool white_queen_black_rook_left_check(int *datas, const int &row, const int &column);
    bool white_queen_black_rook_down_check(int *datas,const int &row, const int &column);
    bool white_queen_black_rook_up_check(int *datas, const int &row, const int &column);
    bool white_queen_black_pawn_right_up_check(int *datas, const int &row, const int &column);
    bool white_queen_black_pawn_right_down_check(int *datas, const int &row, const int &column);
    bool white_queen_black_pawn_left_up_check(int *datas, const int &row, const int &column);
    bool white_queen_black_pawn_left_down_check(int *datas, const int &row, const int &column);

    bool step_black_up_and_down_check(int *datas,const int &row, const int &column);
    bool step_black_right_and_left_check(int *datas,const int &row, const int &column);
    bool step_black_right_up_and_left_down_check(int *datas,const int &row, const int &column);
    bool step_black_left_up_and_right_down_check(int *datas,const int &row, const int &column);
    bool step_black_knight_check(int *datas,const int &row, const int &column);

    void green_cell_disappear(Ui::Game* ui);
    bool check_check(int *datas, const int &row, const int &column, const int &piece, const int &OldRow, const int &OldColumn);
    void look_for_the_kings(int *datas, const int &BlackOrWhite, int &king_row, int &king_column);
    int occupying_an_white_piece(int *datas, const int &row, const int &column);
    int occupying_an_black_piece(int *datas, const int &row, const int &column);

};

#endif // CHECK_H
