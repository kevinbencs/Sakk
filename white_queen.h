#ifndef WHITE_QUEEN_H
#define WHITE_QUEEN_H

#include "white_pawn.h"
#include "white_rook.h"


class White_queen: public White_rook, public White_pawn
{
public:
    White_queen();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int* datas);
    void check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn, const int &AttackerRow, const int &AttackerColumn,int &BlackOrWhite,const int &king_row,const int &king_column,int* datas);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int* datas);
    bool get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);
    bool get_draw_CanMove(int *datas);

    void step_machine(int *datas,const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint, const int &row, const int &column);

};

#endif // WHITE_QUEEN_H
