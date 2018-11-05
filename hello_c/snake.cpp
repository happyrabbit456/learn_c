#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <iostream>

using namespace std;

int width=60;
int height=22;

struct Food{
	int x;
	int y;
	char type;
	int value;
};

struct Node{
	int x;
	int y;
	struct Node *next;
};

enum Direction{
	Left,Right,Up,Down,
};

//��ʳ���ȫ�ֱ��� 
struct Food food;
struct Node *head=NULL;
struct Node *tail=NULL;
int snakeHp=3;
enum Direction dir=Right;
void checkDirection();
int moveSnake();
void eatFood();
int checkGameOver(); 

void gotoxy(int y, int x){
	COORD scrn;
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X=x;
	scrn.Y=y;
	SetConsoleCursorPosition(hOutput,scrn);	
}

//����Ϸ����
void drawInterface(){	
	for(int i=0;i<height;i+=height-1){
		for(int j=0;j<width;j++){
			gotoxy(i+1,j+1);
			printf("-\n");
		}
	}
	for(int i=0;i<width;i+=width-1){
		for(int j=0;j<height-2;j++){
			gotoxy(j+2,i+1);
			printf("|\n");
		}
	}	
}

//����ʳ��
void produceFood()
{
	char fs[5]={'@','#','%','$','&'};
	srand(time(0));
	int n=rand()%5;
	food.type=fs[n];
	food.value=n+1;
	food.x=rand()%(width-3)+2;
	food.y=rand()%(height-3)+2;
	gotoxy(food.y,food.x);
	printf("%c\n",food.type);
 } 

//������
void produceSnake(){
	struct Node *node1=(struct Node*)malloc(sizeof(struct Node));
	node1->y=height/2;
	node1->x=20;
	node1->next=NULL;
	struct Node *node2=(struct Node*)malloc(sizeof(struct Node));
	node2->y=height/2;
	node2->x=19;
	node2->next=node1;
	struct Node *node3=(struct Node*)malloc(sizeof(struct Node));
	node3->y=height/2;
	node3->x=18;
	node3->next=node2;
	
	tail=node3; //�൱������ͷ 
	head=node1;	
} 

//����
void drawSnake(struct Node *head) {
	while(head != NULL){
		gotoxy(head->y, head->x);
		printf("*\n");
		head=head->next;
	}
}

void checkDirection(){
	int res=kbhit();
	if(res>0){
		char ch=getch();
		switch(ch){
			case 'a':
				dir=Left;
				break;
			case 'd':
				dir=Right;
				break;
			case 'w':
				dir=Up;
				break;
			case 's':
				dir=Down;
				break;
			default:
				break;
		}				
	}
}

int moveSnake(){
	if(tail==NULL && head==NULL){
		printf("Game over!!!\n");
		return -1;
	}
	else{
		int oldRow=tail->y;
		int oldCol=tail->x;
		struct Node *p=tail;
		tail=tail->next;
		gotoxy(p->y,p->x);
		printf(" \n");
		if(tail==NULL){
			tail=p;			
		}
		head->next=p;
		p->next=NULL;
		
		switch(dir){
			case Right:
				p->x=head->x+1;
				p->y=head->y;
				break;
			case Left:
				p->x=head->x-1;
				p->y=head->y;
				break;
			case Up:
				p->y=head->y-1;
				p->x=head->x;
				break;
			case Down:
				p->y=head->y+1;
				p->x=head->x;
				break;
			default:
				break;
		}
		head=p;
		gotoxy(p->y,p->x);
		printf("*\n");
		
		//�߳�ʳ��
		eatFood();
		//�ж�game over
		return checkGameOver(); 
	}
}

void eatFood()
{
	if(head->y==food.y && head->x==food.x){
		//�߱䳤
		for(int i=0;i<food.value;i++) {
			struct Node *pNode=(struct Node*)malloc(sizeof(struct Node));
			pNode->next=tail;
			pNode->y=tail->y;
			pNode->x=tail->x;
			tail=pNode;
			gotoxy(pNode->y,pNode->x);
			printf("*\n");
		}
		//�����µ�ʳ�� 
		produceFood(); 
		
	}
}

void deleteTwoNode(){
	if(tail==NULL){
		return;
	}
	struct Node *p=tail;
	struct Node *pnext=p->next;
	if(pnext==NULL){
		gotoxy(p->y,p->x);
		printf(" \n");
		free(p);
		p=NULL;
		head=NULL;
		tail=NULL;
	}
	else{
		tail=pnext->next;
		gotoxy(p->y,p->x);
		printf(" \n");
		gotoxy(pnext->y,pnext->x);
		printf(" \n");
		free(pnext);
		pnext=NULL;
		free(p);
		p=NULL;
		if(tail==NULL){
			head=NULL;
		}
	}
}

void reverseSnake(){
	if(tail==NULL){
		return;
	}
	struct Node *p=tail;
	struct Node *pn=p->next;
	if(pn==NULL){
		return;
	}
	struct Node *pnn=pn->next;
	p->next=NULL;
	
	while(pnn != NULL){
		pn->next=p;
		p=pn;
		pn=pnn;
		pnn=pnn->next;
	}
	pn->next=p;
	head=tail;
	tail=pn;
}

void reverseDirection(){
	if(dir==Left){
		dir=Right;
	}
	else if(dir==Right){
		dir=Left;
	}
	else if(dir==Up){
		dir=Down;
	}
	else if(dir==Down){
		dir=Up;
	}
}

//int checkGameOver(){
//	if(head->y<=0 || head->y>=height-1
//	||head->x<=0 ||head->x>=width){
//		printf("Game Over!!!\n");
//		return -1;
//	}
//	return 0;
//}

int checkGameOver(){
	if(head->y<=0 || head->y>=height-1
	||head->x<=0 ||head->x>=width){
		snakeHp--;
		if(snakeHp>0){
			deleteTwoNode();//ɾ������ 
			reverseSnake();//��ת�ߣ��൱������ת
			reverseDirection();//��ת�ߵķ���
			if(tail==NULL && head==NULL){
				printf("Game Over!!!\n");
				return -1;
			}
			else{
				return 0;
			} 
		}
		else{
			printf("Game Over!!!\n");
			return -1;
		}
	}
	return 0;
}

int main(int argc, const char *argv[]){
	//����Ϸ����
	drawInterface();
	//����ʳ��
	produceFood();
	//����
	produceSnake();
	drawSnake(tail);
	//�߲�ͣ�ƶ�
	while(1) {
		checkDirection();
		int res=moveSnake();
		if(res<0){
			int kk=0; 
			break;
		}
		Sleep(200);
	}
	return 0; 
}
