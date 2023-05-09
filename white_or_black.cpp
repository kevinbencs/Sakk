#include "white_or_black.h"
#include "ui_white_or_black.h"

White_or_black::White_or_black(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::White_or_black)
{
    ui->setupUi(this);
}

White_or_black::~White_or_black()
{
    delete ui;
}
