//判断素数2：简单优化砍一半 
//时间复杂度：O（n/2） 
#include <cstdlib> 
#include<cstdio>
using namespace std;
int main()
{
	int x,y;
	printf("请输入一个正整数:\n");
	scanf("%d",&x);
	y=x/2;//y是x的一半 
	if(x>1)
	{
		for(int i=2;i<y;i++)//枚举的次数只有原来的一半 
		{
			if(x%i==0) 
			{
				printf("非素数\n");//有因子，非素数
				system("pause");
				return 0; 
			}
		}
	}
	else{
		printf("非素数\n");
		system("pause");
		return 0;
	}
	printf("是素数\n");
	system("pause") ;
	return 0; 
}

