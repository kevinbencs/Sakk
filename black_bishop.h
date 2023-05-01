#ifndef BLACK_BISHOP_H
#define BLACK_BISHOP_H

#include "game.h"
#include "ui_game.h"

class Black_bishop
{
public:
    Black_bishop();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // BLACK_BISHOP_H
