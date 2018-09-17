//判断素数_1：暴力枚举
//时间复杂度：O（n）  
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int x;
	printf("请输入一个正整数\n");
	scanf("%d",&x);
	if(x==1)//素数一定大于 1（性质） 
	{
		printf("非素数\n");
		system("pause");
		return 0;
	}
	if(x>1){
		for(int i=2;i<x;i++){
			if(x%i==0){
				printf("非素数\n");//有因子，非素数
				system("pause");
				return 0; 
			}
		}
	}
	printf("是素数");
	printf("\n");
	system("pause");
	return 0; 
}
