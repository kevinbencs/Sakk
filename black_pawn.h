#ifndef BLACK_PAWN_H
#define BLACK_PAWN_H


#include "check.h"
#include <vector>

class Black_pawn
{
public:
    Black_pawn();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
    void check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite);

protected:
    void step_left_up(Ui::Game* ui, const int &row, const int &column);
    void step_left_down(Ui::Game* ui, const int &row, const int &column);
    void step_right_up(Ui::Game* ui, const int &row, const int &column);
    void step_right_down(Ui::Game* ui, const int &row, const int &column);

    void column_equal_check_step(Ui::Game *ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerRow);
    void row_equal_check_step(Ui::Game *ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn);
    void dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);

    void down_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void down_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void up_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void up_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);

private:
    void column_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void column_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void column_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void column_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);

    void row_up_right_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn);
    void row_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);
    void row_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);
    void row_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);

    void helper_down_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
    void helper_down_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
    void helper_up_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
    void helper_up_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
};

#endif // BLACK_PAWN_H
