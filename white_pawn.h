#ifndef WHITE_PAWN_H
#define WHITE_PAWN_H

#include "game.h"
#include "ui_game.h"

class White_pawn
{
public:
    White_pawn();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // WHITE_PAWN_H
