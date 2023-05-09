#ifndef CHECK_H
#define CHECK_H

#include "game.h"
#include "ui_game.h"
#include "white_king.h"
#include "black_king.h"

class Check
{
public:
    Check();
    bool king_check(Ui::Game* ui, const int &BlackOrWhite, const int &row, const int &column, int &AttackerRow, int &AttackerColumn, int &KnightAndBishop);

    bool white_king_right_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_left_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_down_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_up_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_right_down_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_left_down_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_right_up_check(Ui::Game* ui,const int &row, const int &column);
    bool white_king_left_up_check(Ui::Game* ui,const int &row, const int &column);

    bool black_queen_black_rook_right_check(Ui::Game* ui,const int &row, const int &column);
    bool black_queen_black_rook_left_check(Ui::Game* ui,const int &row, const int &column);
    bool black_queen_black_rook_down_check(Ui::Game* ui,const int &row, const int &column);
    bool black_queen_black_rook_up_check(Ui::Game* ui,const int &row, const int &column);
    bool black_queen_black_pawn_right_up_check(Ui::Game* ui, const int &row, const int &column);
    bool black_queen_black_pawn_right_down_check(Ui::Game* ui, const int &row, const int &column);
    bool black_queen_black_pawn_left_up_check(Ui::Game* ui, const int &row, const int &column);
    bool black_queen_black_pawn_left_down_check(Ui::Game* ui, const int &row, const int &column);

    bool step_white_up_and_down_check(Ui::Game* ui,const int &row, const int &column);
    bool step_white_right_and_left_check(Ui::Game* ui,const int &row, const int &column);
    bool step_white_right_up_and_left_down_check(Ui::Game* ui,const int &row, const int &column);
    bool step_white_left_up_and_right_down_check(Ui::Game* ui,const int &row, const int &column);
    bool step_white_knight_check(Ui::Game* ui,const int &row, const int &column);

};

#endif // CHECK_H
