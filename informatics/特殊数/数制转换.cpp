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
	int c=1;//����Ȩ��
	int t=0;//��ʾʮ������
	for(int i=len-1; i>=0; i--) {
		//�ӵ�λ����λ����
		int x;//����ÿλ�������ʵ�ʴ�С
		if(str[i]>='0'&&str[i]<='9') {
			x=str[i]-'0';
		} else if(str[i]>='a'&&str[i]<='z') {
			x=10+str[i]-'a';
		} else if(str[i]>='A'&&str[i]<='Z') {
			x=10+str[i]-'A';
		}
		printf("x:%d ",x);
		t+=x*c;//����Ӳ�� 
		printf("t=%d ",t);
		c=c*a;//����Ӳ�� 
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
