#ifndef WHITE_ROOK_H
#define WHITE_ROOK_H

#include "game.h"
#include "ui_game.h"

class White_rook
{
public:
    White_rook();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // WHITE_ROOK_H
