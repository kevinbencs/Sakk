#ifndef WHITE_OR_BLACK_H
#define WHITE_OR_BLACK_H

#include <QDialog>

namespace Ui {
class White_or_black;
}

class White_or_black : public QDialog
{
    Q_OBJECT

public:
    explicit White_or_black(QWidget *parent = nullptr);
    ~White_or_black();

private:
    Ui::White_or_black *ui;
};

#endif // WHITE_OR_BLACK_H
