#include <iostream>
#include <ctime>
#include "mine.h"
using namespace std;
extern int i;extern int j;
extern const int directions[3]={0,1,-1};
extern int row,column,lei;
extern MineSquare *mine3;
extern NullSquare *null3;
extern NumberSquare *number3;
extern int **map3;
void zidingyi()
{
	int mine_left3=lei;
	mine3=new MineSquare[row*column+2];
	null3=new NullSquare[row*column+2];
	number3=new NumberSquare[row*column+2];
	int *minenumber3=new int[lei];
	map3=new int*[row+2];
	for(i=0;i<row+2;i++)
		map3[i]=new int[column+2];
	////////////////////////
	for(i=0;i<row*column+2;i++)
	{
		mine3[i]=MineSquare(0,0,0,0);
		null3[i]=NullSquare(0,0,0,0);
		number3[i]=NumberSquare(0,0,0,0,0);
	}
	void expend3(int e_x,int e_y);
	for(i=0;i<row+2;i++)
		for(j=0;j<column+2;j++)
			map3[i][j]=0;
	int *buffer=new int[row*column+1],k=0,n=0;
	for(i=0;i<row*column+1;i++)
		buffer[i]=i;
	srand((unsigned)time(NULL));
	for(i=0;i<lei;i++)
	{
		k=rand()%(row*column)+1;
		n=buffer[k];
		while(n==-1)
		{
			k=rand()%(row*column)+1;
			n=buffer[k];
		}
		minenumber3[i]=n;
		buffer[k]=-1;
	}
	delete []buffer;
	buffer=NULL;
	for(i=0;i<lei;i++)
	{
		if(minenumber3[i]%column==0)
		{
			mine3[minenumber3[i]]=MineSquare(0,0,minenumber3[i]/column,column);
			map3[minenumber3[i]/column][column]=1;
		}
		else 
		{
			mine3[minenumber3[i]]=MineSquare(0,0,minenumber3[i]/column+1,minenumber3[i]%column);
			map3[minenumber3[i]/column+1][minenumber3[i]%column]=1;
		}
	}	
	minenumber3=NULL;
	delete []minenumber3;

	int number_of_mine=0,ii=0,jj=0;
	for(ii=1,number_of_mine=0;ii<=row;ii++)
	{
		for(jj=1;jj<=column;jj++)
		{
			number_of_mine=0;
			if((map3[ii][jj]==0)&&(map3[ii-1][jj-1]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii][jj-1]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii+1][jj-1]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii-1][jj]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii+1][jj]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii-1][jj+1]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii][jj+1]==1))
				number_of_mine++;
			if((map3[ii][jj]==0)&&(map3[ii+1][jj+1]==1))
				number_of_mine++;
			if((number_of_mine==0)&&(map3[ii][jj]==0))
				null3[column*(ii-1)+jj]=NullSquare(0,0,ii,jj);
			if((number_of_mine!=0)&&(map3[ii][jj]==0))
			{
				number3[column*(ii-1)+jj]=NumberSquare(0,0,ii,jj,number_of_mine);
				map3[ii][jj]=2;
			}
		}
	}
	system("cls");
	if(column<10){
		for(i=0;i<column;i++)
		    cout<<"    "<<i+1;
	    cout<<endl<<" |";
	}
	else 
	{
		for(i=0;i<9;i++)
			cout<<"    "<<i+1;
		for(i=9;i<column;i++)
			cout<<"   "<<i+1;
		cout<<endl<<" |";
	}
	for(i=0;i<column;i++)
		cout<<"----|";
	cout<<endl;
	for(i=1;i<=row;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=column;j++)
		{
			Square *temp=NULL;
			if((mine3[column*(i-1)+j].x!=0)&&(mine3[column*(i-1)+j].y!=0))
				temp=&mine3[column*(i-1)+j];
			if((null3[column*(i-1)+j].x!=0)&&(null3[column*(i-1)+j].y!=0))
				temp=&null3[column*(i-1)+j];
			if((number3[column*(i-1)+j].x!=0)&&(number3[column*(i-1)+j].y!=0))
				temp=&number3[column*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl<<" |";
		for(int k=0;k<column;k++)
		cout<<"----|";
		cout<<endl;
	}cout<<"现在剩余"<<lei<<"颗雷。"<<endl;
	char temp=0;int tempx=0,tempy=0;int order=0,location=0;
	int enderror=0;double winerror=0.0;
	for(int count=0;;count++)
	{
	    cout<<"请选择目标点的坐标，\n横纵坐标用空格分隔,字母在前数字在后："<<endl;
	    cin>>temp>>tempy;
	    tempx=(int)temp-64;
		location=column*(tempx-1)+tempy;
		cout<<"请选择你要执行的操作：1 点击 2 标记为雷或取消标记："<<endl;
	    cin>>order;
	    if((order!=1)&&(order!=2))
		    continue;
	    else if(order==1)
		{
			if((mine3[location].x!=0)&&(mine3[location].y!=0)
				&&(mine3[location].if_clicked==0)&&(mine3[location].if_signed==0))
			{
				mine3[location].if_clicked=1;
				for(int k=0;k<row*column+1;k++)
				{
					if((mine3[k].x!=0)&&(mine3[k].y!=0))
					{
						mine3[k].if_signed=0;
						mine3[k].if_clicked=1;
					}
					if((null3[k].x!=0)&&(null3[k].y!=0))
					{
						null3[k].if_signed=0;
						null3[k].if_clicked=1;
					}
				    if((number3[k].x!=0)&&(number3[k].y!=0))
					{
						number3[k].if_signed=0;
						number3[k].if_clicked=1;
					}
				}
				system("cls");
				if(column<10){
		            for(i=0;i<column;i++)
		            cout<<"    "<<i+1;
	                cout<<endl<<" |";
	            }
	            else 
	            {
		             for(i=0;i<9;i++)
			             cout<<"    "<<i+1;
		             for(i=9;i<column;i++)
			             cout<<"   "<<i+1;
		             cout<<endl<<" |";
	            }
				for(i=0;i<column;i++)
					cout<<"----|";
				cout<<endl;
	for(i=1;i<=row;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=column;j++)
		{
			Square *temp=NULL;
			if((mine3[column*(i-1)+j].x!=0)&&(mine3[column*(i-1)+j].y!=0))
				temp=&mine3[column*(i-1)+j];
			if((null3[column*(i-1)+j].x!=0)&&(null3[column*(i-1)+j].y!=0))
				temp=&null3[column*(i-1)+j];
			if((number3[column*(i-1)+j].x!=0)&&(number3[column*(i-1)+j].y!=0))
				temp=&number3[column*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl<<" |";
		for(int k=0;k<column;k++)
			cout<<"----|";
		cout<<endl;
	}
				throw enderror;
			}
			else if((number3[location].x!=0)&&(number3[location].y!=0)
				&&(number3[location].if_clicked==0)&&(number3[location].if_signed==0))
				number3[location].if_clicked=1;
			else if((null3[location].x!=0)&&(null3[location].y!=0)
				&&(null3[location].if_clicked==0)&&(null3[location].if_signed==0))
			{
				null3[location].if_clicked=1;
				expend3(tempx,tempy);
			}
			else 
				cout<<"该坐标无法被点击！"<<endl;
		}
		else if(order==2)
		{
			if((mine3[location].x!=0)&&(mine3[location].y!=0)
				&&(mine3[location].if_clicked==0)&&(mine3[location].if_signed==0))
			{
				mine3[location].if_signed=1;
				mine_left3--;
			}
			else if((mine3[location].x!=0)&&(mine3[location].y!=0)
				&&(mine3[location].if_clicked==0)&&(mine3[location].if_signed==1))
			{
				mine3[location].if_signed=0;
				mine_left3++;
			}
			else if((null3[location].x!=0)&&(null3[location].y!=0)
				&&(null3[location].if_clicked==0)&&(null3[location].if_signed==0))
			{
				null3[location].if_signed=1;
				mine_left3--;
			}
			else if((null3[location].x!=0)&&(null3[location].y!=0)
				&&(null3[location].if_clicked==0)&&(null3[location].if_signed==1))
			{
				null3[location].if_signed=0;
				mine_left3++;
			}
			else if((number3[location].x!=0)&&(number3[location].y!=0)
				&&(number3[location].if_clicked==0)&&(number3[location].if_signed==0))
			{
				number3[location].if_signed=1;
				mine_left3--;
			}
			else if((number3[location].x!=0)&&(number3[location].y!=0)
				&&(number3[location].if_clicked==0)&&(number3[location].if_signed==1))
			{
				number3[location].if_signed=0;
				mine_left3++;
			}
			else 
				cout<<"操作无效！"<<endl;
		}
		system("cls");
		if(column<10){
		for(i=0;i<column;i++)
		    cout<<"    "<<i+1;
	    cout<<endl<<" |";
	}
	else 
	{
		for(i=0;i<9;i++)
			cout<<"    "<<i+1;
		for(i=9;i<column;i++)
			cout<<"   "<<i+1;
		cout<<endl<<" |";
	}
	    for(i=0;i<column;i++)
			cout<<"----|";
		cout<<endl;
	for(i=1;i<=row;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=column;j++)
		{
			Square *temp=NULL;
			if((mine3[column*(i-1)+j].x!=0)&&(mine3[column*(i-1)+j].y!=0))
				temp=&mine3[column*(i-1)+j];
			if((null3[column*(i-1)+j].x!=0)&&(null3[column*(i-1)+j].y!=0))
				temp=&null3[column*(i-1)+j];
			if((number3[column*(i-1)+j].x!=0)&&(number3[column*(i-1)+j].y!=0))
				temp=&number3[column*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl<<" |";
		for(int k=0;k<column;k++)
			cout<<"----|";
		cout<<endl;
	}cout<<"现在剩余"<<mine_left3<<"颗雷。"<<endl;
	int unclicked_left=row*column-lei; 
	for(i=0;i<row*column+1;i++)
	{
		if(number3[i].x!=0&&number3[i].if_clicked==1)
			unclicked_left--;
		if(null3[i].x!=0&&null3[i].if_clicked==1)
			unclicked_left--;
	}
	if(unclicked_left==0)
	{
		system("cls");
		if(column<10){
		for(i=0;i<column;i++)
		    cout<<"    "<<i+1;
	    cout<<endl<<" |";
	}
	else 
	{
		for(i=0;i<9;i++)
			cout<<"    "<<i+1;
		for(i=9;i<column;i++)
			cout<<"   "<<i+1;
		cout<<endl<<" |";
	}
	    for(i=0;i<column;i++)
			cout<<"----|";
		cout<<endl;
	for(i=1;i<=row;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=column;j++)
		{
			Square *temp=NULL;
			if((mine3[column*(i-1)+j].x!=0)&&(mine3[column*(i-1)+j].y!=0))
				temp=&mine3[column*(i-1)+j];
			if((null3[column*(i-1)+j].x!=0)&&(null3[column*(i-1)+j].y!=0))
				temp=&null3[column*(i-1)+j];
			if((number3[column*(i-1)+j].x!=0)&&(number3[column*(i-1)+j].y!=0))
				temp=&number3[column*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl<<" |";
		for(int k=0;k<column;k++)
			cout<<"----|";
		cout<<endl;
	}cout<<"现在剩余0颗雷。"<<endl;
		throw winerror;
	}
}
}
void expend3(int e_x,int e_y)
{
	if(map3[e_x][e_y]==0)
	{
		for(int k=0;k<3;k++)
			for(int m=0;m<3;m++)
			{
				if((e_x+directions[k]<=row)&&(e_x+directions[k]>=1)
					&&e_y+directions[m]<=column&&(e_y+directions[m]>=1)
					&&(!(directions[k]==0&&directions[m]==0))
					&&(null3[column*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked==0)&&
					(null3[column*(e_x+directions[k]-1)+e_y+directions[m]].if_signed==0))
				{
					null3[column*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked=1;
					number3[column*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked=1;
					expend3(e_x+directions[k],e_y+directions[m]);
				}
			}
	}
	else if(map3[e_x][e_y]==2&&number3[column*(e_x-1)+e_y].if_signed==0)
	{
		number3[column*(e_x-1)+e_y].if_clicked=1;
		null3[column*(e_x-1)+e_y].if_clicked=1;
	}
}
