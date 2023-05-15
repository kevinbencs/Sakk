#ifndef WHITE_ROOK_H
#define WHITE_ROOK_H


#include "check.h"

class White_rook
{
public:
    White_rook();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite, bool &WhiteKingRookDidNotMoveLeft, bool &WhiteKingRookDidNotMoveRight);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn, int &BlackOrWhite, bool &WhiteKingRookDidNotMoveLeft, bool &WhiteKingRookDidNotMoveRight);
    void check_step(Ui::Game* ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn, int &BlackOrWhite, int &king_row, int &king_column, bool &WhiteKingRookDidNotMoveLeft, bool &WhiteKingRookDidNotMoveRight);

protected:
    void king_column_black_queen_rook_column_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow);
    void king_row_black_queen_rook_row_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow);
    void king_dialog_black_queen_pawn_equal_left_down_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column);
    void king_dialog_black_queen_pawn_equal_left_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column);
    void king_dialog_black_queen_pawn_equal_right_down_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column);
    void king_dialog_black_queen_pawn_equal_right_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column);

    void left_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn);
    void right_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn);
    void down_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerRow);
    void up_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerRow);

    void step_up(Ui::Game* ui, const int &row, const int &column, int &piece);
    void step_down(Ui::Game* ui,const int &row, const int &column, int &piece);
    void step_left(Ui::Game* ui, const int &row, const int &column, int &piece);
    void step_right(Ui::Game* ui,const int &row, const int &column,int &piece);
};

#endif // WHITE_ROOK_H
