#include <cstdio> 
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std;

int width=70;
int height=22;

struct plane{
	int x,y;
	int w,h;
};
struct bullet{
	int x,y;
	char type;
	int flag;
};
struct Monster{
	int x,y;
	char type;
	int flag;
}; 
void initALLBullet(struct bullet arr[],int num){
	for(int i=0;i<num;i++){
		arr[i].flag=1;
	}
}
void gotoxy(int y,int x){
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x,scrn.Y=y;
	SetConsoleCursorPosition(hOuput,scrn);
}
void drawALLBullet(struct bullet arr[],int num){
	for(int i=0;i<num;i++){
		if(arr[i].flag==1){
			continue;
		}
		gotoxy(arr[i].y,arr[i].x-1);
		cout<<arr[i].type;
	}
}
void updateALLBullet(struct bullet arr[],int num){
	for(int i=0;i<num;i++){
		if(arr[i].flag==1){
			continue;
		}
		gotoxy(arr[i].y,arr[i].x-1);
		cout<<" ";
		arr[i].y--;
		if(arr[i].y<2){
			arr[i].flag=1;
		}
	}
}
void producebullet(struct bullet arr[],int num,struct plane p){
	for(int i=0;i<num;i++){
		if(arr[i].flag==1){
			arr[i].y=p.y-1;
			arr[i].x=p.x+1;
			arr[i].type='+';
			arr[i].flag=0;
			return;
		}
	}
}
void drawInterface(){
	for(int i=1;i<=70;i++) std::cout<<"-";
	std::cout<<"\n";
	for(int j=1;j<=20;j++){
		for(int i=1;i<=70;i++){
			if(i==1||i==70){
				std::cout<<"|";
			}
			else{
				std::cout<<" ";
			}
		}
		std::cout<<"\n";
	}
	for(int i=1;i<=70;i++) std::cout<<"-";
}
void drawP(struct plane p){
	gotoxy(p.y,p.x);
	std::cout<<"|";
	gotoxy(p.y+1,p.x-1);
	std::cout<<"/|\\";
}
void clearP(struct plane p){
	gotoxy(p.y,p.x);
	std::cout<<"   ";
	gotoxy(p.y+1,p.x-1);
	std::cout<<"   ";
}
void goLeft(struct plane *p){
	if(p->x<2+1){
		return;
	}
	p->x--;
}
void goRight(struct plane *p){
	if(p->x+p->w > width-2){
		return;
	}
	p->x++;
}
void goUp(struct plane *p){
	if(p->y<2){
		return;
	}
	p->y--;
}
void goDown(struct plane *p){
	if(p->y+p->h>height-2){
		return;
	}
	p->y++;
}
void controlP(struct plane *p){
	int res=kbhit();
	if(res>0){
		char ch=getch();
		clearP(*p);
		switch(ch) {
			case 'a':
			    goLeft(p);
			    break;
			case 'w':
			    goUp(p);
			    break;
			case 'd':
			    goRight(p);
			    break;
			case 's':
			    goDown(p);
			    break;
			default:
				break;	
		}
		drawP(*p);
	}
}
void initALLMonster(struct Monster arr[],int num){
	for(int i=0;i<num;i++){
		arr[i].flag=1;
	}
}
void drawALLMonster(struct Monster arr[],int num){
	for(int i=0;i<num;i++){
		if(arr[i].flag==1){
			continue;
		}
		gotoxy(arr[i].y,arr[i].x);
		cout<<arr[i].type;
	}
}
void updateALLMonster(struct Monster arr[],int num){
	for(int i=0;i<num;i++){
		if(arr[i].flag==1){
			continue;
		}
		gotoxy(arr[i].y,arr[i].x);
		cout<<" ";
		arr[i].y++;
		if(arr[i].y>20){
			arr[i].flag=1;
		}
	}
}
void produceMonster(struct Monster arr[],int num){
	for(int i=0;i<num;i++){
		if(arr[i].flag==1){
			arr[i].y=1;
			arr[i].x=rand()%(70-4)+2;
			arr[i].type='@';
			arr[i].flag=0;
			return;
		}
	}
}
void checkCollision(struct bullet bArr[],int bnum,Monster mArr[],int mnum){
	for(int i=0;i<bnum;i++){
		if(bArr[i].flag==1){
			continue;
		}
		for(int j=0;j<mnum;j++){
			if(mArr[j].flag==1){
				continue;
			}
			if((bArr[i].x==mArr[j].x&&bArr[i].y==mArr[j].y)||
			(bArr[i].x==mArr[j].x&&bArr[i].y<mArr[j].y)){
				bArr[i].flag=1;
				mArr[j].flag=1;
			}
		}
	}
}
bool checkGameOver(struct Monster arr[],int num,struct plane p){
	for(int i=0;i<num;i++)	{
		if(arr[i].flag==1){
			continue;
		}
		if((arr[i].x>=p.x&&arr[i].x<p.x+p.w)&&
		   (arr[i].y>=p.y&&arr[i].y<p.y+p.h)){
//			printf("Game Over!");
//			exit(0);
//			system("pause");
			return true;
		}
	}
	return false;
}
int main(){
	bool bCheck=false;
	drawInterface();
	struct plane Plane = {70/2-1,22-3,3,2};
	drawP(Plane);
	struct bullet array[25];
	initALLBullet(array,25);
	struct Monster monsterArray[70];
	initALLMonster(monsterArray,70);
	int count=0;
//	cout<<Plane.w<<" "<<Plane.h<<endl;	
	while(1){
		controlP(&Plane);
		if(count%3==0){
			producebullet(array,25,Plane);
		}
		if(count%6==0){
			produceMonster(monsterArray,70);
		}
		drawALLBullet(array,25);
		drawALLMonster(monsterArray,70);
		usleep(60000);
		updateALLMonster(monsterArray,70);
		updateALLBullet(array,25);
		
		checkCollision(array,25,monsterArray,70);

		bCheck = checkGameOver(monsterArray,70,Plane);
		if(bCheck)
		{
			break;
		}
		count++;
	}
	
	if(bCheck)
	{
		system("cls");
		gotoxy(10,50);
		cout<<"Game over..."<<endl;
	}
	return 0;
}
