#ifndef BLACK_PAWN_H
#define BLACK_PAWN_H


#include "check.h"
#include <vector>

class Black_pawn
{
public:
    Black_pawn();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas);
    void check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column,int *data);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int *data);

    bool get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);
    bool get_draw_CanMove(int *datas);

    void step_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint,const int &row, const int &column);

protected:
    void step_left_up(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_left_down(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_right_up(Ui::Game* ui, const int &row, const int &column,int *datas);
    void step_right_down(Ui::Game* ui, const int &row, const int &column,int *datas);

    void step_left_up(int *datas, const int &row, const int &column,bool &CanMove);
    void step_left_down(int *datas, const int &row, const int &column,bool &CanMove);
    void step_right_up(int *datas, const int &row, const int &column,bool &CanMove);
    void step_right_down(int *datas, const int &row, const int &column,bool &CanMove);

    void column_equal_check_step(Ui::Game *ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerRow,int *datas);
    void row_equal_check_step(Ui::Game *ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,int *datas);
    void dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);
    void dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);
    void dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);
    void dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas);

    void down_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void down_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void up_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);
    void up_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas);

    void column_equal_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerRow,bool &CanMove);
    void row_equal_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove);
    void dialog_left_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_right_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_left_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);
    void dialog_right_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove);

    void down_left_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void down_right_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void up_right_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);
    void up_left_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove);

    void step_right_down_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_right_up_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_left_down_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_left_up_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);

    void column_equal_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void row_equal_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_left_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_right_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_left_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void dialog_right_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);

    void down_left_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void down_right_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void up_right_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);
    void up_left_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint);

private:
    void column_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas);
    void column_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas);
    void column_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas);
    void column_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas);

    void row_up_right_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,int *datas);
    void row_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,int *datas);
    void row_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,int *datas);
    void row_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,int *datas);

    void helper_down_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas);
    void helper_down_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas);
    void helper_up_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas);
    void helper_up_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas);

    void column_up_right_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove);
    void column_down_right_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove);
    void column_up_left_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove);
    void column_down_left_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove);

    void row_up_right_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove);
    void row_down_right_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,bool &CanMove);
    void row_up_left_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,bool &CanMove);
    void row_down_left_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,bool &CanMove);

    void helper_down_left_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove);
    void helper_down_right_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove);
    void helper_up_right_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove);
    void helper_up_left_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove);

    void column_up_right_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void column_down_right_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void column_up_left_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void column_down_left_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);

    void row_up_right_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void row_down_right_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void row_up_left_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void row_down_left_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);

    void helper_down_left_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint);
    void helper_down_right_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint);
    void helper_up_right_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint);
    void helper_up_left_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint);

    void change_piece_cell(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite, int *datas);
};

#endif // BLACK_PAWN_H
