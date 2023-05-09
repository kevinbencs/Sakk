#include "black_king.h"

Black_king::Black_king()
{

}



bool Black_king::there_is_no_white_queen_and_rook_right(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=column+1;i<8;i++){
        if(ui->tableWidget->item(row,i)->text()!=""){
            if(ui->tableWidget->item(row,i)->text()=="5" || ui->tableWidget->item(row,i)->text()=="8"){
                AttackerColumn=i;
                AttackerRow=row;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}


bool Black_king::there_is_no_white_queen_and_rook_right(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(ui->tableWidget->item(row,i)->text()!=""){
            if(ui->tableWidget->item(row,i)->text()=="5" || ui->tableWidget->item(row,i)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}




bool Black_king::there_is_no_white_queen_and_rook_left(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=column-1;i>=0;i--){
        if(ui->tableWidget->item(row,i)->text()!=""){
            if(ui->tableWidget->item(row,i)->text()=="5" || ui->tableWidget->item(row,i)->text()=="8"){
                AttackerRow=row;
                AttackerColumn=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}





bool Black_king::there_is_no_white_queen_and_rook_left(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(ui->tableWidget->item(row,i)->text()!=""){
            if(ui->tableWidget->item(row,i)->text()=="5" || ui->tableWidget->item(row,i)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }

    }

    return true;
}



bool Black_king::there_is_no_white_queen_and_rook_up(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row-1;i>=0;i--){
        if(ui->tableWidget->item(i,column)->text()!=""){
            if(ui->tableWidget->item(i,column)->text()=="5" || ui->tableWidget->item(i,column)->text()=="8"){
                AttackerColumn=column;
                AttackerRow=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}


bool Black_king::there_is_no_white_queen_and_rook_up(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(ui->tableWidget->item(i,column)->text()!=""){
            if(ui->tableWidget->item(i,column)->text()=="5" || ui->tableWidget->item(i,column)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}


bool Black_king::there_is_no_white_queen_and_rook_down(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row+1;i<8;i++){
        if(ui->tableWidget->item(i,column)->text()!=""){
            if(ui->tableWidget->item(i,column)->text()=="5" || ui->tableWidget->item(i,column)->text()=="8"){
                AttackerColumn=column;
                AttackerRow=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}



bool Black_king::there_is_no_white_queen_and_rook_down(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(ui->tableWidget->item(i,column)->text()!=""){
            if(ui->tableWidget->item(i,column)->text()=="5" || ui->tableWidget->item(i,column)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}




bool Black_king::there_is_no_white_queen_and_rook(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    return there_is_no_white_queen_and_rook_left(ui, row, column,AttackerRow, AttackerColumn) && there_is_no_white_queen_and_rook_right(ui, row, column,AttackerRow, AttackerColumn) && there_is_no_white_queen_and_rook_up(ui, row, column, AttackerRow, AttackerColumn) && there_is_no_white_queen_and_rook_down(ui, row, column, AttackerRow, AttackerColumn);
}




bool Black_king::there_is_no_white_queen_and_rook(Ui::Game* ui, const int &row, const int &column)
{
    return there_is_no_white_queen_and_rook_left(ui, row, column) && there_is_no_white_queen_and_rook_right(ui, row, column) && there_is_no_white_queen_and_rook_up(ui, row, column) && there_is_no_white_queen_and_rook_down(ui, row, column);
}





bool Black_king::there_is_no_white_queen_and_pawn_up_right(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row-1,j=column+1;i>=0 && j<8; i--, j++){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}


bool Black_king::there_is_no_white_queen_and_pawn_up_right(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8; i--, j++){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}



bool Black_king::there_is_no_white_queen_and_pawn_up_left(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0; i--, j--){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}




bool Black_king::there_is_no_white_queen_and_pawn_up_left(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0; i--, j--){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}



bool Black_king::there_is_no_white_queen_and_pawn_down_right(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row+1,j=column+1;i<8 && j<8; i++, j++){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}



bool Black_king::there_is_no_white_queen_and_pawn_down_right(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8; i++, j++){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}



bool Black_king::there_is_no_white_queen_and_pawn_down_left(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    for(int i=row+1,j=column-1;i<8 && j>=0; i++, j--){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                AttackerColumn=j;
                AttackerRow=i;
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}


bool Black_king::there_is_no_white_queen_and_pawn_down_left(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0; i++, j--){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="3" || ui->tableWidget->item(i,j)->text()=="8"){
                return false;
            }
            else{
                return true;
            }
        }
    }

    return true;
}




bool Black_king::there_is_no_white_queen_and_pawn(Ui::Game* ui,const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    return there_is_no_white_queen_and_pawn_down_left(ui,row,column, AttackerRow, AttackerColumn) && there_is_no_white_queen_and_pawn_down_right(ui,row,column, AttackerRow, AttackerColumn) && there_is_no_white_queen_and_pawn_up_left(ui,row,column, AttackerRow, AttackerColumn) && there_is_no_white_queen_and_pawn_up_right(ui,row,column, AttackerRow, AttackerColumn);
}


bool Black_king::there_is_no_white_queen_and_pawn(Ui::Game* ui,const int &row, const int &column)
{
    return there_is_no_white_queen_and_pawn_down_left(ui,row,column) && there_is_no_white_queen_and_pawn_down_right(ui,row,column) && there_is_no_white_queen_and_pawn_up_left(ui,row,column) && there_is_no_white_queen_and_pawn_up_right(ui,row,column);
}



bool Black_king::there_is_no_white_king(Ui::Game *ui, const int &row, const int &column)
{
    if((row+1)<8 && (column+1)<8){
        if(ui->tableWidget->item(row+1,column+1)->text()=="10"){
            return false;
        }
    }

    if((row+1)<8){
        if(ui->tableWidget->item(row+1,column)->text()=="10"){
            return false;
        }
    }

    if((row+1)<8 && (column-1)>=0){
        if(ui->tableWidget->item(row+1,column-1)->text()=="10"){
            return false;
        }
    }

    if((row-1)>=0 && (column+1)<8){
        if(ui->tableWidget->item(row-1,column+1)->text()=="10"){
            return false;
        }
    }

    if((row-1)>=0){
        if(ui->tableWidget->item(row-1,column)->text()=="10"){
            return false;
        }
    }

    if((row-1)>=0 && (column-1)>=0){
        if(ui->tableWidget->item(row-1,column-1)->text()=="10"){
            return false;
        }
    }

    if((column+1)<8){
        if(ui->tableWidget->item(row,column+1)->text()=="10"){
            return false;
        }
    }

    if((column-1)>=0){
        if(ui->tableWidget->item(row,column-1)->text()=="10"){
            return false;
        }
    }

    return true;
}



bool Black_king::there_is_no_white_knight(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    if((row-1)>=0 && (column+2)<8){
        if(ui->tableWidget->item(row-1,column+2)->text()=="4"){
            AttackerColumn=column+2;
            AttackerRow=row-1;
            return false;
        }
    }

    if((row+1)<8 && (column+2)<8){
        if(ui->tableWidget->item(row+1,column+2)->text()=="4"){
            AttackerColumn=column+2;
            AttackerRow=row+1;
            return false;
        }
    }

    if((row-1)>=0 && (column-2)>=0){
        if(ui->tableWidget->item(row-1,column-2)->text()=="4"){
            AttackerColumn=column-2;
            AttackerRow=row-1;
            return false;
        }
    }

    if((row+1)<8 && (column-2)>=0){
        if(ui->tableWidget->item(row+1,column-2)->text()=="-4"){
            AttackerColumn=column-2;
            AttackerRow=row+1;
            return false;
        }
    }

    if((row-2)>=0 && (column+1)<8){
        if(ui->tableWidget->item(row-2,column+1)->text()=="4"){
            AttackerColumn=column+1;
            AttackerRow=row-2;
            return false;
        }
    }

    if((row+2)<8 && (column+1)<8){
        if(ui->tableWidget->item(row+2,column+1)->text()=="4"){
            AttackerColumn=column+1;
            AttackerRow=row+2;
            return false;
        }
    }

    if((row-2)>=0 && (column-1)>=0){
        if(ui->tableWidget->item(row-2,column-1)->text()=="4"){
            AttackerColumn=column-1;
            AttackerRow=row-2;
            return false;
        }
    }

    if((row+2)<8 && (column-1)>=0){
        if(ui->tableWidget->item(row+2,column-1)->text()=="4"){
            AttackerColumn=column-1;
            AttackerRow=row+2;
            return false;
        }
    }

    return true;
}





bool Black_king::there_is_no_white_knight(Ui::Game* ui, const int &row, const int &column)
{
    if((row-1)>=0 && (column+2)<8){
        if(ui->tableWidget->item(row-1,column+2)->text()=="4"){
            return false;
        }
    }

    if((row+1)<8 && (column+2)<8){
        if(ui->tableWidget->item(row+1,column+2)->text()=="4"){
            return false;
        }
    }

    if((row-1)>=0 && (column-2)>=0){
        if(ui->tableWidget->item(row-1,column-2)->text()=="4"){
            return false;
        }
    }

    if((row+1)<8 && (column-2)>=0){
        if(ui->tableWidget->item(row+1,column-2)->text()=="-4"){
            return false;
        }
    }

    if((row-2)>=0 && (column+1)<8){
        if(ui->tableWidget->item(row-2,column+1)->text()=="4"){
            return false;
        }
    }

    if((row+2)<8 && (column+1)<8){
        if(ui->tableWidget->item(row+2,column+1)->text()=="4"){
            return false;
        }
    }

    if((row-2)>=0 && (column-1)>=0){
        if(ui->tableWidget->item(row-2,column-1)->text()=="4"){
            return false;
        }
    }

    if((row+2)<8 && (column-1)>=0){
        if(ui->tableWidget->item(row+2,column-1)->text()=="4"){
            return false;
        }
    }

    return true;
}



bool Black_king::there_is_no_white_bishop(Ui::Game* ui, const int &row, const int &column, int &AttackerRow, int &AttackerColumn)
{
    if((row+1)<8 && (column+1)<8){
        if(ui->tableWidget->item(row+1,column+1)->text()=="1"){
            AttackerColumn=column+1;
            AttackerRow=row+1;
            return false;
        }
    }

    if((row+1)<8 && (column-1)>=0){
        if(ui->tableWidget->item(row+1,column-1)->text()=="1"){
            AttackerColumn=column-1;
            AttackerRow=row+1;
            return false;
        }
    }

    return true;
}



bool Black_king::there_is_no_white_bishop(Ui::Game* ui, const int &row, const int &column)
{
    if((row+1)<8 && (column+1)<8){
        if(ui->tableWidget->item(row+1,column+1)->text()=="1"){
            return false;
        }
    }

    if((row+1)<8 && (column-1)>=0){
        if(ui->tableWidget->item(row+1,column-1)->text()=="1"){
            return false;
        }
    }

    return true;
}


void Black_king::step_1(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((row+1)<8 && there_is_no_white_bishop(ui,row+1,column) && there_is_no_white_knight(ui,row+1,column) && there_is_no_white_queen_and_rook(ui,row+1,column) && there_is_no_white_queen_and_pawn(ui,row+1,column) && there_is_no_white_king(ui,row+1,column)){
        piece=-10;
        if(ui->tableWidget->item(row+1,column)->text()==""){
            ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+1,column)->text().toInt()>0){
                ui->tableWidget->item(row+1,column)->setBackground(Qt::green);
            }
        }
    }
}


void Black_king::step_2(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((column+1)<8 && there_is_no_white_bishop(ui,row,column+1) && there_is_no_white_knight(ui,row,column+1) && there_is_no_white_queen_and_rook(ui,row,column+1) && there_is_no_white_queen_and_pawn(ui,row,column+1) && there_is_no_white_king(ui,row,column+1)){
        piece=-10;
        if(ui->tableWidget->item(row,column+1)->text()==""){
            ui->tableWidget->item(row,column+1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row,column+1)->text().toInt()>0){
                ui->tableWidget->item(row,column+1)->setBackground(Qt::green);
            }
        }
    }
}


void Black_king::step_3(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((row-1)>=0 && there_is_no_white_bishop(ui,row-1,column) && there_is_no_white_knight(ui,row-1,column) && there_is_no_white_queen_and_rook(ui,row-1,column) && there_is_no_white_queen_and_pawn(ui,row-1,column) && there_is_no_white_king(ui,row-1,column)){
        piece=-10;
        if(ui->tableWidget->item(row-1,column)->text()==""){
            ui->tableWidget->item(row-1,column)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-1,column)->text().toInt()>0){
                ui->tableWidget->item(row-1,column)->setBackground(Qt::green);
            }
        }
    }
}



void Black_king::step_4(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((column-1)>=0 && there_is_no_white_bishop(ui,row,column-1) && there_is_no_white_knight(ui,row,column-1) && there_is_no_white_queen_and_rook(ui,row,column-1) && there_is_no_white_queen_and_pawn(ui,row,column-1) && there_is_no_white_king(ui,row,column-1)){
        piece=-10;
        if(ui->tableWidget->item(row,column-1)->text()==""){
            ui->tableWidget->item(row,column-1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row,column-1)->text().toInt()>0){
                ui->tableWidget->item(row,column-1)->setBackground(Qt::green);
            }
        }
    }
}




void Black_king::step_5(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((row+1)<8 && (column+1)<8 && there_is_no_white_bishop(ui,row+1,column+1) && there_is_no_white_knight(ui,row+1,column+1) && there_is_no_white_queen_and_rook(ui,row+1,column+1) && there_is_no_white_queen_and_pawn(ui,row+1,column+1) && there_is_no_white_king(ui,row+1,column+1)){
        piece=-10;
        if(ui->tableWidget->item(row+1,column+1)->text()==""){
            ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+1,column+1)->text().toInt()>0){
                ui->tableWidget->item(row+1,column+1)->setBackground(Qt::green);
            }
        }
    }
}





void Black_king::step_6(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((row-1)>=0 && (column+1)<8 && there_is_no_white_bishop(ui,row-1,column+1) && there_is_no_white_knight(ui,row-1,column+1) && there_is_no_white_queen_and_rook(ui,row-1,column+1) && there_is_no_white_queen_and_pawn(ui,row-1,column+1) && there_is_no_white_king(ui,row-1,column+1)){
        piece=-10;
        if(ui->tableWidget->item(row-1,column+1)->text()==""){
            ui->tableWidget->item(row-1,column+1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-1,column+1)->text().toInt()>0){
                ui->tableWidget->item(row-1,column+1)->setBackground(Qt::green);
            }
        }
    }
}





void Black_king::step_7(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((row+1)<8 && (column-1)>=0 && there_is_no_white_bishop(ui,row+1,column-1) && there_is_no_white_knight(ui,row+1,column-1) && there_is_no_white_queen_and_rook(ui,row+1,column-1) && there_is_no_white_queen_and_pawn(ui,row+1,column-1) && there_is_no_white_king(ui,row+1,column-1)){
        piece=-10;
        if(ui->tableWidget->item(row+1,column-1)->text()==""){
            ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row+1,column-1)->text().toInt()>0){
                ui->tableWidget->item(row+1,column-1)->setBackground(Qt::green);
            }
        }
    }
}



void Black_king::step_8(Ui::Game *ui, const int &row, const int &column,  int &piece)
{
    if((row-1)>=0 && (column-1)>=0 && there_is_no_white_bishop(ui,row-1,column-1) && there_is_no_white_knight(ui,row-1,column-1) && there_is_no_white_queen_and_rook(ui,row-1,column-1) && there_is_no_white_queen_and_pawn(ui,row-1,column-1) && there_is_no_white_king(ui,row-1,column-1)){
        piece=-10;
        if(ui->tableWidget->item(row-1,column-1)->text()==""){
            ui->tableWidget->item(row-1,column-1)->setBackground(Qt::green);
        }
        else{
            if(ui->tableWidget->item(row-1,column-1)->text().toInt()>0){
                ui->tableWidget->item(row-1,column-1)->setBackground(Qt::green);
            }
        }
    }
}


void Black_king::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite)
{
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        ui->tableWidget->setItem(row,column,new QTableWidgetItem(QString::number(-10)));

        ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));

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
        BlackOrWhite=1;
        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        if(ui->tableWidget->item(row,column)->text()=="-10"){

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

                step_1(ui, row, column, piece);
                step_2(ui, row, column, piece);
                step_3(ui, row, column, piece);
                step_4(ui, row, column, piece);
                step_5(ui, row, column, piece);
                step_6(ui, row, column, piece);
                step_7(ui, row, column, piece);
                step_8(ui, row, column, piece);

            }
            else{
                piece=0;
            }

            ColumnOld=column;
            RowOld=row;

        }
    }
}
