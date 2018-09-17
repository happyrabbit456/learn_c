#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	//s,0=剪刀；r,1=石头；p,2=布； 
	char b,a;//a:电脑 b:me 
	cout<<"先输入比赛场数"<<endl; 
	int lose=0,win=0;//电脑输赢次数 
	int total;
	cin>>total;
	while(true){
		cin>>b;
		srand(time(NULL));
		int n=rand()%3;
		if(n==0) a='s';
		else if(n==1) a='r';
		else a='p';
		
		if((a=='s'&&b=='p') 
		||(a=='r'&&b=='s')
		||(a=='p'&&b=='r')){
			cout<<"电脑赢了!"; 
			win++;
		}
		if((a=='s'&&b=='r')
		||(a=='r'&&b=='p')
		||(a=='p'&&b=='s')){
			cout<<"电脑输了！";
			lose++;
		} 
		
		if(a==b) cout<<"平手！";

		if(b=='q') break;
		if(win>total/2){
			cout<<"You are out!";
			break;
		}
		else if(lose>total/2){
			cout<<"You are win!";
			break;
		}
	}
	
	cout<<endl;
	return 0; 
}
