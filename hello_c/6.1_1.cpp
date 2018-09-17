#include <cstdio>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
struct nod{
	int x,y;
}a[2],b;
typedef struct ttt{
	int a;
	int b;
}TTT;


int main(int argc, char *argv[])
{
	a[0].x = 4;
	a[0].y = 3;
	b.x=55;
	b.y=90;
	
	struct nod nod1;
	nod1.x=6;
	nod1.y=8;
	
	TTT t;
	t.a=3;
	TTT *p=&t;
	p->a=666;
	cout<<(*p).a<<endl;
}
