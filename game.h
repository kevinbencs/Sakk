#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "humanormachine.h"
#include "white_bishop.h"
#include "black_bishop.h"

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

private:
    Ui::Game *ui;
    int piece;
    int RowOld;
    int ColumnOld;
    int BlackOrWhite=1;

};

#endif // GAME_H
