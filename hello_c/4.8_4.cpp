#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	//s,0=������r,1=ʯͷ��p,2=���� 
	char b,a;//a:���� b:me 
	cout<<"�������������"<<endl; 
	int lose=0,win=0;//������Ӯ���� 
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
			cout<<"����Ӯ��!"; 
			win++;
		}
		if((a=='s'&&b=='r')
		||(a=='r'&&b=='p')
		||(a=='p'&&b=='s')){
			cout<<"�������ˣ�";
			lose++;
		} 
		
		if(a==b) cout<<"ƽ�֣�";

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
