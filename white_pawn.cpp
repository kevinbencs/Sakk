#include "white_pawn.h"
#include <iterator>


White_pawn::White_pawn()
{

}

///////////////////////////////////////////
//////////////////////////////////////////
/// Human
///////////////////////////////////////////
///////////////////////////////////////////


////////////////////////////////////////
/// Step when there is no check
////////////////////////////////////////


////////////////////////////////////////
/// Paint green the cells where the pawn and queen can step
////////////////////////////////////////
void White_pawn::step_left_up(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=row-1, j=column-1;i>=0 && j>=0;i--, j--){
        if(*(datas+i*8+j)==0){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_pawn::step_left_down(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=row+1, j=column-1;i<8 && j>=0;j--, i++){
        if(*(datas+i*8+j)==0){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_pawn::step_right_up(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=row-1, j=column+1;i>=0 && j<8;j++, i--){
        if(*(datas+i*8+j)==0){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



void White_pawn::step_right_down(Ui::Game* ui, const int &row, const int &column,int *datas)
{
    for(int i=row+1, j=column+1; i<8 && j<8;j++, i++){
        if(*(datas+i*8+j)==0){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)<0){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
            break;
        }
    }
}



///////////////////////////////////////////
/// Change the cell of piece
///////////////////////////////////////////
void White_pawn::change_piece_cell(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;
    QImage* img;

    ui->tableWidget->setItem(RowOld,ColumnOld,new QTableWidgetItem(""));
    datas[RowOld*8+ColumnOld]=0;

    if(WhiteOrBlackMachine==-1){
        img=new QImage("Gui/black_pawn.png");
    }
    else{
        img=new QImage("Gui/white_pawn.png");
    }

    QTableWidgetItem* picture=new QTableWidgetItem;
    picture->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(70,70));
    ui->tableWidget->setItem(row,column,picture);
    datas[row*8+column]=3;

    check.green_cell_disappear(ui);
    piece=0;
    BlackOrWhite=-1;
}





void White_pawn::step(Ui::Game *ui, const int &row, const int &column, int &RowOld, int &ColumnOld, int &piece, int &BlackOrWhite,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        change_piece_cell(ui,row,column,RowOld,ColumnOld,piece,BlackOrWhite,datas,WhiteOrBlackMachine);
    }
    else{
        check.green_cell_disappear(ui);

        if(piece!=3 && *(datas+row*8+column)==3){
            if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                step_left_up(ui,row,column,datas);
                step_right_down(ui,row,column,datas);
            }
            if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                step_left_down(ui,row,column,datas);
                step_right_up(ui,row,column,datas);
            }
            piece=3;
        }
        else{
            piece=100;
        }




        ColumnOld=column;
        RowOld=row;
    }
}


////////////////////////
/// Step when there is check
////////////////////////
void White_pawn::column_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas)
{
    for(int i=row-1,j=column+1; j<=king_column && i>=0 ;i--,j++){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void White_pawn::column_down_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas)
{
    for(int i=row+1,j=column+1;j<=king_column && i<8;i++,j++){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}





void White_pawn::column_up_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas)
{
    for(int i=row-1,j=column-1; j>=king_column && i>=0 ;i--,j--){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void White_pawn::column_down_left_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas)
{
    for(int i=row+1,j=column-1;j>=king_column && i<8;i++,j--){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void White_pawn::column_equal_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,int *datas)
{
    Check check;

    if(column<king_column){
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            column_down_right_check_step(ui,row, column, king_column, king_row,AttackerRow,datas);
        }
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            column_up_right_check_step(ui,row, column, king_column, king_row,AttackerRow,datas);
        }
    }
    if(column>king_column){
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            column_down_left_check_step(ui,row, column, king_column, king_row,AttackerRow,datas);
        }
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            column_up_left_check_step(ui,row, column, king_column, king_row,AttackerRow,datas);
        }

    }
}




void White_pawn::row_up_right_check_step(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,int *datas)
{
    for(int i=row-1,j=column+1; j<8 && i>=king_row ;i--,j++){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void White_pawn::row_down_right_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,int *datas)
{
    for(int i=row+1,j=column+1;j<8 && i<=king_row;i++,j++){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}





void White_pawn::row_up_left_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,int *datas)
{
    for(int i=row-1,j=column-1; j>=0 && i>=king_row ;i--,j--){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void White_pawn::row_down_left_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,int *datas)
{
    for(int i=row+1,j=column-1;j>=0 && i<=king_row;i++,j--){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                ui->tableWidget->item(i,j)->setBackground(Qt::green);
            }
        }
    }
}



