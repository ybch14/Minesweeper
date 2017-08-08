#ifndef MINE_H
#define MINE_H
#include <iostream>
using namespace std;
class Square
{
protected:
	int x;
	int y;
public:
    bool if_clicked;
	bool if_signed;
	Square();
	Square(bool clicked_judge,bool signed_judge,int s_x,int s_y);
	virtual ~Square(){};
	virtual void show()=0;
	friend void set_map1();
	friend void operate1();
	friend void set_map2();
	friend void operate2();
};
class MineSquare:public Square
{
public:
	MineSquare();
	MineSquare(bool clicked_judge,bool signed_judge,int j_x,int j_y);
	virtual ~MineSquare(){};
	virtual void show();
	friend void set_map1();
	friend void operate1();
	friend void expend1(int e_x,int e_y);
	friend void set_map2();
	friend void operate2();
	friend void expend2(int e_x,int e_y);
	friend void zidingyi();
	friend void expend3(int e_x,int e_y);
};
class NumberSquare:public Square
{
protected:
	int number;
public:
	NumberSquare();
	NumberSquare(bool clicked_judge,bool signed_judge,int n_x,int n_y,int n_number);
	virtual ~NumberSquare(){};
	virtual void show();
	friend void set_map1();
	friend void operate1();
	friend void expend1(int e_x,int e_y);
	friend void set_map2();
	friend void operate2();
	friend void expend2(int e_x,int e_y);
	friend void zidingyi();
	friend void expend3(int e_x,int e_y);
};
class NullSquare:public Square
{
public:
	NullSquare();
	NullSquare(bool clicked_judge,bool signed_judge,int n_x,int n_y);
	virtual ~NullSquare(){};
	virtual void show();
	friend void set_map1();
	friend void operate1();
	friend void expend1(int e_x,int e_y);
	friend void set_map2();
	friend void operate2();
	friend void expend2(int e_x,int e_y);
	friend void zidingyi();
	friend void expend3(int e_x,int e_y);
};
#endif