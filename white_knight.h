#ifndef WHITE_KNIGHT_H
#define WHITE_KNIGHT_H

#include "game.h"
#include "ui_game.h"
#include "check.h"
#include "white_rook.h"

class White_knight
{
public:
    White_knight();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
    void check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn,const int &AttackerRow, const int &AttackerColumn, int &BlackOrWhite,const int &king_row,const int &king_column);

    void step_1(Ui::Game* ui, const int &row, const int &column);
    void step_2(Ui::Game* ui, const int &row, const int &column);
    void step_3(Ui::Game* ui, const int &row, const int &column);
    void step_4(Ui::Game* ui, const int &row, const int &column);
    void step_5(Ui::Game* ui, const int &row, const int &column);
    void step_6(Ui::Game* ui, const int &row, const int &column);
    void step_7(Ui::Game* ui, const int &row, const int &column);
    void step_8(Ui::Game* ui, const int &row, const int &column);
};

#endif // WHITE_KNIGHT_H