void White_pawn::row_equal_check_step(Ui::Game* ui, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,int *datas)
{
    Check check;

    if(row>king_row){
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            row_up_left_check_step(ui,row, column, king_column, king_row,AttackerColumn,datas);
        }
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            row_up_right_check_step(ui,row, column, king_column, king_row,AttackerColumn,datas);
        }
    }
    if(row<king_row){
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            row_down_left_check_step(ui,row, column, king_column, king_row,AttackerColumn,datas);
        }
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            row_down_right_check_step(ui,row, column, king_column, king_row,AttackerColumn,datas);
        }
    }
}




void White_pawn::helper_down_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas)
{
    for(int i=row+1,j=column-1;i<=x && j>=y;i++,j--){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::down_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column-1;i<8 && j>=0 && ThereIsOnCell==false;i++,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_left_check_step(ui,row, column,x, y,datas);
    }
}





void White_pawn::helper_down_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas)
{
    for(int i=row+1,j=column+1;i<=x && j<=y;i++,j++){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::down_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column+1;i<8 && j<8 && ThereIsOnCell==false;i++,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_right_check_step(ui,row, column,x, y,datas);
    }
}



void White_pawn::helper_up_right_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas)
{
    for(int i=row-1,j=column+1;i>=x && j<=y;i--,j++){
        if(i==x && j==y){
            ui->tableWidget->item(x,y)->setBackground(Qt::green);
            int a;
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::up_right_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column+1;i>=0 && j<8 && ThereIsOnCell==false;i--,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_right_check_step(ui,row, column,x, y,datas);
    }
}






void White_pawn::helper_up_left_check_step(Ui::Game* ui,const int &row, const int &column,const int &x, const int &y,int *datas)
{
    for(int i=row-1,j=column-1;i>=x && j>=y;i--,j--){
        if(i==x && j==y){
            ui->tableWidget->item(i,j)->setBackground(Qt::green);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::up_left_check_step(Ui::Game* ui,const int &row, const int &column,std::vector<std::pair<int,int>> v,int *datas)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column-1;i>=0 && j>=0 && ThereIsOnCell==false;i--,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_left_check_step(ui,row, column,x, y,datas);
    }
}




void White_pawn::dialog_left_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        down_left_check_step(ui,row,column,v,datas);
        up_right_check_step(ui,row,column,v,datas);
    }
}



void White_pawn::dialog_right_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        down_left_check_step(ui,row,column,v,datas);
        up_right_check_step(ui,row,column,v,datas);
    }
}



void White_pawn::dialog_left_down(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        up_left_check_step(ui,row,column,v,datas);
        down_right_check_step(ui,row,column,v,datas);
    }
}



void White_pawn::dialog_right_up(Ui::Game* ui,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,int *datas)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        up_left_check_step(ui,row,column,v,datas);
        down_right_check_step(ui,row,column,v,datas);
    }
}




void White_pawn::check_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int &king_row, int &king_column,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;
    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        change_piece_cell(ui,row,column,OldRow,OldColumn,piece,BlackOrWhite,datas,WhiteOrBlackMachine);

        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece!=3 && *(datas+row*8+column)==3){
            piece=3;

            if(king_column==AttackerColumn){
                column_equal_check_step(ui,row, column, king_column, king_row,AttackerRow,datas);
            }

            if(king_row==AttackerRow){
                row_equal_check_step(ui,row, column, king_column, king_row,AttackerColumn,datas);
            }

            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                dialog_left_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
            }

            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                dialog_right_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
            }

            if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                dialog_right_up(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
            }

            if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                dialog_left_down(ui,row, column, king_column, king_row,AttackerColumn,AttackerRow,datas);
            }
        }
        else{
            piece=100;
        }

        OldRow=row;
        OldColumn=column;
    }
}



