#ifndef WHITE_KNIGHT_H
#define WHITE_KNIGHT_H

#include "game.h"
#include "ui_game.h"

class White_knight
{
public:
    White_knight();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // WHITE_KNIGHT_H
