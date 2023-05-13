#ifndef WHITE_KNIGHT_H
#define WHITE_KNIGHT_H

#include "check.h"

//class Check;

class White_knight{
public:
    White_knight();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite);
    void check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn,const int &AttackerRow, const int &AttackerColumn, int &BlackOrWhite,const int &king_row,const int &king_column);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite);

    void step_1(Ui::Game* ui, const int &row, const int &column);
    void step_2(Ui::Game* ui, const int &row, const int &column);
    void step_3(Ui::Game* ui, const int &row, const int &column);
    void step_4(Ui::Game* ui, const int &row, const int &column);
    void step_5(Ui::Game* ui, const int &row, const int &column);
    void step_6(Ui::Game* ui, const int &row, const int &column);
    void step_7(Ui::Game* ui, const int &row, const int &column);
    void step_8(Ui::Game* ui, const int &row, const int &column);

    void column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow);
    void row_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn);
    void dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);
    void dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow);

    void step_1_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_2_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_3_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_4_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_5_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_6_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_7_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);
    void step_8_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v);

};

#endif // WHITE_KNIGHT_H
