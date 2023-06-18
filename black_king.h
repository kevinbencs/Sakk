#ifndef BLACK_KING_H
#define BLACK_KING_H


#include "ui_game.h"
#include "check.h"

class Black_king
{
public:
    Black_king();
    void step(Ui::Game* ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,bool &BlackKingRookDidNotMoveRight,bool &BlackKingRookDidNotMoveLeft,int *datas);

    bool there_is_no_white_bishop(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_knight(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_left(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_right(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_up(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook_down(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_rook(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_up_right(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_up_left(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_down_right(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn_down_left(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_queen_and_pawn(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn);
    bool there_is_no_white_king(int *datas,const int &row, const int &column);

    bool get_CanMove(int *datas);
    void step_machine(int *datas,std::vector<std::vector<int>> &MoveAndPoint,const bool &BlackKingRookDidNotMoveRight, const bool &BlackKingRookDidNotMoveLeft);

private:
    bool there_is_no_white_bishop(int *datas, const int &row, const int &column);
    bool there_is_no_white_knight(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_left(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_right(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_up(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook_down(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_rook(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_up_right(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_up_left(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_down_right(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn_down_left(int *datas, const int &row, const int &column);
    bool there_is_no_white_queen_and_pawn(int *datas,const int &row, const int &column);
    bool there_is_no_white_king(int *datas,const int &row);

    void step_1(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_2(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_3(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_4(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_5(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_6(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_7(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_8(Ui::Game *ui, const int &row, const int &column,int *datas);
    void step_castling_left(Ui::Game* ui, const int &row, const int &column, int *datas);
    void step_castling_right(Ui::Game* ui, const int &row, const int &column, int *datas);

    void step_1(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_2(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_3(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_4(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_5(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_6(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_7(int *datas, const int &row, const int &column,  bool &CanMove);
    void step_8(int *datas, const int &row, const int &column,  bool &CanMove);

    void step_1_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_2_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_3_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_4_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_5_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_6_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_7_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_8_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_castling_left_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);
    void step_castling_right_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint);

};

#endif // BLACK_KING_H
