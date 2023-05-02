#ifndef WHITE_QUEEN_H
#define WHITE_QUEEN_H

#include "game.h"
#include "ui_game.h"

class White_queen
{
public:
    White_queen();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // WHITE_QUEEN_H
