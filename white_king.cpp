#include "white_king.h"

White_king::White_king()
{

}



bool White_king::there_is_no_black_queen_and_rook_right(int *datas, const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==-5 || *(datas+row*8+i)==-8){
                return false;
            }
            else{
                if(*(datas+row*8+i)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook_right(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=column+1;i<8;i++){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==-5 || *(datas+row*8+i)==-8){
                AttackerColumn=i;
                AttackerRow=row;
                return false;
            }
            else{
                if(*(datas+row*8+i)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook_left(int *datas, const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==-5 || *(datas+row*8+i)==-8){
                return false;
            }
            else{
                if(*(datas+row*8+i)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook_left(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=column-1;i>=0;i--){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==-5 || *(datas+row*8+i)==-8){
                AttackerColumn=i;
                AttackerRow=row;
                return false;
            }
            else{
                if(*(datas+row*8+i)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook_up(int *datas, const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==-5 || *(datas+i*8+column)==-8){
                return false;
            }
            else{
                if(*(datas+i*8+column)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook_up(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row-1;i>=0;i--){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==-5 || *(datas+i*8+column)==-8){
                AttackerColumn=column;
                AttackerRow=i;
                return false;
            }
            else{
                if(*(datas+i*8+column)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}


bool White_king::there_is_no_black_queen_and_rook_down(int *datas, const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==-5 || *(datas+i*8+column)==-8){
                return false;
            }
            else{
                if(*(datas+i*8+column)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook_down(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row+1;i<8;i++){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==-5 || *(datas+i*8+column)==-8){
                AttackerColumn=column;
                AttackerRow=i;
                return false;
            }
            else{
                if(*(datas+i*8+column)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_rook(int *datas, const int &row, const int &column)
{
    return there_is_no_black_queen_and_rook_left(datas, row, column) && there_is_no_black_queen_and_rook_right(datas, row, column) && there_is_no_black_queen_and_rook_up(datas, row, column) && there_is_no_black_queen_and_rook_down(datas, row, column);
}



bool White_king::there_is_no_black_queen_and_rook(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    return there_is_no_black_queen_and_rook_left(datas, row, column, AttackerRow, AttackerColumn) && there_is_no_black_queen_and_rook_right(datas, row, column, AttackerRow, AttackerColumn) && there_is_no_black_queen_and_rook_up(datas, row, column, AttackerRow, AttackerColumn) && there_is_no_black_queen_and_rook_down(datas, row, column, AttackerRow, AttackerColumn);
}



bool White_king::there_is_no_black_queen_and_pawn_up_right(int *datas,const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8; i--, j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_pawn_up_right(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row-1,j=column+1;i>=0 && j<8; i--, j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}


bool White_king::there_is_no_black_queen_and_pawn_up_left(int *datas,const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0; i--, j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_pawn_up_left(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0; i--, j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}




bool White_king::there_is_no_black_queen_and_pawn_down_right(int *datas,const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8; i++, j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}




bool White_king::there_is_no_black_queen_and_pawn_down_right(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row+1,j=column+1;i<8 && j<8; i++, j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_pawn_down_left(int *datas,const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0; i++, j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}




bool White_king::there_is_no_black_queen_and_pawn_down_left(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row+1,j=column-1;i<8 && j>=0; i++, j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-3 || *(datas+i*8+j)==-8){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                if(*(datas+i*8+j)!=10){
                    return true;
                }
            }
        }
    }

    return true;
}



bool White_king::there_is_no_black_queen_and_pawn(int *datas,const int &row, const int &column)
{
    return there_is_no_black_queen_and_pawn_down_left(datas,row,column) && there_is_no_black_queen_and_pawn_down_right(datas,row,column) && there_is_no_black_queen_and_pawn_up_left(datas,row,column) && there_is_no_black_queen_and_pawn_up_right(datas,row,column);
}



bool White_king::there_is_no_black_queen_and_pawn(int *datas,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    return there_is_no_black_queen_and_pawn_down_left(datas,row,column, AttackerRow, AttackerColumn) && there_is_no_black_queen_and_pawn_down_right(datas,row,column, AttackerRow, AttackerColumn) && there_is_no_black_queen_and_pawn_up_left(datas,row,column, AttackerRow, AttackerColumn) && there_is_no_black_queen_and_pawn_up_right(datas,row,column, AttackerRow, AttackerColumn);
}



bool White_king::there_is_no_black_king(int *datas, const int &row, const int &column)
{
    if((row+1)<8 && (column+1)<8){
        if(*(datas+(row+1)*8+column+1)==-10){
            return false;
        }
    }

    if((row+1)<8){
        if(*(datas+(row+1)*8+column)==-10){
            return false;
        }
    }

    if((row+1)<8 && (column-1)>=0){
        if(*(datas+(row+1)*8+column-1)==-10){
            return false;
        }
    }

    if((row-1)>=0 && (column+1)<8){
        if(*(datas+(row-1)*8+column+1)==-10){
            return false;
        }
    }

    if((row-1)>=0){
        if(*(datas+(row-1)*8+column)==-10){
            return false;
        }
    }

    if((row-1)>=0 && (column-1)>=0){
        if(*(datas+(row-1)*8+column-1)==-10){
            return false;
        }
    }

    if((column+1)<8){
        if(*(datas+row*8+column+1)==-10){
            return false;
        }
    }

    if((column-1)>=0){
        if(*(datas+row*8+column-1)==-10){
            return false;
        }
    }

    return true;
}



bool White_king::there_is_no_black_knight(int *datas, const int &row, const int &column)
{
    if((row-1)>=0 && (column+2)<8){
        if(*(datas+(row-1)*8+column+2)==-4){
            return false;
        }
    }

    if((row+1)<8 && (column+2)<8){
        if(*(datas+(row+1)*8+column+2)==-4){
            return false;
        }
    }

    if((row-1)>=0 && (column-2)>=0){
        if(*(datas+(row-1)*8+column-2)==-4){
            return false;
        }
    }

    if((row+1)<8 && (column-2)>=0){
        if(*(datas+(row+1)*8+column-2)==-4){
            return false;
        }
    }

    if((row-2)>=0 && (column+1)<8){
        if(*(datas+(row-2)*8+column+1)==-4){
            return false;
        }
    }

    if((row+2)<8 && (column+1)<8){
        if(*(datas+(row+2)*8+column+1)==-4){
            return false;
        }
    }

    if((row-2)>=0 && (column-1)>=0){
        if(*(datas+(row-2)*8+column-1)==-4){
            return false;
        }
    }

    if((row+2)<8 && (column-1)>=0){
        if(*(datas+(row+2)*8+column-1)==-4){
            return false;
        }
    }

    return true;
}




bool White_king::there_is_no_black_knight(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    if((row-1)>=0 && (column+2)<8){
        if(*(datas+(row-1)*8+column+2)==-4){
            AttackerColumn=column+2;
            AttackerRow=row-1;
            return false;
        }
    }

    if((row+1)<8 && (column+2)<8){
        if(*(datas+(row+1)*8+column+2)==-4){
            AttackerColumn=column+2;
            AttackerRow=row+1;
            return false;
        }
    }

    if((row-1)>=0 && (column-2)>=0){
        if(*(datas+(row-1)*8+column-2)==-4){
            AttackerColumn=column-2;
            AttackerRow=row-1;
            return false;
        }
    }

    if((row+1)<8 && (column-2)>=0){
        if(*(datas+(row+1)*8+column-2)==-4){
            AttackerColumn=column-2;
            AttackerRow=row+1;
            return false;
        }
    }

    if((row-2)>=0 && (column+1)<8){
        if(*(datas+(row-2)*8+column+1)==-4){
            AttackerColumn=column+1;
            AttackerRow=row-2;
            return false;
        }
    }

    if((row+2)<8 && (column+1)<8){
        if(*(datas+(row+2)*8+column+1)==-4){
            AttackerColumn=column+1;
            AttackerRow=row+2;
            return false;
        }
    }

    if((row-2)>=0 && (column-1)>=0){
        if(*(datas+(row-2)*8+column-1)==-4){
            AttackerColumn=column-1;
            AttackerRow=row-2;
            return false;
        }
    }

    if((row+2)<8 && (column-1)>=0){
        if(*(datas+(row+2)*8+column-1)==-4){
            AttackerColumn=column-1;
            AttackerRow=row+2;
            return false;
        }
    }

    return true;
}




bool White_king::there_is_no_black_bishop(int *datas, const int &row, const int &column)
{
    if((row-1)>=0 && (column+1)<8){
        if(*(datas+(row-1)*8+column+1)==-1){
            return false;
        }
    }

    if((row-1)>=0 && (column-1)>=0){
        if(*(datas+(row-1)*8+column-1)==-1){
            return false;
        }
    }

    return true;
}



bool White_king::there_is_no_black_bishop(int *datas, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    if((row-1)>=0 && (column+1)<8){
        if(*(datas+(row-1)*8+column+1)==-1){
            AttackerColumn=column+1;
            AttackerRow=row-1;
            return false;
        }
    }

    if((row-1)>=0 && (column-1)>=0){
        if(*(datas+(row-1)*8+column-1)==-1){
            AttackerColumn=column-1;
            AttackerRow=row-1;
            return false;
        }
    }

    return true;
}



void White_king::step_1(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((row+1)<8 && there_is_no_black_bishop(datas,row+1,column) && there_is_no_black_knight(datas,row+1,column) && there_is_no_black_queen_and_rook(datas,row+1,column) && there_is_no_black_queen_and_pawn(datas,row+1,column) && there_is_no_black_king(datas,row+1,column)){
        if(*(datas+(row+1)*8+column)==0){
            ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+1)*8+column)<0){
                ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
            }
        }
    }
}


void White_king::step_2(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((column+1)<8 && there_is_no_black_bishop(datas,row,column+1) && there_is_no_black_knight(datas,row,column+1) && there_is_no_black_queen_and_rook(datas,row,column+1) && there_is_no_black_queen_and_pawn(datas,row,column+1) && there_is_no_black_king(datas,row,column+1)){
        if(*(datas+row*8+column+1)==0){
            ui->tableWidget->item(row,column+1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+row*8+column+1)<0){
                ui->tableWidget->item(row,column+1)->setBackground(Qt::green);
            }
        }
    }
}


void White_king::step_3(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((row-1)>=0 && there_is_no_black_bishop(datas,row-1,column) && there_is_no_black_knight(datas,row-1,column) && there_is_no_black_queen_and_rook(datas,row-1,column) && there_is_no_black_queen_and_pawn(datas,row-1,column) && there_is_no_black_king(datas,row-1,column)){
        if(*(datas+(row-1)*8+column)==0){
            ui->tableWidget->item(row-1,column)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-1)*8+column)<0){
                ui->tableWidget->item(row-1,column)->setBackground(Qt::green);
            }
        }
    }
}



void White_king::step_4(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((column-1)>=0 && there_is_no_black_bishop(datas,row,column-1) && there_is_no_black_knight(datas,row,column-1) && there_is_no_black_queen_and_rook(datas,row,column-1) && there_is_no_black_queen_and_pawn(datas,row,column-1) && there_is_no_black_king(datas,row,column-1)){
        if(*(datas+row*8+column-1)==0){
            ui->tableWidget->item(row,column-1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+row*8+column-1)<0){
                ui->tableWidget->item(row,column-1)->setBackground(Qt::green);
            }
        }
    }
}




void White_king::step_5(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((row+1)<8 && (column+1)<8 && there_is_no_black_bishop(datas,row+1,column+1) && there_is_no_black_knight(datas,row+1,column+1) && there_is_no_black_queen_and_rook(datas,row+1,column+1) && there_is_no_black_queen_and_pawn(datas,row+1,column+1) && there_is_no_black_king(datas,row+1,column+1)){
        if(*(datas+(row+1)*8+column+1)==0){
            ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+1)*8+column+1)<0){
                ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
            }
        }
    }
}





void White_king::step_6(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((row-1)>=0 && (column+1)<8 && there_is_no_black_bishop(datas,row-1,column+1) && there_is_no_black_knight(datas,row-1,column+1) && there_is_no_black_queen_and_rook(datas,row-1,column+1) && there_is_no_black_queen_and_pawn(datas,row-1,column+1) && there_is_no_black_king(datas,row-1,column+1)){
        if(*(datas+(row-1)*8+column+1)==0){
            ui->tableWidget->item(row-1,column+1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-1)*8+column+1)<0){
                ui->tableWidget->item(row-1,column+1)->setBackground(Qt::green);
            }
        }
    }
}





void White_king::step_7(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((row+1)<8 && (column-1)>=0 && there_is_no_black_bishop(datas,row+1,column-1) && there_is_no_black_knight(datas,row+1,column-1) && there_is_no_black_queen_and_rook(datas,row+1,column-1) && there_is_no_black_queen_and_pawn(datas,row+1,column-1) && there_is_no_black_king(datas,row+1,column-1)){
        if(*(datas+(row+1)*8+column-1)==0){
            ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row+1)*8+column-1)<0){
                ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
            }
        }
    }
}



