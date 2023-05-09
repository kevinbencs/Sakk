#include "check.h"

Check::Check()
{

}


bool Check::king_check(Ui::Game* ui,const int &BlackOrWhite,const int &row, const int &column, int &AttackerRow, int &AttackerColumn,int &KnightAndBishop)
{
    Black_king black_king;
    White_king white_king;
    KnightAndBishop=0;
    if(BlackOrWhite==1){
        if(!white_king.there_is_no_black_bishop(ui,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!white_king.there_is_no_black_knight(ui,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!white_king.there_is_no_black_queen_and_pawn(ui,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
        if(!white_king.there_is_no_black_queen_and_rook(ui,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
    }
    else{
        if(!black_king.there_is_no_white_bishop(ui,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!black_king.there_is_no_white_knight(ui,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!black_king.there_is_no_white_queen_and_pawn(ui,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
        if(!black_king.there_is_no_white_queen_and_rook(ui,row,column,AttackerRow,AttackerColumn)){
            return true;
        }



    }
    return false;
}




bool Check::white_king_right_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(ui->tableWidget->item(row,i)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(row,i)->text()!=""){
                return false;
            }
        }

    }
    return false;
}




bool Check::white_king_left_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(ui->tableWidget->item(row,i)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(row,i)->text()!=""){
                return false;
            }
        }

    }
    return false;
}



bool Check::white_king_down_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(ui->tableWidget->item(i,column)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(i,column)->text()!=""){
                return false;
            }
        }

    }
    return false;
}




bool Check::white_king_up_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(ui->tableWidget->item(i,column)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(i,column)->text()!=""){
                return false;
            }
        }

    }
    return false;
}




bool Check::white_king_right_down_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        if(ui->tableWidget->item(i,j)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                return false;
            }
        }
    }
    return false;
}




bool Check::white_king_left_down_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        if(ui->tableWidget->item(i,j)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                return false;
            }
        }
    }
    return false;
}





bool Check::white_king_right_up_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        if(ui->tableWidget->item(i,j)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                return false;
            }
        }
    }
    return false;
}




bool Check::white_king_left_up_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(ui->tableWidget->item(i,j)->text()=="10"){
            return true;
        }
        else{
            if(ui->tableWidget->item(i,j)->text()!=""){
                return false;
            }
        }
    }
    return false;
}



