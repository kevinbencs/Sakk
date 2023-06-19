#include "check.h"



////////////////////////////////////////////////////
/// Check there is check and if you step one piece, there will be check
/// Machine get point when hits one piece
////////////////////////////////////////////////////



Check::Check()
{

}



/////////////////////////////////////
/// Delete the green color cells
/////////////////////////////////////
void Check::green_cell_disappear(Ui::Game* ui)
{
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
}


////////////////////////////////////////////////////
/// Check there is check
////////////////////////////////////////////////////
bool Check::king_check(int *datas,const int &BlackOrWhite,const int &row, const int &column, int &AttackerRow, int &AttackerColumn,int &KnightAndBishop)
{
    White_king white_king;
    Black_king black_king;
    KnightAndBishop=0;
    if(BlackOrWhite==1){
        if(!white_king.there_is_no_black_bishop(datas,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!white_king.there_is_no_black_knight(datas,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!white_king.there_is_no_black_queen_and_pawn(datas,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
        if(!white_king.there_is_no_black_queen_and_rook(datas,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
    }
    else{
        if(!black_king.there_is_no_white_bishop(datas,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!black_king.there_is_no_white_knight(datas,row,column,AttackerRow,AttackerColumn)){
            KnightAndBishop=1;
            return true;
        }
        if(!black_king.there_is_no_white_queen_and_pawn(datas,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
        if(!black_king.there_is_no_white_queen_and_rook(datas,row,column,AttackerRow,AttackerColumn)){
            return true;
        }
    }
    return false;
}


////////////////////////////////////////////////////
/// Check if you step one piece, there will be check (white king)
////////////////////////////////////////////////////
bool Check::white_king_right_check(int* datas,const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(*(datas+row*8+i)==10){
            return true;
        }
        else{
            if(*(datas+row*8+i)!=0){
                return false;
            }
        }
    }

    return false;
}



bool Check::white_king_left_check(int* datas,const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(*(datas+row*8+i)==10){
            return true;
        }
        else{
            if(*(datas+row*8+i)!=0){
                return false;
            }
        }
    }
    return false;
}



bool Check::white_king_down_check(int* datas,const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(*(datas+i*8+column)==10){
            return true;
        }
        else{
            if(*(datas+i*8+column)!=0){
                return false;
            }
        }
    }

    return false;
}




bool Check::white_king_up_check(int* datas,const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(*(datas+i*8+column)==10){
            return true;
        }
        else{
            if(*(datas+i*8+column)!=0){
                return false;
            }
        }
    }

    return false;
}




bool Check::white_king_right_down_check(int* datas,const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        if(*(datas+i*8+j)==10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }

    return false;
}




bool Check::white_king_left_down_check(int* datas,const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        if(*(datas+i*8+j)==10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }

    return false;
}





bool Check::white_king_right_up_check(int* datas,const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        if(*(datas+i*8+j)==10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }

    return false;
}




bool Check::white_king_left_up_check(int* datas,const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(*(datas+i*8+j)==10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }

    return false;
}



bool Check::black_queen_black_rook_right_check(int* datas,const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==-8 || *(datas+row*8+i)==-5){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;
}




bool Check::black_queen_black_rook_left_check(int* datas,const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==-8 || *(datas+row*8+i)==-5){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;
}



bool Check::black_queen_black_rook_down_check(int* datas,const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==-8 || *(datas+i*8+column)==-5){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;
}




bool Check::black_queen_black_rook_up_check(int *datas, const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==-8 || *(datas+i*8+column)==-5){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;
}





bool Check::black_queen_black_pawn_right_up_check(int *datas, const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-8 || *(datas+i*8+j)==-3){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;
}




bool Check::black_queen_black_pawn_right_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-8 || *(datas+i*8+j)==-3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}



bool Check::black_queen_black_pawn_left_up_check(int *datas, const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-8 || *(datas+i*8+j)==-3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::black_queen_black_pawn_left_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==-8 || *(datas+i*8+j)==-3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::step_white_up_and_down_check(int *datas,const int &row, const int &column)
{
    if(white_king_right_check(datas,row,column) && black_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(white_king_left_check(datas,row,column) && black_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(white_king_left_down_check(datas,row,column) && black_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_up_check(datas,row,column) && black_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(white_king_right_down_check(datas,row,column) && black_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }
    if(white_king_right_up_check(datas,row,column) && black_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_right_and_left_check(int *datas, const int &row, const int &column)
{
    if(white_king_up_check(datas,row,column) && black_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(white_king_down_check(datas,row,column) && black_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_down_check(datas,row,column) && black_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_up_check(datas,row,column) && black_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(white_king_right_down_check(datas,row,column) && black_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }
    if(white_king_right_up_check(datas,row,column) && black_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_left_up_and_right_down_check(int *datas, const int &row, const int &column)
{
    if(white_king_up_check(datas,row,column) && black_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(white_king_down_check(datas,row,column) && black_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_check(datas,row,column) && black_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(white_king_right_check(datas,row,column) && black_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(white_king_left_down_check(datas,row,column) && black_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(white_king_right_up_check(datas,row,column) && black_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_right_up_and_left_down_check(int *datas, const int &row, const int &column)
{
    if(white_king_up_check(datas,row,column) && black_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(white_king_down_check(datas,row,column) && black_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_check(datas,row,column) && black_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(white_king_right_check(datas,row,column) && black_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(white_king_left_up_check(datas,row,column) && black_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(white_king_right_down_check(datas,row,column) && black_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_white_knight_check(int *datas, const int &row, const int &column)
{
    if(white_king_up_check(datas,row,column) && black_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(white_king_down_check(datas,row,column) && black_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_check(datas,row,column) && black_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(white_king_right_check(datas,row,column) && black_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(white_king_left_up_check(datas,row,column) && black_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(white_king_right_down_check(datas,row,column) && black_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }
    if(white_king_left_down_check(datas,row,column) && black_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(white_king_right_up_check(datas,row,column) && black_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



////////////////////////////////////////////////////
/// Check if you step one piece, there will be check (white king)
////////////////////////////////////////////////////
bool Check::black_king_right_check(int *datas,const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(*(datas+row*8+i)==-10){
            return true;
        }
        else{
            if(*(datas+row*8+i)!=0){
                return false;
            }
        }
    }
    return false;
}




bool Check::black_king_left_check(int *datas,const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(*(datas+row*8+i)==-10){
            return true;
        }
        else{
            if(*(datas+row*8+i)!=0){
                return false;
            }
        }
    }

    return false;
}



bool Check::black_king_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(*(datas+i*8+column)==-10){
            return true;
        }
        else{
            if(*(datas+i*8+column)!=0){
                return false;
            }
        }
    }
    return false;
}




bool Check::black_king_up_check(int *datas,const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(*(datas+i*8+column)==-10){
            return true;
        }
        else{
            if(*(datas+i*8+column)!=0){
                return false;
            }
        }
    }
    return false;
}




bool Check::black_king_right_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        if(*(datas+i*8+j)==-10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }
    return false;
}




bool Check::black_king_left_down_check(int *datas,const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        if(*(datas+i*8+j)==-10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }
    return false;
}





bool Check::black_king_right_up_check(int *datas, const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        if(*(datas+i*8+j)==-10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }
    return false;
}




bool Check::black_king_left_up_check(int *datas,const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(*(datas+i*8+j)==-10){
            return true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                return false;
            }
        }
    }
    return false;
}



bool Check::white_queen_black_rook_right_check(int *datas, const int &row, const int &column)
{
    for(int i=column+1;i<8;i++){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==8 || *(datas+row*8+i)==5){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::white_queen_black_rook_left_check(int *datas,const int &row, const int &column)
{
    for(int i=column-1;i>=0;i--){
        if(*(datas+row*8+i)!=0){
            if(*(datas+row*8+i)==8 || *(datas+row*8+i)==5){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}



bool Check::white_queen_black_rook_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1;i<8;i++){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==8 || *(datas+i*8+column)==5){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::white_queen_black_rook_up_check(int *datas,const int &row, const int &column)
{
    for(int i=row-1;i>=0;i--){
        if(*(datas+i*8+column)!=0){
            if(*(datas+i*8+column)==8 || *(datas+i*8+column)==5){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}





bool Check::white_queen_black_pawn_right_up_check(int *datas, const int &row, const int &column)
{
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==8 || *(datas+i*8+j)==3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::white_queen_black_pawn_right_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==8 || *(datas+i*8+j)==3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}



bool Check::white_queen_black_pawn_left_up_check(int *datas, const int &row, const int &column)
{
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==8 || *(datas+i*8+j)==3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::white_queen_black_pawn_left_down_check(int *datas, const int &row, const int &column)
{
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        if(*(datas+i*8+j)!=0){
            if(*(datas+i*8+j)==8 || *(datas+i*8+j)==3){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}




bool Check::step_black_up_and_down_check(int *datas, const int &row, const int &column)
{
    if(black_king_right_check(datas,row,column) && white_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(black_king_left_check(datas,row,column) && white_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(black_king_left_down_check(datas,row,column) && white_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_up_check(datas,row,column) && white_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(black_king_right_down_check(datas,row,column) && white_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }
    if(black_king_right_up_check(datas,row,column) && white_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_black_right_and_left_check(int *datas, const int &row, const int &column)
{
    if(black_king_up_check(datas,row,column) && white_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(black_king_down_check(datas,row,column) && white_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_down_check(datas,row,column) && white_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_up_check(datas,row,column) && white_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(black_king_right_down_check(datas,row,column) && white_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }
    if(black_king_right_up_check(datas,row,column) && white_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_black_left_up_and_right_down_check(int *datas, const int &row, const int &column)
{
    if(black_king_up_check(datas,row,column) && white_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(black_king_down_check(datas,row,column) && white_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_check(datas,row,column) && white_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(black_king_right_check(datas,row,column) && white_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(black_king_left_down_check(datas,row,column) && white_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(black_king_right_up_check(datas,row,column) && white_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_black_right_up_and_left_down_check(int *datas, const int &row, const int &column)
{
    if(black_king_up_check(datas,row,column) && white_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(black_king_down_check(datas,row,column) && white_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_check(datas,row,column) && white_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(black_king_right_check(datas,row,column) && white_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(black_king_left_up_check(datas,row,column) && white_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(black_king_right_down_check(datas,row,column) && white_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }

    return true;
}



bool Check::step_black_knight_check(int *datas, const int &row, const int &column)
{
    if(black_king_up_check(datas,row,column) && white_queen_black_rook_down_check(datas,row,column)){
        return false;
    }
    if(black_king_down_check(datas,row,column) && white_queen_black_rook_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_check(datas,row,column) && white_queen_black_rook_right_check(datas,row,column)){
        return false;
    }
    if(black_king_right_check(datas,row,column) && white_queen_black_rook_left_check(datas,row,column)){
        return false;
    }
    if(black_king_left_up_check(datas,row,column) && white_queen_black_pawn_right_down_check(datas,row,column)){
        return false;
    }
    if(black_king_right_down_check(datas,row,column) && white_queen_black_pawn_left_up_check(datas,row,column)){
        return false;
    }
    if(black_king_left_down_check(datas,row,column) && white_queen_black_pawn_right_up_check(datas,row,column)){
        return false;
    }
    if(black_king_right_up_check(datas,row,column) && white_queen_black_pawn_left_down_check(datas,row,column)){
        return false;
    }

    return true;
}






void Check::look_for_the_kings(int *datas, const int &BlackOrWhite, int &king_row, int &king_column)
{
    if(BlackOrWhite==1){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==10){
                    king_row=i;
                    king_column=j;
                }
            }
        }
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==-10){
                    king_row=i;
                    king_column=j;
                }
            }
        }
    }
}




//////////////////////////////
/// Check check when the machine steps
//////////////////////////////
bool Check::check_check(int *datas, const int &row, const int &column, const int &piece,const int &OldRow, const int &OldColumn)
{
    bool check=false;
    int *datas1=new int[64];
    int BlackOrWhite,king_row,king_column,AttackerRow,AttackerColumn,KnightAndBishop;

    if(piece<0){
        BlackOrWhite=1;
    }
    else{
        BlackOrWhite=-1;
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            *(datas1+i*8+j)=*(datas+i*8+j);
        }
    }

    *(datas1+OldRow*8+OldColumn)=0;
    *(datas1+row*8+column)=piece;

    look_for_the_kings(datas1, BlackOrWhite, king_row,king_column);

    if(king_check(datas1,BlackOrWhite,king_row,king_column,AttackerRow,AttackerColumn,KnightAndBishop)){
        check=true;
    }

    delete [] datas1;

    return check;
}






/////////////////////
/// The machine get point when it hits one piece
/////////////////////
int Check::occupying_an_white_piece(int *datas, const int &row, const int &column)
{
    int point=0;

    switch (*(datas+8*row+column)){
    case 1:
        point=10;
        break;
    case 3:
        point=30;
        break;
    case 4:
        point=30;
        break;
    case 5:
        point=50;
        break;
    case 8:
        point=80;
        break;
    }

    return point;
}



int Check::occupying_an_black_piece(int *datas, const int &row, const int &column)
{
    int point=0;

    switch (*(datas+8*row+column)){
    case -1:
        point=10;
        break;
    case -3:
        point=30;
        break;
    case -4:
        point=30;
        break;
    case -5:
        point=50;
        break;
    case -8:
        point=80;
        break;
    }

    return point;
}



