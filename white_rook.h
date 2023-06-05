#ifndef WHITE_ROOK_H
#define WHITE_ROOK_H


#include "check.h"
#include <ui_game.h>

class White_rook
{
public:
    White_rook();
    void step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite, bool &WhiteKingRookDidNotMoveLeft, bool &WhiteKingRookDidNotMoveRight, int* datas);
    void check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn, int &BlackOrWhite, bool &WhiteKingRookDidNotMoveLeft, bool &WhiteKingRookDidNotMoveRight, int* datas);
    void check_step(Ui::Game* ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn, int &BlackOrWhite, int &king_row, int &king_column, bool &WhiteKingRookDidNotMoveLeft, bool &WhiteKingRookDidNotMoveRight, int* datas);

    bool get_checkmate_CanMove(int* datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop);
    bool get_draw_CanMove(int* datas);

    void step_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint,const int &row, const int &column);

protected:
    void king_column_black_queen_rook_column_equal_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,int* datas);
    void king_row_black_queen_rook_row_equal_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow, const int &king_row, const int &king_column,int* datas);
    void king_dialog_black_queen_pawn_equal_left_down_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,int* datas);
    void king_dialog_black_queen_pawn_equal_left_up_step(Ui::Game* ui,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,int* datas);
    void king_dialog_black_queen_pawn_equal_right_down_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,int* datas);
    void king_dialog_black_queen_pawn_equal_right_up_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,int* datas);

    void left_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn,int* datas);
    void right_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerColumn,int* datas);
    void down_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerRow,int* datas);
    void up_check_step(Ui::Game* ui, const int &row, const int &column, const int &AttackerRow,int* datas);

    void king_column_black_queen_rook_column_equal_step(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, bool &CanMove, const int &king_row, const int &king_column);
    void king_row_black_queen_rook_row_equal_step(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, bool &CanMove, const int &king_row, const int &king_column);
    void king_dialog_black_queen_pawn_equal_left_down_step(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,bool &CanMove);
    void king_dialog_black_queen_pawn_equal_left_up_step(int* datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,bool &CanMove);
    void king_dialog_black_queen_pawn_equal_right_down_step(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,bool &CanMove);
    void king_dialog_black_queen_pawn_equal_right_up_step(int* datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,bool &CanMove);

    void left_check_step(int* datas, const int &row, const int &column, const int &AttackerColumn,bool &CanMove);
    void right_check_step(int* datasi, const int &row, const int &column, const int &AttackerColumn,bool &CanMove);
    void down_check_step(int* datas, const int &row, const int &column, const int &AttackerRow,bool &CanMove);
    void up_check_step(int* datas, const int &row, const int &column, const int &AttackerRow,bool &CanMove);

    void step_up(Ui::Game* ui, const int &row, const int &column,int* datas);
    void step_down(Ui::Game* ui,const int &row, const int &column,int* datas);
    void step_left(Ui::Game* ui, const int &row, const int &column,int* datas);
    void step_right(Ui::Game* ui,const int &row, const int &column,int* datas);

    void step_up(int* datas, const int &row, const int &column,bool &CanMove);
    void step_down(int* datas,const int &row, const int &column,bool &CanMove);
    void step_left(int* datas, const int &row, const int &column,bool &CanMove);
    void step_right(int* datas,const int &row, const int &column,bool &CanMove);

    void step_right_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_left_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_up_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);
    void step_down_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint);

    void left_check_step_machine(int *datas, const int &row, const int &column,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void right_check_step_machine(int *datas, const int &row, const int &column,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint);
    void up_check_step_machine(int *datas,const int &row, const int &column,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void down_check_step_machine(int *datas,const int &row, const int &column,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint);
    void king_column_black_queen_rook_column_equal_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint, const int &king_row, const int &king_column);
    void king_row_black_queen_rook_row_equal_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint, const int &king_row, const int &king_column);
    void king_dialog_black_queen_pawn_equal_left_down_step_machine(int *datas, const int &row, const int &column, const int &AttackerColumn, const int &AttackerRow, const int &king_row, const int &king_column,std::vector<std::vector<int>> &MoveAndPoint);
    void king_dialog_black_queen_pawn_equal_left_up_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,std::vector<std::vector<int>> &MoveAndPoint);
    void king_dialog_black_queen_pawn_equal_right_down_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,std::vector<std::vector<int>> &MoveAndPoint);
    void king_dialog_black_queen_pawn_equal_right_up_step_machine(int *datas,const int &row,const int &column,const int &AttackerColumn,const int &AttackerRow,const int &king_row,const int &king_column,std::vector<std::vector<int>> &MoveAndPoint);

};

#endif // WHITE_ROOK_H