void White_pawn::check_knight_and_bishop_step(Ui::Game *ui, const int &row, const int &column, int &piece, int &OldRow, int &OldColumn, int &AttackerRow, int &AttackerColumn,int &BlackOrWhite,int *datas,const int &WhiteOrBlackMachine)
{
    Check check;

    if(ui->tableWidget->item(row,column)->background()==Qt::green){
        change_piece_cell(ui,row,column,OldRow,OldColumn,piece,BlackOrWhite,datas,WhiteOrBlackMachine);

        ui->label->setText("<p align=center><span style= font-size:22pt><b><b><span><p>");
    }
    else{
        check.green_cell_disappear(ui);

        if(piece!=3 && *(datas+row*8+column)==3){
            piece=3;

            std::vector<std::pair<int,int>> v;
            v.push_back(std::make_pair(AttackerRow,AttackerColumn));

            if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                up_left_check_step(ui,row,column,v,datas);
                down_right_check_step(ui,row,column,v,datas);
            }

            if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                up_right_check_step(ui,row,column,v,datas);
                down_left_check_step(ui,row,column,v,datas);
            }
        }
        else{
            piece=100;
        }

        OldRow=row;
        OldColumn=column;
    }
}









////////////////////////
/// Pawn can step when there is check
///////////////////////

void White_pawn::column_up_right_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove)
{
    for(int i=row-1,j=column+1; j<=king_column && i>=0 ;i--,j++){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                CanMove=true;
            }
        }
    }
}



void White_pawn::column_down_right_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove)
{
    for(int i=row+1,j=column+1;j<=king_column && i<8;i++,j++){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                CanMove=true;
            }
        }
    }
}





void White_pawn::column_up_left_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove)
{
    for(int i=row-1,j=column-1; j>=king_column && i>=0 ;i--,j--){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                CanMove=true;
            }
        }
    }
}



void White_pawn::column_down_left_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove)
{
    for(int i=row+1,j=column-1;j>=king_column && i<8;i++,j--){
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                CanMove=true;
            }
        }
    }
}



void White_pawn::column_equal_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,bool &CanMove)
{
    Check check;

    if(column<king_column){
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            column_down_right_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
        }
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            column_up_right_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
        }
    }
    if(column>king_column){
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            column_down_left_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
        }
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            column_up_left_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
        }

    }
}




void White_pawn::row_up_right_check_step(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,bool &CanMove)
{
    for(int i=row-1,j=column+1; j<8 && i>=king_row ;i--,j++){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                CanMove=true;
            }
        }
    }
}



void White_pawn::row_down_right_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove)
{
    for(int i=row+1,j=column+1;j<8 && i<=king_row;i++,j++){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                CanMove=true;
            }
        }
    }
}





void White_pawn::row_up_left_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove)
{
    for(int i=row-1,j=column-1; j>=0 && i>=king_row ;i--,j--){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                CanMove=true;
            }
        }
    }
}



void White_pawn::row_down_left_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove)
{
    for(int i=row+1,j=column-1;j>=0 && i<=king_row;i++,j--){
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                CanMove=true;
            }
        }
    }
}



void White_pawn::row_equal_check_step(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,bool &CanMove)
{
    Check check;

    if(row>king_row){
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            row_up_left_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
        }
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            row_up_right_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
        }
    }
    if(row<king_row){
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            row_down_left_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
        }
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            row_down_right_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
        }
    }
}




void White_pawn::helper_down_left_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove)
{
    for(int i=row+1,j=column-1;i<=x && j>=y;i++,j--){
        if(i==x && j==y){
            CanMove=true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::down_left_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column-1;i<8 && j>=0 && ThereIsOnCell==false;i++,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_left_check_step(datas,row, column,x, y,CanMove);
    }
}





void White_pawn::helper_down_right_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove)
{
    for(int i=row+1,j=column+1;i<=x && j<=y;i++,j++){
        if(i==x && j==y){
            CanMove=true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::down_right_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column+1;i<8 && j<8 && ThereIsOnCell==false;i++,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_right_check_step(datas,row, column,x, y,CanMove);
    }
}



void White_pawn::helper_up_right_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove)
{
    for(int i=row-1,j=column+1;i>=x && j<=y;i--,j++){
        if(i==x && j==y){
            CanMove=true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::up_right_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column+1;i>=0 && j<8 && ThereIsOnCell==false;i--,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_right_check_step(datas,row, column,x, y,CanMove);
    }
}






void White_pawn::helper_up_left_check_step(int *datas,const int &row, const int &column,const int &x, const int &y,bool &CanMove)
{
    for(int i=row-1,j=column-1;i>=x && j>=y;i--,j--){
        if(i==x && j==y){
            CanMove=true;
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::up_left_check_step(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,bool &CanMove)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column-1;i>=0 && j>=0 && ThereIsOnCell==false;i--,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_left_check_step(datas,row, column,x, y,CanMove);
    }
}




void White_pawn::dialog_left_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        down_left_check_step(datas,row,column,v,CanMove);
        up_right_check_step(datas,row,column,v,CanMove);
    }
}



