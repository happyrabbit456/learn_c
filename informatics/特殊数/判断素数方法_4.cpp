//线性筛选 
//时间复杂度：O（n） 
#include<cstdio>
#include<cstring>//memset函数用
#include <cstdlib>
int f[100005];//10W以内的素数表 
 
int main()
{
	int n=100000;
	memset(f,0,sizeof(f));//将f数组初始化为0：素数 
	f[1]=1;//1不是素数
	 
	for(int i=2;i<=n;i++)
	{
		if(f[i]==0)//i是素数， 
		{
			for(int j=i*2;j<=n;j+=i)
			{
				f[j]=1;//i的倍数都不是素数
			}
		}
	}
	//以上是打表部分 
	printf("请输入一个正整数n(n<=100000):\n");
	scanf("%d",&n);
	if(f[n]==0) printf("是素数\n");//直接查表,完美! 
	else{
		printf("非素数\n");
	}
	system("pause");
	return 0;
}