void White_king::step_8(Ui::Game *ui, const int &row, const int &column,int *datas)
{
    if((row-1)>=0 && (column-1)>=0 && there_is_no_black_bishop(datas,row-1,column-1) && there_is_no_black_knight(datas,row-1,column-1) && there_is_no_black_queen_and_rook(datas,row-1,column-1) && there_is_no_black_queen_and_pawn(datas,row-1,column-1) && there_is_no_black_king(datas,row-1,column-1)){
        if(*(datas+(row-1)*8+column-1)==0){
            ui->tableWidget->item(row-1,column-1)->setBackground(Qt::green);
        }
        else{
            if(*(datas+(row-1)*8+column-1)<0){
                ui->tableWidget->item(row-1,column-1)->setBackground(Qt::green);
            }
        }
    }
}



void White_king::step_castling_right(Ui::Game* ui,const int &row, const int &column,int *datas)
{
    if(row==7 && there_is_no_black_bishop(datas,row,column+2) && there_is_no_black_knight(datas,row,column+2) && there_is_no_black_queen_and_rook(datas,row,column+2) && there_is_no_black_queen_and_pawn(datas,row,column+2) && there_is_no_black_king(datas,row,column+2)){
        if(*(datas+row*8+column+1)==0 && *(datas+row*8+column+2)==0 && *(datas+row*8+column+3)==5){
            ui->tableWidget->item(row,column+2)->setBackground(Qt::green);
        }
    }
}



