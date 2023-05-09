#ifndef WHITE_QUEEN_H
#define WHITE_QUEEN_H

#include "game.h"
#include "ui_game.h"
#include "white_pawn.h"
#include "white_rook.h"

class White_queen
{
public:
    White_queen();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
    void check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn, const int &AttackerRow, const int &AttackerColumn,int &BlackOrWhite,const int &king_row,const int &king_column);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite);
};

#endif // WHITE_QUEEN_H
