#ifndef BLACK_ROOK_H
#define BLACK_ROOK_H

#include "game.h"
#include "ui_game.h"

class Black_rook
{
public:
    Black_rook();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // BLACK_ROOK_H