void White_king::step_castling_left(Ui::Game* ui,const int &row, const int &column,int *datas)
{
    if(row==7 && there_is_no_black_bishop(datas,row,column-2) && there_is_no_black_knight(datas,row,column-2) && there_is_no_black_queen_and_rook(datas,row,column-2) && there_is_no_black_queen_and_pawn(datas,row,column-2) && there_is_no_black_king(datas,row,column-2)){
        if(*(datas+row*8+column-1)==0 && *(datas+row*8+column-2)==0 && *(datas+row*8+column-3)==0  && *(datas+row*8+column-4)==5){
            ui->tableWidget->item(row,column-2)->setBackground(Qt::green);
        }
    }
}




void White_king::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,bool &WhiteKingRookDidNotMoveLeft,bool &WhiteKingRookDidNotMoveRight,int *datas)
{
    if(ui->tableWidget->item(row,column)->background()==Qt::green){

        QImage *img=new QImage("Gui/white_king.png");

        QTableWidgetItem* picture=new QTableWidgetItem;
        picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img).scaled(70,70));
        ui->tableWidget->setItem(row,column,picture);
        datas[row*8+column]=10;

        datas[RowOld*8+ColumnOld]=0;

        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));



        if(row==7 && column==6 && WhiteKingRookDidNotMoveRight){
            QImage *img2=new QImage("Gui/white_rook.png");
            picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img2).scaled(70,70));
            ui->tableWidget->setItem(row,column-1,picture);
            datas[row*8+column-1]=5;
            datas[row*8+column+1]=0;
            ui->tableWidget->setItem(row,column+1,new QTableWidgetItem(""));
        }
        if(row==7 && column==2 && WhiteKingRookDidNotMoveLeft){
            QImage *img2=new QImage("Gui/white_rook.png");
            picture->setData(Qt::DecorationRole,QPixmap::fromImage(*img2).scaled(70,70));
            ui->tableWidget->setItem(row,column+1,picture);
            datas[row*8+column+1]=5;
            datas[row*8+column-1]=0;
            ui->tableWidget->setItem(row,column-1,new QTableWidgetItem(""));
        }

        WhiteKingRookDidNotMoveLeft=false;
        WhiteKingRookDidNotMoveRight=false;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if((i+j)%2==0){
                    ui->tableWidget->item(i,j)->setBackground(Qt::gray);
                }
                else{
                    ui->tableWidget->item(i,j)->setBackground(Qt::white);
                }
            }
        }

        piece=0;
        BlackOrWhite=-1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if((i+j)%2==0){
                    ui->tableWidget->item(i,j)->setBackground(Qt::gray);
                }
                else{
                    ui->tableWidget->item(i,j)->setBackground(Qt::white);
                }
            }
        }

        if(piece==0){

            step_1(ui, row, column,datas);
            step_2(ui, row, column,datas);
            step_3(ui, row, column,datas);
            step_4(ui, row, column,datas);
            step_5(ui, row, column,datas);
            step_6(ui, row, column,datas);
            step_7(ui, row, column,datas);
            step_8(ui, row, column,datas);
            if(WhiteKingRookDidNotMoveRight){
                step_castling_right(ui,row,column,datas);
            }
            if(WhiteKingRookDidNotMoveLeft){
                step_castling_left(ui,row,column,datas);
            }
            piece=10;

        }
        else{
            piece=0;
        }

        ColumnOld=column;
        RowOld=row;
    }
}





