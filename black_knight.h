#ifndef BLACK_KNIGHT_H
#define BLACK_KNIGHT_H

#include "game.h"
#include "ui_game.h"

class Black_knight
{
public:
    Black_knight();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // BLACK_KNIGHT_H
