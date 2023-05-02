#ifndef BLACK_PAWN_H
#define BLACK_PAWN_H

#include "game.h"
#include "ui_game.h"

class Black_pawn
{
public:
    Black_pawn();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // BLACK_PAWN_H