void White_king::step_1(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((row+1)<8 && there_is_no_black_bishop(datas,row+1,column) && there_is_no_black_knight(datas,row+1,column) && there_is_no_black_queen_and_rook(datas,row+1,column) && there_is_no_black_queen_and_pawn(datas,row+1,column) && there_is_no_black_king(datas,row+1,column)){
        if(*(datas+(row+1)*8+column)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+1)*8+column)<0){
                CanMove=true;
            }
        }
    }
}


void White_king::step_2(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((column+1)<8 && there_is_no_black_bishop(datas,row,column+1) && there_is_no_black_knight(datas,row,column+1) && there_is_no_black_queen_and_rook(datas,row,column+1) && there_is_no_black_queen_and_pawn(datas,row,column+1) && there_is_no_black_king(datas,row,column+1)){
        if(*(datas+row*8+column+1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+row*8+column+1)<0){
                CanMove=true;
            }
        }
    }
}


void White_king::step_3(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((row-1)>=0 && there_is_no_black_bishop(datas,row-1,column) && there_is_no_black_knight(datas,row-1,column) && there_is_no_black_queen_and_rook(datas,row-1,column) && there_is_no_black_queen_and_pawn(datas,row-1,column) && there_is_no_black_king(datas,row-1,column)){
        if(*(datas+(row-1)*8+column)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-1)*8+column)<0){
                CanMove=true;
            }
        }
    }
}



