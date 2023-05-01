#ifndef WHITE_BISHOP_H
#define WHITE_BISHOP_H

#include "game.h"
#include "ui_game.h"


class White_bishop
{
public:
    White_bishop();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
};

#endif // WHITE_BISHOP_H
