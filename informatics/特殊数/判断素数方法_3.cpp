//判断素数3：继续优化：降维 
//时间复杂度：O(√n)  
#include <cstdio>
#include <cmath>//sqrt开根函数要用 
#include <cstdlib> 
int main()
{
	int x,y;
	printf("请输入一个正整数:\n");
	scanf("%d",&x);
	y=sqrt(x+1);//y表示x的开根因子的取整，+1是保险 
	if(x>1)
	{
		for(int i=2;i<=y;i++)//枚举的次数只有原来的开根号次 
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