void White_king::step_4(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((column-1)>=0 && there_is_no_black_bishop(datas,row,column-1) && there_is_no_black_knight(datas,row,column-1) && there_is_no_black_queen_and_rook(datas,row,column-1) && there_is_no_black_queen_and_pawn(datas,row,column-1) && there_is_no_black_king(datas,row,column-1)){
        if(*(datas+row*8+column-1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+row*8+column-1)<0){
                CanMove=true;
            }
        }
    }
}




void White_king::step_5(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((row+1)<8 && (column+1)<8 && there_is_no_black_bishop(datas,row+1,column+1) && there_is_no_black_knight(datas,row+1,column+1) && there_is_no_black_queen_and_rook(datas,row+1,column+1) && there_is_no_black_queen_and_pawn(datas,row+1,column+1) && there_is_no_black_king(datas,row+1,column+1)){
        if(*(datas+(row+1)*8+column+1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+1)*8+column+1)<0){
                CanMove=true;
            }
        }
    }
}





void White_king::step_6(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((row-1)>=0 && (column+1)<8 && there_is_no_black_bishop(datas,row-1,column+1) && there_is_no_black_knight(datas,row-1,column+1) && there_is_no_black_queen_and_rook(datas,row-1,column+1) && there_is_no_black_queen_and_pawn(datas,row-1,column+1) && there_is_no_black_king(datas,row-1,column+1)){
        if(*(datas+(row-1)*8+column+1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-1)*8+column+1)<0){
                CanMove=true;
            }
        }
    }
}





