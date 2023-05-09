#ifndef WHITE_PAWN_H
#define WHITE_PAWN_H

#include "game.h"
#include "ui_game.h"
#include "check.h"
#include "white_rook.h"
#include <vector>
#include <iterator>

class White_pawn
{
public:
    White_pawn();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);

    void step_left_up(Ui::Game* ui, const int &row, const int &column);
    void step_left_down(Ui::Game* ui, const int &row, const int &column);
    void step_right_up(Ui::Game* ui, const int &row, const int &column);
    void step_right_down(Ui::Game* ui, const int &row, const int &column);

    void check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite);

    void column_equal_check_step(Ui::Game *ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerRow);
    void row_equal_check_step(Ui::Game *ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn);
    void column_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void column_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void column_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void column_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);

    void row_up_right_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn);
    void row_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);
    void row_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);
    void row_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);

    void dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);

    void down_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void helper_down_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
    void down_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void helper_down_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
    void up_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void helper_up_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);
    void up_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void helper_up_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y);


};

#endif // WHITE_PAWN_H
