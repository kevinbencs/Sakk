#ifndef WHITE_BISHOP_H
#define WHITE_BISHOP_H

#include "check.h"
#include "ui_game.h"


class White_bishop
{
public:
    White_bishop();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite, int *datas);
    void check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column,int* datas);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn, int &BlackOrWhite,int* datas);
    bool get_checkmate_CanMove(int* datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);
    bool get_draw_CanMove(int* datas);

    void step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint,const int &row, const int &column);
    //void step_machine(int* datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_machine(int* datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
private:
    void step_up(Ui::Game* ui, const int &row, const int &column, int *datas);
    void step_up_right(Ui::Game* ui, const int &row, const int &column, int *datas);
    void step_up_left(Ui::Game* ui, const int &row, const int &column, int *datas);

    void step_up(int* datas, const int &row, const int &column,bool &CanMove);
    void step_up_right(int* datas, const int &row, const int &column,bool &CanMove);
    void step_up_left(int* datas, const int &row, const int &column,bool &CanMove);

    void check_step_move(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow,int* datas);
    void check_step_move(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,const int &AttackerColumn,const int &AttackerRow,int* datas);

    void row_equal_check_step(Ui::Game* ui,const int &row,const int &column,const int &king_column,const int &king_row,const int &AttackerColumn,int* datas);
    void dialog_left_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,int* datas);
    void dialog_right_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,int* datas);
    void dialog_right_up(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,int* datas);
    void dialog_left_down(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,int* datas);

    void check_step_move(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow,bool &CanMove);
    void check_step_move(int* datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);

    void row_equal_check_step(int* datas,const int &row,const int &column,const int &king_column,const int &king_row,const int &AttackerColumn,bool &CanMove);
    void dialog_left_up(int* datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_right_down(int* datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_right_up(int* datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_left_down(int* datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,bool &CanMove);

    void dialog_right_up_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_right_down_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_left_up_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_left_down_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void row_equal_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void check_step_move_machine(int *datas, const int &row, const int &column, std::vector<std::pair<int,int>> v, const int &AttackerColumn, const int &AttackerRow,  std::vector<std::vector<int>> &MoveAndPoint);
    void check_step_move_machine(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, std::vector<std::vector<int>> &MoveAndPoint);

    void step_down_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_down_right_machine(int* datas, const int &row, const int &column, std::vector<std::vector<int> > &MoveAndPoint);
    void step_down_left_machine(int* datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);

};

#endif // WHITE_BISHOP_H
