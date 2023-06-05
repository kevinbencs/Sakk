#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "humanormachine.h"
#include "white_bishop.h"
#include "black_bishop.h"
#include "white_pawn.h"
#include "black_pawn.h"
#include "white_rook.h"
#include "black_rook.h"
#include "white_queen.h"
#include "black_queen.h"
#include "white_knight.h"
#include "black_knight.h"
#include "white_king.h"
#include "black_king.h"
#include "check.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "black_machine.h"
#include "white_machine.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    void saved_game_load();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_2_clicked();

    void on_Action_triggered();

private:
    bool get_White_CanMove();
    bool be_draw_white();
    bool get_Black_CanMove();
    bool be_draw_black();
    bool there_is_no_draw_and_checkmatt();

    Ui::Game *ui;
    int piece=0;
    int RowOld;
    int ColumnOld;
    int BlackOrWhite=1;
    int king_row,king_column,KnightAndBishop=0,AttackerRow,AttackerColumn;
    bool white_rook_is_ok;
    int OldRow, OldColumn;
    bool WhiteKingRookDidNotMoveLeft=true, WhiteKingRookDidNotMoveRight=true;
    bool BlackKingRookDidNotMoveLeft=true, BlackKingRookDidNotMoveRight=true;
    int *datas=new int[64];
    int WhiteOrBlack=1;

    QMenuBar* menuBar;
    QMenu* menu;
    QAction* Action;
    int theme;

};

#endif // GAME_H
