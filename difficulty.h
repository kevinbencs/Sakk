#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QDialog>

namespace Ui {
class Difficulty;
}

class Difficulty : public QDialog
{
    Q_OBJECT

public:
    explicit Difficulty(QWidget *parent = nullptr);
    ~Difficulty();

private:
    Ui::Difficulty *ui;
};

#endif // DIFFICULTY_H
