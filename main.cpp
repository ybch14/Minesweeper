#include <iostream>
#include <fstream>
#include "mine.h"
using namespace std;
int row=0;int column=0;int lei=0;
MineSquare *mine3=NULL;
NullSquare *null3=NULL;
NumberSquare *number3=NULL;
int **map3=NULL;
int main()
{
	void preface();
	preface();
	ifstream infile("record.txt",ios::in);
	ofstream outfile("record.txt",ios::out);
	int easy_win=0,easy_lose=0,hard_win=0,hard_lose=0;
	infile>>easy_win>>easy_lose>>hard_win>>hard_lose;
	infile.close();
	infile.clear();
	int choose=0;
	for(int count=0;;count++){
	cout<<"��ѡ����Ϸģʽ��1 �� 2 ���� 3 �Զ���"<<endl;
	int order;cin>>order;
	if(order==1){
		system("cls");
	void set_map1();
	set_map1();
	void operate1();
	try
	{
		operate1();
	}
	catch(int)
	{
		easy_lose++;
		cout<<"������˼�������ˣ��´����ˣ�"<<endl;
		cout<<"��ǰʤ����"<<easy_win<<endl;
		cout<<"��ǰ������"<<easy_lose<<endl;
		cout<<"��ǰʤ�ʣ�"<<((double)easy_win*100/double(easy_win+easy_lose))<<"%"<<endl;;
		cout<<"1 ����һ�� 2 �˳�"<<endl;
	    cin>>choose;
		if(choose==1)
		{
			outfile.seekp(ios_base::beg);
			outfile<<easy_win<<" "<<easy_lose<<" "<<hard_win<<" "<<hard_lose;
		}
	    else if(choose==2)
		{
			outfile.seekp(ios_base::beg);
			outfile<<0<<" "<<0<<" "<<0<<" "<<0;
			outfile.close();
			outfile.clear();
			return 0;
		}

	}
	catch(double)
	{
		easy_win++;
		cout<<"��ϲ�㣬��Ӯ�ˣ�"<<endl;
		cout<<"��ǰʤ����"<<easy_win<<endl;
		cout<<"��ǰ������"<<easy_lose<<endl;
		cout<<"��ǰʤ�ʣ�"<<((double)easy_win*100/(double)(easy_win+easy_lose))<<"%"<<endl;
		cout<<"1 ����һ�� 2 �˳�"<<endl;
	    cin>>choose;
	    if(choose==2)
			return 0;
	}}
	else if(order==2){
		system("cls");
		void set_map2();
		set_map2();
		void operate2();
		try
		{
			operate2();
		}
		catch(int)
		{
			hard_lose++;
			cout<<"������˼�������ˣ��´����ˣ�"<<endl;
			cout<<"��ǰʤ����"<<hard_win<<endl;
		    cout<<"��ǰ������"<<hard_lose<<endl;
		    cout<<"��ǰʤ�ʣ�"<<((double)hard_win*100/(double)(hard_win+hard_lose))<<"%"<<endl;
			cout<<"1 ����һ�� 2 �˳�"<<endl;
	        cin>>choose;
	        if(choose==1)
		    {
			    outfile.seekp(ios_base::beg);
			    outfile<<easy_win<<" "<<easy_lose<<" "<<hard_win<<" "<<hard_lose;
		    }
	        else if(choose==2)
		    {
			    outfile.seekp(ios_base::beg);
			    outfile<<0<<" "<<0<<" "<<0<<" "<<0;
			    outfile.close();
			    outfile.clear();
			    return 0;
		    }
	    }
	    catch(double)
	    {
			hard_win++;
		    cout<<"��ϲ�㣬��Ӯ�ˣ�"<<endl;
			cout<<"��ǰʤ����"<<hard_win<<endl;
		    cout<<"��ǰ������"<<hard_lose<<endl;
		    cout<<"��ǰʤ�ʣ�"<<((double)hard_win*100/(double)(hard_win+hard_lose))<<"%"<<endl;
			cout<<"1 ����һ�� 2 �˳�"<<endl;
	        cin>>choose;
	        if(choose==1)
		    {
			    outfile.seekp(ios_base::beg);
			    outfile<<easy_win<<" "<<easy_lose<<" "<<hard_win<<" "<<hard_lose;
		    }
	        else if(choose==2)
		    {
			    outfile.seekp(ios_base::beg);
			    outfile<<0<<" "<<0<<" "<<0<<" "<<0;
			    outfile.close();
			    outfile.clear();
			    return 0;
		    }
	    }
	}
	else if(order==3)
	{
		
	    cout<<"�������ȣ�����Ϊ14����";
		cin>>column;
	    while((column>14))
	    {
		    cout<<"������������ԣ�"<<endl;
	        cout<<"�������ȣ�����Ϊ14����";
			cin>>column;
	    }
	    cout<<"������߶ȣ�����Ϊ18����";
		cin>>row;
	    while(column>18)
	    {
		    cout<<"������������ԣ�"<<endl;
		    cout<<"������߶ȣ�����Ϊ18����";
			cin>>row;
	    }
	    cout<<"�������׵ĸ���������Ϊ��ȡ��߶ȵ�һ�룩��";
		cin>>lei;
	    while(lei>column*row/2)
	    {
		    cout<<"������������ԣ�"<<endl;
		    cout<<"�������׵ĸ���������Ϊ��ȡ��߶ȵ�һ�룩��";
			cin>>lei;
	    }
		void zidingyi();
		try
		{
			zidingyi();
		}
		catch(int)
		{
			cout<<"������˼�������ˣ��´����ˣ�"<<endl;
			cout<<"1 ����һ�� 2 �˳�"<<endl;
	        cin>>choose;
	        if(choose==2)
			{
                delete []mine3;
		        mine3=NULL;
		        delete []null3;
		        null3=NULL;
		        delete []number3;
		        number3=NULL;
		        for(int k=0;k<row;k++)
		        {
			        delete []map3[k];
			       map3[k]=NULL;
		       }
		       delete []map3;
		       return 0;
			}
	    }
	    catch(double)
	    {
		    cout<<"��ϲ�㣬��Ӯ�ˣ�"<<endl;
	 		cout<<"1 ����һ�� 2 �˳�"<<endl;
	        cin>>choose;
	        if(choose==2)
			{
                delete []mine3;
		        mine3=NULL;
		        delete []null3;
		        null3=NULL;
		        delete []number3;
		        number3=NULL;
		        for(int k=0;k<row;k++)
		        {
			        delete []map3[k];
			        map3[k]=NULL;
		        }
		        delete []map3;
		        return 0;
			}
	    }
		delete []mine3;
		mine3=NULL;
		delete []null3;
		null3=NULL;
		delete []number3;
		number3=NULL;
		for(int k=0;k<row;k++)
		{
			delete []map3[k];
			map3[k]=NULL;
		}
		delete []map3;
	}
	}
	return 0;
}