bool Check::black_queen_black_rook_right_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(ui->tableWidget->item(row,i)->text()!=""){
            if(ui->tableWidget->item(row,i)->text()=="-8" || ui->tableWidget->item(row,i)->text()=="-5"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::black_queen_black_rook_left_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(ui->tableWidget->item(row,i)->text()!=""){
            if(ui->tableWidget->item(row,i)->text()=="-8" || ui->tableWidget->item(row,i)->text()=="-5"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}



bool Check::black_queen_black_rook_down_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(ui->tableWidget->item(i,column)->text()!=""){
            if(ui->tableWidget->item(i,column)->text()=="-8" || ui->tableWidget->item(i,column)->text()=="-5"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::black_queen_black_rook_up_check(Ui::Game* ui,const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(ui->tableWidget->item(i,column)->text()!=""){
            if(ui->tableWidget->item(i,column)->text()=="-8" || ui->tableWidget->item(i,column)->text()=="-5"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}





bool Check::black_queen_black_pawn_right_up_check(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="-8" || ui->tableWidget->item(i,j)->text()=="-3"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::black_queen_black_pawn_right_down_check(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="-8" || ui->tableWidget->item(i,j)->text()=="-3"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}



bool Check::black_queen_black_pawn_left_up_check(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="-8" || ui->tableWidget->item(i,j)->text()=="-3"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::black_queen_black_pawn_left_down_check(Ui::Game* ui, const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        if(ui->tableWidget->item(i,j)->text()!=""){
            if(ui->tableWidget->item(i,j)->text()=="-8" || ui->tableWidget->item(i,j)->text()=="-3"){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::step_white_up_and_down_check(Ui::Game* ui,const int &row, const int &column)
{
    if(white_king_right_check(ui,row,column) && black_queen_black_rook_left_check(ui,row,column)){
        return false;
    }
    if(white_king_left_check(ui,row,column) && black_queen_black_rook_right_check(ui,row,column)){
        return false;
    }
    if(white_king_left_down_check(ui,row,column) && black_queen_black_pawn_right_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_up_check(ui,row,column) && black_queen_black_pawn_right_down_check(ui,row,column)){
        return false;
    }
    if(white_king_right_down_check(ui,row,column) && black_queen_black_pawn_left_up_check(ui,row,column)){
        return false;
    }
    if(white_king_right_up_check(ui,row,column) && black_queen_black_pawn_left_down_check(ui,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_right_and_left_check(Ui::Game* ui,const int &row, const int &column)
{
    if(white_king_up_check(ui,row,column) && black_queen_black_rook_down_check(ui,row,column)){
        return false;
    }
    if(white_king_down_check(ui,row,column) && black_queen_black_rook_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_down_check(ui,row,column) && black_queen_black_pawn_right_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_up_check(ui,row,column) && black_queen_black_pawn_right_down_check(ui,row,column)){
        return false;
    }
    if(white_king_right_down_check(ui,row,column) && black_queen_black_pawn_left_up_check(ui,row,column)){
        return false;
    }
    if(white_king_right_up_check(ui,row,column) && black_queen_black_pawn_left_down_check(ui,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_left_up_and_right_down_check(Ui::Game* ui, const int &row, const int &column)
{
    if(white_king_up_check(ui,row,column) && black_queen_black_rook_down_check(ui,row,column)){
        return false;
    }
    if(white_king_down_check(ui,row,column) && black_queen_black_rook_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_check(ui,row,column) && black_queen_black_rook_right_check(ui,row,column)){
        return false;
    }
    if(white_king_right_check(ui,row,column) && black_queen_black_rook_left_check(ui,row,column)){
        return false;
    }
    if(white_king_left_down_check(ui,row,column) && black_queen_black_pawn_right_up_check(ui,row,column)){
        return false;
    }
    if(white_king_right_up_check(ui,row,column) && black_queen_black_pawn_left_down_check(ui,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_right_up_and_left_down_check(Ui::Game* ui, const int &row, const int &column)
{
    if(white_king_up_check(ui,row,column) && black_queen_black_rook_down_check(ui,row,column)){
        return false;
    }
    if(white_king_down_check(ui,row,column) && black_queen_black_rook_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_check(ui,row,column) && black_queen_black_rook_right_check(ui,row,column)){
        return false;
    }
    if(white_king_right_check(ui,row,column) && black_queen_black_rook_left_check(ui,row,column)){
        return false;
    }
    if(white_king_left_up_check(ui,row,column) && black_queen_black_pawn_right_down_check(ui,row,column)){
        return false;
    }
    if(white_king_right_down_check(ui,row,column) && black_queen_black_pawn_left_up_check(ui,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_knight_check(Ui::Game* ui,const int &row, const int &column)
{
    if(white_king_up_check(ui,row,column) && black_queen_black_rook_down_check(ui,row,column)){
        return false;
    }
    if(white_king_down_check(ui,row,column) && black_queen_black_rook_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_check(ui,row,column) && black_queen_black_rook_right_check(ui,row,column)){
        return false;
    }
    if(white_king_right_check(ui,row,column) && black_queen_black_rook_left_check(ui,row,column)){
        return false;
    }
    if(white_king_left_up_check(ui,row,column) && black_queen_black_pawn_right_down_check(ui,row,column)){
        return false;
    }
    if(white_king_right_down_check(ui,row,column) && black_queen_black_pawn_left_up_check(ui,row,column)){
        return false;
    }
    if(white_king_left_down_check(ui,row,column) && black_queen_black_pawn_right_up_check(ui,row,column)){
        return false;
    }
    if(white_king_right_up_check(ui,row,column) && black_queen_black_pawn_left_down_check(ui,row,column)){
        return false;
    }

    return true;
}