void White_pawn::dialog_right_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        down_left_check_step(datas,row,column,v,CanMove);
        up_right_check_step(datas,row,column,v,CanMove);
    }
}



void White_pawn::dialog_left_down(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        up_left_check_step(datas,row,column,v,CanMove);
        down_right_check_step(datas,row,column,v,CanMove);
    }
}



void White_pawn::dialog_right_up(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,bool &CanMove)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        up_left_check_step(datas,row,column,v,CanMove);
        down_right_check_step(datas,row,column,v,CanMove);
    }
}








bool White_pawn::get_checkmate_CanMove(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop)
{
    Check check;
    int row, column,king_row,king_column;
    bool CanMove=false;;
    if(KnightBishop==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==3){
                    row=i;
                    column=j;

                    for(int f=0;f<8;f++){
                        for(int l=0;l<8;l++){
                            if(*(datas+f*8+l)==10){
                                king_column=l;
                                king_row=f;
                            }
                        }
                    }

                    //column
                    if(king_column==AttackerColumn){
                        column_equal_check_step(datas,row, column, king_column, king_row,AttackerRow,CanMove);
                    }

                    //row
                    if(king_row==AttackerRow){
                        row_equal_check_step(datas,row, column, king_column, king_row,AttackerColumn,CanMove);
                    }

                    //dialog
                    if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
                        dialog_left_up(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                    }

                    if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
                        dialog_right_down(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                    }

                    if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
                        dialog_right_up(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                    }

                    if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
                        dialog_left_down(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,CanMove);
                    }


                }
            }
        }
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(*(datas+i*8+j)==3){
                    row=i;
                    column=j;

                    std::vector<std::pair<int,int>> v;
                    v.push_back(std::make_pair(AttackerRow,AttackerColumn));

                    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                        up_left_check_step(datas,row,column,v,CanMove);
                        down_right_check_step(datas,row,column,v,CanMove);
                    }

                    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                        up_right_check_step(datas,row,column,v,CanMove);
                        down_left_check_step(datas,row,column,v,CanMove);
                    }
                }
            }
        }
    }

    return CanMove;
}



////////////////////////
/// Pawn can step when there is no check (for draw)
///////////////////////



void White_pawn::step_left_up(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row-1>=0) && (column-1>=0)){
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



void White_pawn::step_left_down(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row+1<8) && (column-1>=0)){
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



void White_pawn::step_right_up(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row-1>=0) && (column+1<8)){
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



void White_pawn::step_right_down(int *datas, const int &row, const int &column,bool &CanMove)
{
    if((row+1<8) && (column+1<8)){
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





bool White_pawn::get_draw_CanMove(int *datas)
{
    Check check;
    int row, column;
    bool CanMove=false;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(*(datas+i*8+j)==3){
                row=i;
                column=j;

                if(check.step_white_left_up_and_right_down_check(datas,row,column)){
                    step_left_up(datas,row,column,CanMove);
                    step_right_down(datas,row,column,CanMove);
                }
                if(check.step_white_right_up_and_left_down_check(datas,row,column)){
                    step_left_down(datas,row,column,CanMove);
                    step_right_up(datas,row,column,CanMove);
                }


            }
        }
    }

    return CanMove;
}





///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/// Machine
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////



void White_pawn::step_left_up_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        point=0;
        if(*(datas+i*8+j)>0){
            break;
        }
        else{
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}



void White_pawn::step_left_down_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column-1;i<8 && j>=0;i++,j--){
        point=0;
        if(*(datas+i*8+j)>0){
            break;
        }
        else{
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}



void White_pawn::step_right_up_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column+1;i>=0 && j<8;i--,j++){
        point=0;
        if(*(datas+i*8+j)>0){
            break;
        }
        else{
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}



void White_pawn::step_right_down_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column+1;i<8 && j<8;i++,j++){
        point=0;
        if(*(datas+i*8+j)>0){
            break;
        }
        else{
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
                MoveAndPoint.push_back(v);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                    MoveAndPoint.push_back(v);
                }
                break;
            }
        }
    }
}





