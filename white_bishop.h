#ifndef WHITE_BISHOP_H
#define WHITE_BISHOP_H

#include "check.h"
#include "ui_game.h"


class White_bishop
{
public:
    White_bishop();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
    void check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn, int &BlackOrWhite);

private:
    void step_up(Ui::Game* ui, const int &row, const int &column);
    void step_up_right(Ui::Game* ui, const int &row, const int &column);
    void step_up_left(Ui::Game* ui, const int &row, const int &column);

    void check_step_move(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow);
    void check_step_move(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,const int &AttackerColumn,const int &AttackerRow);

    void row_equal_check_step(Ui::Game* ui,const int &row,const int &column,const int &king_column,const int &king_row,const int &AttackerColumn);
    void dialog_left_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow);
    void dialog_left_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow);
};

#endif // WHITE_BISHOP_H