void White_king::step_7(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((row+1)<8 && (column-1)>=0 && there_is_no_black_bishop(datas,row+1,column-1) && there_is_no_black_knight(datas,row+1,column-1) && there_is_no_black_queen_and_rook(datas,row+1,column-1) && there_is_no_black_queen_and_pawn(datas,row+1,column-1) && there_is_no_black_king(datas,row+1,column-1)){
        if(*(datas+(row+1)*8+column-1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row+1)*8+column-1)<0){
                CanMove=true;
            }
        }
    }
}



void White_king::step_8(int *datas, const int &row, const int &column,  bool &CanMove)
{
    if((row-1)>=0 && (column-1)>=0 && there_is_no_black_bishop(datas,row-1,column-1) && there_is_no_black_knight(datas,row-1,column-1) && there_is_no_black_queen_and_rook(datas,row-1,column-1) && there_is_no_black_queen_and_pawn(datas,row-1,column-1) && there_is_no_black_king(datas,row-1,column-1)){
        if(*(datas+(row-1)*8+column-1)==0){
            CanMove=true;
        }
        else{
            if(*(datas+(row-1)*8+column-1)<0){
                CanMove=true;
            }
        }
    }
}







bool White_king::get_CanMove(int *datas)
{
    int row, column;
    bool CanMove=false;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==10){
                row=i;
                column=j;

                step_1(datas, row, column, CanMove);
                step_2(datas, row, column, CanMove);
                step_3(datas, row, column, CanMove);
                step_4(datas, row, column, CanMove);
                step_5(datas, row, column, CanMove);
                step_6(datas, row, column, CanMove);
                step_7(datas, row, column, CanMove);
                step_8(datas, row, column, CanMove);
            }
        }
    }

    return CanMove;
}




void White_king::step_1_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && there_is_no_black_bishop(datas,row+1,column) && there_is_no_black_knight(datas,row+1,column) && there_is_no_black_queen_and_rook(datas,row+1,column) && there_is_no_black_queen_and_pawn(datas,row+1,column) && there_is_no_black_king(datas,row+1,column)){
        if(*(datas+(row+1)*8+column)==0){
            std::vector<int> f;
            f.push_back(row+1);
            f.push_back(column);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+1)*8+column)<0){
                std::vector<int> f;
                f.push_back(row+1);
                f.push_back(column);
                point+=check.occupying_an_black_piece(datas,row+1,column);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}