void White_pawn::step_machine(int *datas, const int &row, const int &column,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        step_left_up_machine(datas,row,column,MoveAndPoint);
        step_right_down_machine(datas,row,column,MoveAndPoint);
    }
    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        step_left_down_machine(datas,row,column,MoveAndPoint);
        step_right_up_machine(datas,row,column,MoveAndPoint);
    }
}




















void White_pawn::column_up_right_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column+1; j<=king_column && i>=0 ;i--,j++){
        point=0;
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_pawn::column_down_right_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column+1;j<=king_column && i<8;i++,j++){
        point=0;
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}





void White_pawn::column_up_left_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column-1; j>=king_column && i>=0 ;i--,j--){
        point=0;
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_pawn::column_down_left_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column-1;j>=king_column && i<8;i++,j--){
        point=0;
        if(j!=king_column){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((i>king_row && i<=AttackerRow) || (i<king_row && i>=AttackerRow)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_pawn::column_equal_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(column<king_column){
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            column_down_right_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
        }
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            column_up_right_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
        }
    }
    if(column>king_column){
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            column_down_left_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
        }
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            column_up_left_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
        }

    }
}




void White_pawn::row_up_right_check_step_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column+1; j<8 && i>=king_row ;i--,j++){
        point=0;
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_pawn::row_down_right_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column+1;j<8 && i<=king_row;i++,j++){
        point=0;
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}





void White_pawn::row_up_left_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column-1; j>=0 && i>=king_row ;i--,j--){
        point=0;
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_pawn::row_down_left_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column-1;j>=0 && i<=king_row;i++,j--){
        point=0;
        if(i!=king_row){
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
        else{
            if((j>king_column && j<=AttackerColumn) || (j<king_column && j>=AttackerColumn)){
                std::vector<int> v;
                v.push_back(i);
                v.push_back(j);

                if(*(datas+i*8+j)==0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    v.push_back(point);
                }
                else{
                    if(*(datas+i*8+j)<0){
                        if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                            point+=900;
                        }
                        point+=check.occupying_an_black_piece(datas,i,j);
                        v.push_back(point);
                    }
                }

                MoveAndPoint.push_back(v);
            }
        }
    }
}



void White_pawn::row_equal_check_step_machine(int *datas, const int &row, const int &column, const int &king_column, const int &king_row, const int &AttackerColumn,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;

    if(row>king_row){
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            row_up_left_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
        }
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            row_up_right_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
        }
    }
    if(row<king_row){
        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            row_down_left_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
        }
        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            row_down_right_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
        }
    }
}




void White_pawn::helper_down_left_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column-1;i<=x && j>=y;i++,j--){
        point=0;
        if(i==x && j==y){
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                }
            }

            MoveAndPoint.push_back(v);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::down_left_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column-1;i<8 && j>=0 && ThereIsOnCell==false;i++,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_left_check_step_machine(datas,row, column,x, y,MoveAndPoint);
    }
}





void White_pawn::helper_down_right_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row+1,j=column+1;i<=x && j<=y;i++,j++){
        point=0;
        if(i==x && j==y){
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                }
            }

            MoveAndPoint.push_back(v);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::down_right_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row+1,j=column+1;i<8 && j<8 && ThereIsOnCell==false;i++,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_down_right_check_step_machine(datas,row, column,x, y,MoveAndPoint);
    }
}



void White_pawn::helper_up_right_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column+1;i>=x && j<=y;i--,j++){
        point=0;
        if(i==x && j==y){
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                }
            }

            MoveAndPoint.push_back(v);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::up_right_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column+1;i>=0 && j<8 && ThereIsOnCell==false;i--,j++){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_right_check_step_machine(datas,row, column,x, y,MoveAndPoint);
    }
}






void White_pawn::helper_up_left_check_step_machine(int *datas,const int &row, const int &column,const int &x, const int &y,std::vector<std::vector<int>> &MoveAndPoint)
{
    Check check;
    int point=0;
    for(int i=row-1,j=column-1;i>=x && j>=y;i--,j--){
        point=0;
        if(i==x && j==y){
            std::vector<int> v;
            v.push_back(i);
            v.push_back(j);

            if(*(datas+i*8+j)==0){
                if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                    point+=900;
                }
                v.push_back(point);
            }
            else{
                if(*(datas+i*8+j)<0){
                    if(check.check_check(datas,i,j,*(datas+row*8+column),row,column)){
                        point+=900;
                    }
                    point+=check.occupying_an_black_piece(datas,i,j);
                    v.push_back(point);
                }
            }

            MoveAndPoint.push_back(v);
        }
        else{
            if(*(datas+i*8+j)!=0){
                break;
            }
        }
    }
}



