//����ɸѡ 
//ʱ�临�Ӷȣ�O��n�� 
#include<cstdio>
#include<cstring>//memset������
#include <cstdlib>
int f[100005];//10W���ڵ������� 
 
int main()
{
	int n=100000;
	memset(f,0,sizeof(f));//��f�����ʼ��Ϊ0������ 
	f[1]=1;//1��������
	 
	for(int i=2;i<=n;i++)
	{
		if(f[i]==0)//i�������� 
		{
			for(int j=i*2;j<=n;j+=i)
			{
				f[j]=1;//i�ı�������������
			}
		}
	}
	//�����Ǵ���� 
	printf("������һ��������n(n<=100000):\n");
	scanf("%d",&n);
	if(f[n]==0) printf("������\n");//ֱ�Ӳ��,����! 
	else{
		printf("������\n");
	}
	system("pause");
	return 0;
}
