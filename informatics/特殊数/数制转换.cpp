#include<iostream>
#include<stdio.h>
#include<string.h>
//#include<queue>
using namespace std;
int a,b;
char str[40];
char ans[40];
int main() {
	memset(ans,0,sizeof(ans));
	scanf("%d%s%d",&a,str,&b);
	int len=strlen(str);
	int c=1;//保存权重
	int t=0;//表示十进制数
	for(int i=len-1; i>=0; i--) {
		//从低位到高位遍历
		int x;//保存每位数代表的实际大小
		if(str[i]>='0'&&str[i]<='9') {
			x=str[i]-'0';
		} else if(str[i]>='a'&&str[i]<='z') {
			x=10+str[i]-'a';
		} else if(str[i]>='A'&&str[i]<='Z') {
			x=10+str[i]-'A';
		}
		printf("x:%d ",x);
		t+=x*c;//死记硬背 
		printf("t=%d ",t);
		c=c*a;//死记硬背 
		printf("c:%d\n",c);
	}
	//int size=tenRT(t,b);
	int size=0;
	do {
		int x=t%b;
		ans[size++]=x<10?x+'0':x-10+'A';
		t/=b;
	} while(t!=0);
	for(int i=size-1; i>=0; i--) {
		printf("%c",ans[i]);
	}
	printf("\n");

}
