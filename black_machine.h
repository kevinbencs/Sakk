#ifndef BLACK_MACHINE_H
#define BLACK_MACHINE_H

#include "black_bishop.h"
#include "black_pawn.h"
#include "black_knight.h"
#include "black_king.h"
#include "black_rook.h"
#include "black_queen.h"

class Black_machine
{
public:
    Black_machine();
    void step(Ui::Game *ui, int *datas, int &BlackOrWhite);
    void step_check(Ui::Game* ui, int* datas, int &BlackOrWhite, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);


private:
    std::vector<std::vector<std::vector<int>>> v;
    void make_v(int *datas, int i ,int j);
};

#endif // BLACK_MACHINE_H
