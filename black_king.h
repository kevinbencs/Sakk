#ifndef BLACK_KING_H
#define BLACK_KING_H


#include "ui_game.h"

class Black_king
{
public:
    Black_king();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
    bool there_is_no_white_bishop(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_knight(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_left(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_right(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_up(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_down(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_up_right(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_up_left(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_down_right(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_down_left(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_king(Ui::Game* ui,const int &row, const int &column);

    bool there_is_no_white_bishop(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_knight(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_left(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_right(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_up(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_down(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_up_right(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_up_left(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_down_right(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_down_left(Ui::Game* ui, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn(Ui::Game* ui,const int &row, const int &column);
    bool there_is_no_white_king(Ui::Game* ui,const int &row);

    void step_1(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_2(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_3(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_4(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_5(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_6(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_7(Ui::Game *ui, const int &row, const int &column,  int &piece);
    void step_8(Ui::Game *ui, const int &row, const int &column,  int &piece);
};

#endif // BLACK_KING_H
