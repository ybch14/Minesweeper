#include <iostream>
#include "mine.h"
using namespace std;
Square::Square()
{
	if_clicked=0;
	if_signed=0;
	x=0;
	y=0;
}
Square::Square(bool clicked_judge,bool signed_judge,int s_x,int s_y)
{
	if_clicked=clicked_judge;
	if_signed=signed_judge;
	x=s_x;
	y=s_y;
}
//////////////////////////////////////////
MineSquare::MineSquare()
{
	if_clicked=0;
	if_signed=0;
	x=0;
	y=0;
}
MineSquare::MineSquare(bool clicked_judge,bool signed_judge,int m_x,int m_y)
{
	if_clicked=clicked_judge;
	if_signed=signed_judge;
	x=m_x;
	y=m_y;
}
void MineSquare::show()
{
	if((if_clicked==0)&&(if_signed==0))
		cout<<"¡ö";
	else if((if_clicked==1)&&(if_signed==0))
		cout<<"¡ù";
	else if((if_clicked==0)&&(if_signed==1))
		cout<<"¡ø";
}
//////////////////////////////////////////
NumberSquare::NumberSquare()
{
	if_clicked=0;
	if_signed=0;
	x=0;y=0;
	number=0;
}
NumberSquare::NumberSquare(bool clicked_judge,bool signed_judge,int n_x,int n_y,int n_number)
{
	if_clicked=clicked_judge;
	if_signed=signed_judge;
	x=n_x;
	y=n_y;
	number=n_number;
}
void NumberSquare::show()
{
	if((if_clicked==0)&&(if_signed==0))
		cout<<"¡ö";
	else if((if_clicked==1)&&(if_signed==0))
		cout<<number<<" ";
	else if((if_clicked==0)&&(if_signed==1))
		cout<<"¡ø";
}
//////////////////////////////////////////
NullSquare::NullSquare()
{
	if_clicked=0;
	if_signed=0;
	x=0;y=0;
}
NullSquare::NullSquare(bool clicked_judge,bool signed_judge,int n_x,int n_y)
{
	if_clicked=clicked_judge;
	if_signed=signed_judge;
	x=n_x;y=n_y;
}
void NullSquare::show()
{
	if((if_clicked==0)&&(if_clicked==0))
		cout<<"¡ö";
	else if((if_clicked==1)&&(if_signed==0))
		cout<<"  ";
	else if((if_clicked==0)&&(if_signed==1))
		cout<<"¡ø";
}
