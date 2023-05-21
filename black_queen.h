#ifndef BLACK_QUEEN_H
#define BLACK_QUEEN_H


#include "black_pawn.h"
#include "black_rook.h"

class Black_queen: public Black_rook, public Black_pawn
{
public:
    Black_queen();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas);
    void check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn, const int &AttackerRow, const int &AttackerColumn,int &BlackOrWhite,const int &king_row,const int &king_column,int *datas);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int *datas);
    bool get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);
    bool get_draw_CanMove(int *datas);

};

#endif // BLACK_QUEEN_H
