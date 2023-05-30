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
    std::vector<std::vector<std::vector<int>>> v1;
    void make_v(int *datas, int row ,int column);
    void make_v_check(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, const int &row, const int &column);

    void step_bishop(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    void step_king(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    void step_queen(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    void step_rook(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    void step_pawn(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);
    void step_knight(Ui::Game *ui, int *datas, const int &moving, const int &coordinate);

    void max_point_move_search();
};

#endif // BLACK_MACHINE_H
