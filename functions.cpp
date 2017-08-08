#include <iostream>
#include <ctime>
#include "mine.h"
using namespace std;
int i=0,j=0;int mine_left1=10;int mine_left2=20;
const int directions[3]={0,1,-1};
MineSquare mine[83];NullSquare null[83];NumberSquare number[83];
int minenumber[10];
int map1[11][11];
MineSquare mine2[146];NullSquare null2[146];NumberSquare number2[146];
int minenumber2[20];
int map2[14][14];
//初始化地图
void set_map1()
{
	for(i=0;i<83;i++)
	{
		mine[i]=MineSquare(0,0,0,0);
		null[i]=NullSquare(0,0,0,0);
		number[i]=NumberSquare(0,0,0,0,0);
	}
	void expend1(int e_x,int e_y);
	for(i=0;i<11;i++)
		for(j=0;j<11;j++)
			map1[i][j]=0;
	int buffer[82],k=0,n=0;
	for(i=0;i<82;i++)
		buffer[i]=i;
	srand((unsigned)time(NULL));
	for(i=0;i<10;i++)
	{
		k=rand()%81+1;
		n=buffer[k];
		while(n==-1)
		{
			k=rand()%81+1;
			n=buffer[k];
		}
		minenumber[i]=n;
		buffer[k]=-1;
	}
	//minenumber[9]=81;
	for(i=0;i<10;i++)
	{
		if(minenumber[i]%9==0)
		{
			mine[minenumber[i]]=MineSquare(0,0,minenumber[i]/9,9);
			map1[minenumber[i]/9][9]=1;
		}
		else 
		{
			mine[minenumber[i]]=MineSquare(0,0,minenumber[i]/9+1,minenumber[i]%9);
			map1[minenumber[i]/9+1][minenumber[i]%9]=1;
		}
	}
	int number_of_mine=0;
	for(i=1,number_of_mine=0;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			number_of_mine=0;
			if((map1[i][j]==0)&&(map1[i-1][j-1]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i][j-1]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i+1][j-1]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i-1][j]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i+1][j]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i-1][j+1]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i][j+1]==1))
				number_of_mine++;
			if((map1[i][j]==0)&&(map1[i+1][j+1]==1))
				number_of_mine++;
			if((number_of_mine==0)&&(map1[i][j]==0))
				null[9*(i-1)+j]=NullSquare(0,0,i,j);
			if((number_of_mine!=0)&&(map1[i][j]==0))
			{
				number[9*(i-1)+j]=NumberSquare(0,0,i,j,number_of_mine);
				map1[i][j]=2;
			}
		}
	}
	cout<<"    1    2    3    4    5    6    7    8    9 "<<endl;
	cout<<" |----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=9;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=9;j++)
		{
			Square *temp=NULL;
			if((mine[9*(i-1)+j].x!=0)&&(mine[9*(i-1)+j].y!=0))
				temp=&mine[9*(i-1)+j];
			if((null[9*(i-1)+j].x!=0)&&(null[9*(i-1)+j].y!=0))
				temp=&null[9*(i-1)+j];
			if((number[9*(i-1)+j].x!=0)&&(number[9*(i-1)+j].y!=0))
				temp=&number[9*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}cout<<"现在剩余"<<10<<"颗雷。"<<endl;
}
//操作
void operate1()
{
	char temp=0;int tempx=0,tempy=0;int order=0,location=0;
	int enderror=0;double winerror=0.0;
	for(int count=0;;count++)
	{
	    cout<<"请选择目标点的坐标，\n横纵坐标用空格分隔,字母在前数字在后："<<endl;
	    cin>>temp>>tempy;
	    tempx=(int)temp-64;
		location=9*(tempx-1)+tempy;
		cout<<"请选择你要执行的操作：1 点击 2 标记为雷或取消标记："<<endl;
	    cin>>order;
	    if((order!=1)&&(order!=2))
		    continue;
	    else if(order==1)
		{
			if((mine[location].x!=0)&&(mine[location].y!=0)
				&&(mine[location].if_clicked==0)&&(mine[location].if_signed==0))
			{
				mine[location].if_clicked=1;
				for(int k=0;k<82;k++)
				{
					if((mine[k].x!=0)&&(mine[k].y!=0))
					{
						mine[k].if_signed=0;
						mine[k].if_clicked=1;
					}
					if((null[k].x!=0)&&(null[k].y!=0))
					{
						null[k].if_signed=0;
						null[k].if_clicked=1;
					}
				    if((number[k].x!=0)&&(number[k].y!=0))
					{
						number[k].if_signed=0;
						number[k].if_clicked=1;
					}
				}
				system("cls");
				cout<<"    1    2    3    4    5    6    7    8    9 "<<endl;
	            cout<<" |----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=9;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=9;j++)
		{
			Square *temp=NULL;
			if((mine[9*(i-1)+j].x!=0)&&(mine[9*(i-1)+j].y!=0))
				temp=&mine[9*(i-1)+j];
			if((null[9*(i-1)+j].x!=0)&&(null[9*(i-1)+j].y!=0))
				temp=&null[9*(i-1)+j];
			if((number[9*(i-1)+j].x!=0)&&(number[9*(i-1)+j].y!=0))
				temp=&number[9*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}
				throw enderror;
			}
			else if((number[location].x!=0)&&(number[location].y!=0)
				&&(number[location].if_clicked==0)&&(number[location].if_signed==0))
				number[location].if_clicked=1;
			else if((null[location].x!=0)&&(null[location].y!=0)
				&&(null[location].if_clicked==0)&&(null[location].if_signed==0))
			{
				null[location].if_clicked=1;
				expend1(tempx,tempy);
			}
			else 
				cout<<"该坐标无法被点击！"<<endl;
		}
		else if(order==2)
		{
			if((mine[location].x!=0)&&(mine[location].y!=0)
				&&(mine[location].if_clicked==0)&&(mine[location].if_signed==0))
			{
				mine[location].if_signed=1;
				mine_left1--;
			}
			else if((mine[location].x!=0)&&(mine[location].y!=0)
				&&(mine[location].if_clicked==0)&&(mine[location].if_signed==1))
			{
				mine[location].if_signed=0;
				mine_left1++;
			}
			else if((null[location].x!=0)&&(null[location].y!=0)
				&&(null[location].if_clicked==0)&&(null[location].if_signed==0))
			{
				null[location].if_signed=1;
				mine_left1--;
			}
			else if((null[location].x!=0)&&(null[location].y!=0)
				&&(null[location].if_clicked==0)&&(null[location].if_signed==1))
			{
				null[location].if_signed=0;
				mine_left1++;
			}
			else if((number[location].x!=0)&&(number[location].y!=0)
				&&(number[location].if_clicked==0)&&(number[location].if_signed==0))
			{
				number[location].if_signed=1;
				mine_left1--;
			}
			else if((number[location].x!=0)&&(number[location].y!=0)
				&&(number[location].if_clicked==0)&&(number[location].if_signed==1))
			{
				number[location].if_signed=0;
				mine_left1++;
			}
			else 
				cout<<"操作无效！"<<endl;
		}
		system("cls");
		cout<<"    1    2    3    4    5    6    7    8    9 "<<endl;
	    cout<<" |----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=9;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=9;j++)
		{
			Square *temp=NULL;
			if((mine[9*(i-1)+j].x!=0)&&(mine[9*(i-1)+j].y!=0))
				temp=&mine[9*(i-1)+j];
			if((null[9*(i-1)+j].x!=0)&&(null[9*(i-1)+j].y!=0))
				temp=&null[9*(i-1)+j];
			if((number[9*(i-1)+j].x!=0)&&(number[9*(i-1)+j].y!=0))
				temp=&number[9*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}cout<<"现在剩余"<<mine_left1<<"颗雷。"<<endl;
    int unclicked_left=71; 
	for(i=0;i<82;i++)
	{
		if(number[i].x!=0&&number[i].if_clicked==1)
			unclicked_left--;
		if(null[i].x!=0&&null[i].if_clicked==1)
			unclicked_left--;
	}
	if(unclicked_left==0)
	{
		system("cls");
			cout<<"    1    2    3    4    5    6    7    8    9 "<<endl;
	        cout<<" |----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=9;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=9;j++)
		{
			Square *temp=NULL;
			if((mine[9*(i-1)+j].x!=0)&&(mine[9*(i-1)+j].y!=0))
				temp=&mine[9*(i-1)+j];
			if((null[9*(i-1)+j].x!=0)&&(null[9*(i-1)+j].y!=0))
				temp=&null[9*(i-1)+j];
			if((number[9*(i-1)+j].x!=0)&&(number[9*(i-1)+j].y!=0))
				temp=&number[9*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}cout<<"现在剩余0颗雷。"<<endl;
		throw winerror;
	}
}
}
void expend1(int e_x,int e_y)
{
	if(map1[e_x][e_y]==0)
	{
		for(int k=0;k<3;k++)
			for(int m=0;m<3;m++)
			{
				if((e_x+directions[k]<=9)&&(e_x+directions[k]>=1)
					&&(e_y+directions[m]<=9)&&(e_y+directions[m]>=1)
					&&(!(directions[k]==0&&directions[m]==0))
					&&(null[9*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked==0)&&
					(null[9*(e_x+directions[k]-1)+e_y+directions[m]].if_signed==0))
				{
					null[9*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked=1;
					number[9*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked=1;
					expend1(e_x+directions[k],e_y+directions[m]);
				}
			}
	}
	else if(map1[e_x][e_y]==2&&number[9*(e_x-1)+e_y].if_signed==0)
	{
		number[9*(e_x-1)+e_y].if_clicked=1;
		null[9*(e_x-1)+e_y].if_clicked=1;
	}
}
void set_map2()
{
	for(i=0;i<146;i++)
	{
		mine2[i]=MineSquare(0,0,0,0);
		null2[i]=NullSquare(0,0,0,0);
		number2[i]=NumberSquare(0,0,0,0,0);
	}
	void expend2(int e_x,int e_y);
	for(i=0;i<14;i++)
		for(j=0;j<14;j++)
			map2[i][j]=0;
	int buffer[145],k=0,n=0;
	for(i=0;i<145;i++)
		buffer[i]=i;
	srand((unsigned)time(NULL));
	for(i=0;i<20;i++)
	{
		k=rand()%144+1;
		n=buffer[k];
		while(n==-1)
		{
			k=rand()%144+1;
			n=buffer[k];
		}
		minenumber2[i]=n;
		buffer[k]=-1;
	}
	for(i=0;i<20;i++)
	{
		if(minenumber2[i]%12==0)
		{
			mine2[minenumber2[i]]=MineSquare(0,0,minenumber2[i]/12,12);
			map2[minenumber2[i]/12][12]=1;
		}
		else 
		{
			mine2[minenumber2[i]]=MineSquare(0,0,minenumber2[i]/12+1,minenumber2[i]%12);
			map2[minenumber2[i]/12+1][minenumber2[i]%12]=1;
		}
	}
	int number_of_mine=0;
	for(i=1,number_of_mine=0;i<=12;i++)
	{
		for(j=1;j<=12;j++)
		{
			number_of_mine=0;
			if((map2[i][j]==0)&&(map2[i-1][j-1]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i][j-1]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i+1][j-1]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i-1][j]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i+1][j]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i-1][j+1]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i][j+1]==1))
				number_of_mine++;
			if((map2[i][j]==0)&&(map2[i+1][j+1]==1))
				number_of_mine++;
			if((number_of_mine==0)&&(map2[i][j]==0))
				null2[12*(i-1)+j]=NullSquare(0,0,i,j);
			if((number_of_mine!=0)&&(map2[i][j]==0))
			{
				number2[12*(i-1)+j]=NumberSquare(0,0,i,j,number_of_mine);
				map2[i][j]=2;
			}
		}
	}
	cout<<"    1    2    3    4    5    6    7    8    9   10   11   12"<<endl;
	cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=12;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=12;j++)
		{
			Square *temp=NULL;
			if((mine2[12*(i-1)+j].x!=0)&&(mine2[12*(i-1)+j].y!=0))
				temp=&mine2[12*(i-1)+j];
			if((null2[12*(i-1)+j].x!=0)&&(null2[12*(i-1)+j].y!=0))
				temp=&null2[12*(i-1)+j];
			if((number2[12*(i-1)+j].x!=0)&&(number2[12*(i-1)+j].y!=0))
				temp=&number2[12*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}cout<<"现在剩余"<<20<<"颗雷。"<<endl;
}
void operate2()
{
	char temp=0;int tempx=0,tempy=0;int order=0,location=0;
	int enderror=0;double winerror=0.0;
	for(int count=0;;count++)
	{
	    cout<<"请选择目标点的坐标，\n横纵坐标用空格分隔,字母在前数字在后："<<endl;
	    cin>>temp>>tempy;
	    tempx=(int)temp-64;
		location=12*(tempx-1)+tempy;
		cout<<"请选择你要执行的操作：1 点击 2 标记为雷或取消标记："<<endl;
	    cin>>order;
	    if((order!=1)&&(order!=2))
		    continue;
	    else if(order==1)
		{
			if((mine2[location].x!=0)&&(mine2[location].y!=0)
				&&(mine2[location].if_clicked==0)&&(mine2[location].if_signed==0))
			{
				mine2[location].if_clicked=1;
				for(int k=0;k<145;k++)
				{
					if((mine2[k].x!=0)&&(mine2[k].y!=0))
					{
						mine2[k].if_signed=0;
						mine2[k].if_clicked=1;
					}
					if((null2[k].x!=0)&&(null2[k].y!=0))
					{
						null2[k].if_signed=0;
						null2[k].if_clicked=1;
					}
				    if((number2[k].x!=0)&&(number2[k].y!=0))
					{
						number2[k].if_signed=0;
						number2[k].if_clicked=1;
					}
				}
				system("cls");
				cout<<"    1    2    3    4    5    6    7    8    9   10   11   12  "<<endl;
	            cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=12;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=12;j++)
		{
			Square *temp=NULL;
			if((mine2[12*(i-1)+j].x!=0)&&(mine2[12*(i-1)+j].y!=0))
				temp=&mine2[12*(i-1)+j];
			if((null2[12*(i-1)+j].x!=0)&&(null2[12*(i-1)+j].y!=0))
				temp=&null2[12*(i-1)+j];
			if((number2[12*(i-1)+j].x!=0)&&(number2[12*(i-1)+j].y!=0))
				temp=&number2[12*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}
				throw enderror;
			}
			else if((number2[location].x!=0)&&(number2[location].y!=0)
				&&(number2[location].if_clicked==0)&&(number2[location].if_signed==0))
				number2[location].if_clicked=1;
			else if((null2[location].x!=0)&&(null2[location].y!=0)
				&&(null2[location].if_clicked==0)&&(null2[location].if_signed==0))
			{
				null2[location].if_clicked=1;
				expend2(tempx,tempy);
			}
			else 
				cout<<"该坐标无法被点击！"<<endl;
		}
		else if(order==2)
		{
			if((mine2[location].x!=0)&&(mine2[location].y!=0)
				&&(mine2[location].if_clicked==0)&&(mine2[location].if_signed==0))
			{
				mine2[location].if_signed=1;
				mine_left2--;
			}
			else if((mine2[location].x!=0)&&(mine2[location].y!=0)
				&&(mine2[location].if_clicked==0)&&(mine2[location].if_signed==1))
			{
				mine2[location].if_signed=0;
				mine_left2++;
			}
			else if((null2[location].x!=0)&&(null2[location].y!=0)
				&&(null2[location].if_clicked==0)&&(null2[location].if_signed==0))
			{
				null2[location].if_signed=1;
				mine_left2--;
			}
			else if((null2[location].x!=0)&&(null2[location].y!=0)
				&&(null2[location].if_clicked==0)&&(null2[location].if_signed==1))
			{
				null2[location].if_signed=0;
				mine_left2++;
			}
			else if((number2[location].x!=0)&&(number2[location].y!=0)
				&&(number2[location].if_clicked==0)&&(number2[location].if_signed==0))
			{
				number2[location].if_signed=1;
				mine_left2--;
			}
			else if((number2[location].x!=0)&&(number2[location].y!=0)
				&&(number2[location].if_clicked==0)&&(number2[location].if_signed==1))
			{
				number2[location].if_signed=0;
				mine_left2++;
			}
			else 
				cout<<"操作无效！"<<endl;
		}
		system("cls");
		cout<<"    1    2    3    4    5    6    7    8    9   10   11   12"<<endl;
	    cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=12;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=12;j++)
		{
			Square *temp=NULL;
			if((mine2[12*(i-1)+j].x!=0)&&(mine2[12*(i-1)+j].y!=0))
				temp=&mine2[12*(i-1)+j];
			if((null2[12*(i-1)+j].x!=0)&&(null2[12*(i-1)+j].y!=0))
				temp=&null2[12*(i-1)+j];
			if((number2[12*(i-1)+j].x!=0)&&(number2[12*(i-1)+j].y!=0))
				temp=&number2[12*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}cout<<"现在剩余"<<mine_left2<<"颗雷。"<<endl;
	int unclicked_left=124; 
	for(i=0;i<145;i++)
	{
		if(number2[i].x!=0&&number2[i].if_clicked==1)
			unclicked_left--;
		if(null2[i].x!=0&&null2[i].if_clicked==1)
			unclicked_left--;
	}
	if(unclicked_left==0)
	{
		system("cls");
			cout<<"    1    2    3    4    5    6    7    8    9   10   11   12"<<endl;
	        cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|"<<endl;
	for(i=1;i<=12;i++)
	{
		cout<<char('A'+i-1)<<"|";
		for(j=1;j<=12;j++)
		{
			Square *temp=NULL;
			if((mine2[12*(i-1)+j].x!=0)&&(mine2[12*(i-1)+j].y!=0))
				temp=&mine2[12*(i-1)+j];
			if((null2[12*(i-1)+j].x!=0)&&(null2[12*(i-1)+j].y!=0))
				temp=&null2[12*(i-1)+j];
			if((number2[12*(i-1)+j].x!=0)&&(number2[12*(i-1)+j].y!=0))
				temp=&number2[12*(i-1)+j];
			cout<<" ";
			temp->show();
			cout<<" |";
		}
		cout<<endl;cout<<" |----|----|----|----|----|----|----|----|----|----|----|----|";
		cout<<endl;
	}cout<<"现在剩余0颗雷。"<<endl;
		throw winerror;
	}
}
}
void expend2(int e_x,int e_y)
{
	if(map2[e_x][e_y]==0)
	{
		for(int k=0;k<3;k++)
			for(int m=0;m<3;m++)
			{
				if((e_x+directions[k]<=12)&&(e_x+directions[k]>=1)
					&&(e_y+directions[m]<=12)&&(e_y+directions[m]>=1)
					&&(!(directions[k]==0&&directions[m]==0))
					&&(null2[12*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked==0)&&
					(null2[12*(e_x+directions[k]-1)+e_y+directions[m]].if_signed==0))
				{
					null2[12*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked=1;
					number2[12*(e_x+directions[k]-1)+e_y+directions[m]].if_clicked=1;
					expend2(e_x+directions[k],e_y+directions[m]);
				}
			}
	}
	else if(map2[e_x][e_y]==2&&number2[12*(e_x-1)+e_y].if_signed==0)
	{
		number2[12*(e_x-1)+e_y].if_clicked=1;
		null2[12*(e_x-1)+e_y].if_clicked=1;
	}
}
void preface()
{
	cout<<"                                    ┏━━━━━━━━━┓ "<<endl;
	cout<<"    ┏━┓                          ┃                  ┃ "<<endl;
	cout<<"    ┃  ┃    ┏━━━━━━┓      ┗━━━┓  ┏━━━┛"<<endl;
	cout<<"    ┃  ┃    ┃            ┃┏━━━━━━┛  ┗━━━━━━┓"<<endl;
	cout<<"┏━┛  ┗━┓┗━━━━┓  ┃┃                              ┃"<<endl;
	cout<<"┃          ┃          ┃  ┃┃  ┏━━━━┓  ┏━━━━┓  ┃"<<endl;
	cout<<"┗━┓  ┏━┛          ┃  ┃┃  ┃ ┏━┓ ┃  ┃ ┏━┓ ┃  ┃"<<endl;
	cout<<"    ┃  ┃    ┏━━━━┛  ┃┃  ┃ ┗━┛ ┃  ┃ ┗━┛ ┃  ┃"<<endl;
	cout<<"    ┃  ┃    ┃            ┃┃  ┃ ┏━┓ ┃  ┃ ┏━┓ ┃  ┃"<<endl;
	cout<<"┏━┛  ┗━┓┗━━━━┓  ┃┗━┛ ┗━┛ ┗━┛ ┗━┛ ┗━┛"<<endl;
	cout<<"┃          ┃          ┃  ┃      ┏━━━━━━━━━┓"<<endl;
	cout<<"┗━┓  ┏━┛          ┃  ┃      ┃                  ┃"<<endl;
	cout<<"    ┃  ┃    ┏━━━━┛  ┃      ┃  ┏━┓  ┏━┓  ┃"<<endl;
	cout<<"┏━┛  ┃    ┃            ┃      ┃  ┗━┛  ┗━┛  ┃"<<endl;
	cout<<"┃      ┃    ┗━━━━━━┛      ┃                  ┃"<<endl;
	cout<<"┗━━━┛                          ┃  ┏━┓  ┏━┓  ┃"<<endl;
	cout<<" M I N E S W E E P                  ┃  ┗━┛  ┗━┛  ┃"<<endl;
	cout<<"       M I N E S W E E P            ┃                  ┃"<<endl;
	cout<<"             M I N E S W E E P      ┗━━━━━━━━━┛"<<endl;
	cout<<"         游戏说明：■为未知方块，▲为已标记方块，※为雷"<<endl;
}