void White_king::step_2_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((column+1)<8 && there_is_no_black_bishop(datas,row,column+1) && there_is_no_black_knight(datas,row,column+1) && there_is_no_black_queen_and_rook(datas,row,column+1) && there_is_no_black_queen_and_pawn(datas,row,column+1) && there_is_no_black_king(datas,row,column+1)){
        if(*(datas+row*8+column+1)==0){
            std::vector<int> f;
            f.push_back(row);
            f.push_back(column+1);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+row*8+column+1)<0){
                std::vector<int> f;
                f.push_back(row);
                f.push_back(column+1);
                point+=check.occupying_an_black_piece(datas,row,column+1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}


void White_king::step_3_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && there_is_no_black_bishop(datas,row-1,column) && there_is_no_black_knight(datas,row-1,column) && there_is_no_black_queen_and_rook(datas,row-1,column) && there_is_no_black_queen_and_pawn(datas,row-1,column) && there_is_no_black_king(datas,row-1,column)){
        if(*(datas+(row-1)*8+column)==0){
            std::vector<int> f;
            f.push_back(row-1);
            f.push_back(column);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-1)*8+column)<0){
                std::vector<int> f;
                f.push_back(row-1);
                f.push_back(column);
                point+=check.occupying_an_black_piece(datas,row-1,column);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}