void White_pawn::up_left_check_step_machine(int *datas,const int &row, const int &column,std::vector<std::pair<int,int>> v,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>>::iterator ptr;
    bool ThereIsOnCell=false;
    int x, y;

    for(int i=row-1,j=column-1;i>=0 && j>=0 && ThereIsOnCell==false;i--,j--){
        for(ptr=v.begin(); ptr<v.end() && ThereIsOnCell==false;ptr++){
            if(ptr->first==i && ptr->second==j){
                ThereIsOnCell=true;
                x=i;
                y=j;
            }
        }
    }

    if(ThereIsOnCell){
        helper_up_left_check_step_machine(datas,row, column,x, y,MoveAndPoint);
    }
}




void White_pawn::dialog_left_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column-1;i>=AttackerRow && j>=AttackerColumn;i--,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        down_left_check_step_machine(datas,row,column,v,MoveAndPoint);
        up_right_check_step_machine(datas,row,column,v,MoveAndPoint);
    }
}



void White_pawn::dialog_right_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow, std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column+1;i<=AttackerRow && j<=AttackerColumn;i++,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_right_up_and_left_down_check(datas,row,column)){
        down_left_check_step_machine(datas,row,column,v,MoveAndPoint);
        up_right_check_step_machine(datas,row,column,v,MoveAndPoint);
    }
}



void White_pawn::dialog_left_down_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row+1,j=king_column-1;i<=AttackerRow && j>=AttackerColumn;i++,j--){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        up_left_check_step_machine(datas,row,column,v,MoveAndPoint);
        down_right_check_step_machine(datas,row,column,v,MoveAndPoint);
    }
}



void White_pawn::dialog_right_up_machine(int *datas,const int &row, const int &column, const int &king_column, const int &king_row,const int &AttackerColumn,const int &AttackerRow,std::vector<std::vector<int>> &MoveAndPoint)
{
    std::vector<std::pair<int,int>> v;
    Check check;

    for(int i=king_row-1,j=king_column+1;i>=AttackerRow && j<=AttackerColumn;i--,j++){
        v.push_back(std::make_pair(i,j));
    }

    if(check.step_white_left_up_and_right_down_check(datas,row,column)){
        up_left_check_step_machine(datas,row,column,v,MoveAndPoint);
        down_right_check_step_machine(datas,row,column,v,MoveAndPoint);
    }
}








void White_pawn::step_check_machine(int *datas, const int &AttackerRow, const int &AttackerColumn, const int &KnightBishop, std::vector<std::vector<int>> &MoveAndPoint,const int &row, const int &column)
{
    Check check;
    int king_row,king_column;

    if(KnightBishop==0){
        for(int f=0;f<8;f++){
            for(int l=0;l<8;l++){
                if(*(datas+f*8+l)==-10){
                    king_column=l;
                    king_row=f;
                }
            }
        }

        //column
        if(king_column==AttackerColumn){
            column_equal_check_step_machine(datas,row, column, king_column, king_row,AttackerRow,MoveAndPoint);
        }

        //row
        if(king_row==AttackerRow){
            row_equal_check_step_machine(datas,row, column, king_column, king_row,AttackerColumn,MoveAndPoint);
        }

        //dialog
        if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)>0){
            dialog_left_up_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
        }

        if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)<0){
            dialog_right_down_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
        }

        if((king_column-AttackerColumn)<0 && (king_row-AttackerRow)>0){
            dialog_right_up_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
        }

        if((king_column-AttackerColumn)>0 && (king_row-AttackerRow)<0){
            dialog_left_down_machine(datas,row, column, king_column, king_row,AttackerColumn,AttackerRow,MoveAndPoint);
        }
    }
    else{
        std::vector<std::pair<int,int>> v;
        v.push_back(std::make_pair(AttackerRow,AttackerColumn));

        if(check.step_white_left_up_and_right_down_check(datas,row,column)){
            up_left_check_step_machine(datas,row,column,v,MoveAndPoint);
            down_right_check_step_machine(datas,row,column,v,MoveAndPoint);
        }

        if(check.step_white_right_up_and_left_down_check(datas,row,column)){
            up_right_check_step_machine(datas,row,column,v,MoveAndPoint);
            down_left_check_step_machine(datas,row,column,v,MoveAndPoint);
        }
    }
}



