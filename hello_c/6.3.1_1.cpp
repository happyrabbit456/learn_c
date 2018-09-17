#include <iostream> 
#include <cstdio>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>;
using namespace std;
void gotoxy(int a,int b)
{
	COORD scrn;
	HANDLE hOuput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=b;scrn.Y=a;
	SetConsoleCursorPosition(hOuput,scrn);
}
struct nod{
	int x,y;//坐标；
	int a1/*宽 */,b1/*长*/;
	int n/*点数*/; 
};
void clearD(struct nod dice){
	gotoxy(dice.y+2,dice.x+2);
	printf("   ");
	gotoxy(dice.y+3,dice.x+2);
	cout<<"   ";
	gotoxy(dice.y+4,dice.x+2);
	cout<<"   ";
}
void updateD(struct nod*dice){
	dice->n=rand()%6+1;
}
void drawD(struct nod dice){
	for(int i=0;i<dice.a1;i++)
	{
		gotoxy(dice.y,dice.x+i);
		cout<<"-\n";
		gotoxy(dice.y+6,dice.x+i);
		cout<<"-\n";
	}
	for(int i=0;i<dice.b1-2;i++){
		gotoxy(dice.y+1+i,dice.x);
		cout<<"|\n";
		gotoxy(dice.y+1+i,dice.x+6);
		cout<<"|\n";
	}
}
void checkR(int choose,struct nod dice1,struct nod dice2,struct nod dice3){
	int sum=dice1.n+dice2.n+dice3.n;
	gotoxy(dice1.y+9,dice1.x);
	if(choose==0){
		printf("骰子总点数是:%d,",sum);
		if(sum>11){
			printf("你赢了!");
		}else{
			printf("你输了!");
		}
	}
	else if(choose==2){
		printf("骰子总点数是:%d",sum);
		if(sum<=11){
			cout<<"你赢了!";
		}
		else{
			cout<<"你输了!";
		}
	}else{
		cout<<"3个骰子点数不相同,";
		if(dice1.n==dice2.n&&dice2.n==dice3.n){
			cout<<"你赢了!";
		}else{
			cout<<"你输了!";
		}
	}
}
void drawN(struct nod dice){
	switch(dice.n){
		case 1:
		{
			gotoxy(dice.y+3,dice.x+3);
			cout<<"o";
		}
		break;
		case 2:
		{
			gotoxy(dice.y+3,dice.x+2);
			cout<<"o";
			gotoxy(dice.y+3,dice.x+4);
			cout<<"o";
		}
		break;
		case 3:
		{
			gotoxy(dice.y+2,dice.x+2);
			cout<<"o";
			gotoxy(dice.y+3,dice.x+3);
			cout<<"o";
			gotoxy(dice.y+4,dice.x+4);
			cout<<"o";
		}	
		break;
		case 4:
		{
			gotoxy(dice.y+2,dice.x+2);
			cout<<"o";
			gotoxy(dice.y+2,dice.x+4);
			cout<<"o";
			gotoxy(dice.y+4,dice.x+2);
			cout<<"o";
			gotoxy(dice.y+4,dice.x+4);
			cout<<"o";
		}	
		break;
		case 5:{
			gotoxy(dice.y+2,dice.x+2);printf("o\n");
			gotoxy(dice.y+2,dice.x+4);printf("o\n");
			gotoxy(dice.y+3,dice.x+3);printf("o\n");
			gotoxy(dice.y+4,dice.x+2);printf("o\n");
			gotoxy(dice.y+4,dice.x+4);printf("o\n");
		} 
		break;
		case 6:{
			gotoxy(dice.y+2,dice.x+2);printf("o\n");
			gotoxy(dice.y+2,dice.x+4);printf("o\n");
			gotoxy(dice.y+3,dice.x+2);printf("o\n");
			gotoxy(dice.y+3,dice.x+4);printf("o\n");
			gotoxy(dice.y+4,dice.x+2);printf("o\n");
			gotoxy(dice.y+4,dice.x+4);printf("o\n");
			break;
		}
	}
}
void drawDice(struct nod dice){
	drawD(dice);
	drawN(dice);
}
int main()
{
	srand(time(NULL));
	int n1=rand()%6+1;
	struct nod dice1{3,2,7,7,n1};
	int n2=rand()%6+1;
	struct nod dice2{13,2,7,7,n2};
	int n3=rand()%6+1;
	struct nod dice3{23,2,7,7,n3};
//	drawN(dice1);
//	drawD(dice1);
	drawDice(dice1);
	drawDice(dice2);
	drawDice(dice3);
	gotoxy(dice1.y+7,1);
	printf("0买大,1买豹子,2买小\n");
	int choose=-1;
	scanf("%d",&choose);
	for(int i=0;i<20;i++){
		sleep(1);
		clearD(dice1);
		clearD(dice2);
		clearD(dice3);
		updateD(&dice1);
		updateD(&dice2);
		updateD(&dice3);
		drawDice(dice1);
		drawDice(dice2);
		drawDice(dice3);
	} 
	checkR(choose,dice1,dice2,dice3);
	return 0;
}