void White_king::step_4_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((column-1)>=0 && there_is_no_black_bishop(datas,row,column-1) && there_is_no_black_knight(datas,row,column-1) && there_is_no_black_queen_and_rook(datas,row,column-1) && there_is_no_black_queen_and_pawn(datas,row,column-1) && there_is_no_black_king(datas,row,column-1)){
        if(*(datas+row*8+column-1)==0){
            std::vector<int> f;
            f.push_back(row);
            f.push_back(column-1);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+row*8+column-1)<0){
                std::vector<int> f;
                f.push_back(row);
                f.push_back(column-1);
                point+=check.occupying_an_black_piece(datas,row,column-1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}




void White_king::step_5_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && (column+1)<8 && there_is_no_black_bishop(datas,row+1,column+1) && there_is_no_black_knight(datas,row+1,column+1) && there_is_no_black_queen_and_rook(datas,row+1,column+1) && there_is_no_black_queen_and_pawn(datas,row+1,column+1) && there_is_no_black_king(datas,row+1,column+1)){
        if(*(datas+(row+1)*8+column+1)==0){
            std::vector<int> f;
            f.push_back(row+1);
            f.push_back(column+1);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+1)*8+column+1)<0){
                std::vector<int> f;
                f.push_back(row+1);
                f.push_back(column+1);
                point+=check.occupying_an_black_piece(datas,row+1,column+1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}





void White_king::step_6_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && (column+1)<8 && there_is_no_black_bishop(datas,row-1,column+1) && there_is_no_black_knight(datas,row-1,column+1) && there_is_no_black_queen_and_rook(datas,row-1,column+1) && there_is_no_black_queen_and_pawn(datas,row-1,column+1) && there_is_no_black_king(datas,row-1,column+1)){
        if(*(datas+(row-1)*8+column+1)==0){
            std::vector<int> f;
            f.push_back(row-1);
            f.push_back(column+1);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-1)*8+column+1)<0){
                std::vector<int> f;
                f.push_back(row-1);
                f.push_back(column+1);
                point+=check.occupying_an_black_piece(datas,row-1,column+1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}





void White_king::step_7_machine(int *datas, const int &row, const int &column,  std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row+1)<8 && (column-1)>=0 && there_is_no_black_bishop(datas,row+1,column-1) && there_is_no_black_knight(datas,row+1,column-1) && there_is_no_black_queen_and_rook(datas,row+1,column-1) && there_is_no_black_queen_and_pawn(datas,row+1,column-1) && there_is_no_black_king(datas,row+1,column-1)){
        if(*(datas+(row+1)*8+column-1)==0){
            std::vector<int> f;
            f.push_back(row+1);
            f.push_back(column-1);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row+1)*8+column-1)<0){
                std::vector<int> f;
                f.push_back(row+1);
                f.push_back(column-1);
                point+=check.occupying_an_black_piece(datas,row+1,column-1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}



void White_king::step_8_machine(int *datas, const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    if((row-1)>=0 && (column-1)>=0 && there_is_no_black_bishop(datas,row-1,column-1) && there_is_no_black_knight(datas,row-1,column-1) && there_is_no_black_queen_and_rook(datas,row-1,column-1) && there_is_no_black_queen_and_pawn(datas,row-1,column-1) && there_is_no_black_king(datas,row-1,column-1)){
        if(*(datas+(row-1)*8+column-1)==0){
            std::vector<int> f;
            f.push_back(row-1);
            f.push_back(column-1);
            f.push_back(point);
            MoveAndPoint.push_back(f);
        }
        else{
            if(*(datas+(row-1)*8+column-1)<0){
                std::vector<int> f;
                f.push_back(row-1);
                f.push_back(column-1);
                point+=check.occupying_an_black_piece(datas,row-1,column-1);
                f.push_back(point);
                MoveAndPoint.push_back(f);
            }
        }
    }
}



void White_king::step_castling_right_machine(int *datas,const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint)
{
    if(row==0 && there_is_no_black_bishop(datas,row,column+2) && there_is_no_black_knight(datas,row,column+2) && there_is_no_black_queen_and_rook(datas,row,column+2) && there_is_no_black_queen_and_pawn(datas,row,column+2) && there_is_no_black_king(datas,row,column+2)){
        if(*(datas+row*8+column+1)==0 && *(datas+row*8+column+2)==0 && *(datas+row*8+column+3)==-5){
            std::vector<int> f;
            f.push_back(row);
            f.push_back(column+2);
            f.push_back(0);
            MoveAndPoint.push_back(f);
        }
    }
}



void White_king::step_castling_left_machine(int *datas,const int &row, const int &column, std::vector<std::vector<int>> &MoveAndPoint)
{
    if(row==0 && there_is_no_black_bishop(datas,row,column-2) && there_is_no_black_knight(datas,row,column-2) && there_is_no_black_queen_and_rook(datas,row,column-2) && there_is_no_black_queen_and_pawn(datas,row,column-2) && there_is_no_black_king(datas,row,column-2)){
        if(*(datas+row*8+column-1)==0 && *(datas+row*8+column-2)==0 && *(datas+row*8+column-3)==0 && *(datas+row*8+column-4)==-5){
            std::vector<int> f;
            f.push_back(row);
            f.push_back(column-2);
            f.push_back(0);
            MoveAndPoint.push_back(f);
        }
    }
}





void White_king::step_machine(int *datas,std::vector<std::vector<int>> &MoveAndPoint)
{
    int row, column;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==10){
                row=i;
                column=j;

                step_1_machine(datas, row, column, MoveAndPoint);
                step_2_machine(datas, row, column, MoveAndPoint);
                step_3_machine(datas, row, column, MoveAndPoint);
                step_4_machine(datas, row, column, MoveAndPoint);
                step_5_machine(datas, row, column, MoveAndPoint);
                step_6_machine(datas, row, column, MoveAndPoint);
                step_7_machine(datas, row, column, MoveAndPoint);
                step_8_machine(datas, row, column, MoveAndPoint);
                step_castling_left_machine(datas,row, column, MoveAndPoint);
                step_castling_right_machine(datas,row, column, MoveAndPoint);
            }
        }
    }
}




