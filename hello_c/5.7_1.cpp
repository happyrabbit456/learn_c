#include <cstdio>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std; 
void gotoxy(int y,int x){
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x;scrn.Y=y;
	SetConsoleCursorPosition(hOuput,scrn) ;
}
void tixe(){
	for(int i=1;i<=22;i++){
		for(int y=1;y<=70;y++){
			if(i==1||i==22){
				cout<<"*";
			}
			else if(y==1||y==70){
				cout<<"*";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
int main()
{
	tixe();
	int a=1,b=1,aSpeed=1,bSpeed=1;
	while(1){
		gotoxy(b,a);
		cout<<'o';
		sleep(1);
		gotoxy(b,a);
		cout<<' ';
		a+=aSpeed;
		b+=bSpeed;
		if(a>=68||a<=1){
			aSpeed=-aSpeed;
		}
		if(b>=20||b<=1){
			bSpeed=-bSpeed;
		}
	} 
	return 0;
}
