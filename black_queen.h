#ifndef BLACK_QUEEN_H
#define BLACK_QUEEN_H

#include "game.h"
#include "ui_game.h"

class Black_queen
{
public:
    Black_queen();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // BLACK_QUEEN_H
