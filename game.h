#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "difficulty.h"
#include "white_bishop.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::Game *ui;
    int piece;
    int RowOld;
    int ColumnOld;
};

#endif // GAME_H
