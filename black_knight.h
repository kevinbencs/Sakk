#ifndef BLACK_KNIGHT_H
#define BLACK_KNIGHT_H


#include "check.h"

class Black_knight
{
public:
    Black_knight();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas);
    void check_step(Ui::Game* ui,const int &row,const int &column, int &piece, int &OldRow, int &OldColumn,const int &AttackerRow, const int &AttackerColumn, int &BlackOrWhite,const int &king_row,const int &king_column,int *datas);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int *datas);
    bool get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);
    bool get_draw_CanMove(int *datas);

    void step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop,std::vector<std::vector<int>> &MoveAndPoint,const int &row,const int &column);
    void step_machine(int *datas,const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);

private:
    void step_1(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_2(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_3(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_4(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_5(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_6(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_7(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_8(Ui::Game* ui, const int &row, const int &column,int *datas);

    void column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas);
    void row_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,int *datas);
    void dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);
    void dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);
    void dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);
    void dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);

    void step_1_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_2_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_3_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_4_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_5_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_6_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_7_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void step_8_check(Ui::Game* ui, const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);

    void step_1(int *datas, const int &row, const int &column,bool &CanMove);
    void step_2(int *datas, const int &row, const int &column,bool &CanMove);
    void step_3(int *datas, const int &row, const int &column,bool &CanMove);
    void step_4(int *datas, const int &row, const int &column,bool &CanMove);
    void step_5(int *datas, const int &row, const int &column,bool &CanMove);
    void step_6(int *datas, const int &row, const int &column,bool &CanMove);
    void step_7(int *datas, const int &row, const int &column,bool &CanMove);
    void step_8(int *datas, const int &row, const int &column,bool &CanMove);

    void column_equal_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove);
    void row_equal_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,bool &CanMove);
    void dialog_left_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_right_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_left_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_right_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);

    void step_1_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_2_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_3_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_4_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_5_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_6_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_7_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void step_8_check(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);

    void step_1_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_2_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_3_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_4_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_5_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_6_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_7_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_8_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);

    void column_equal_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void row_equal_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_left_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_right_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_left_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_right_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);

    void step_1_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_2_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_3_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_4_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_5_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_6_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_7_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void step_8_check_machine(int *datas, const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    //int check_point_machine(int *datas, const int &row, const int &column, const int &OldRow, const int &OldColumn);

};

#endif // BLACK_KNIGHT_H
