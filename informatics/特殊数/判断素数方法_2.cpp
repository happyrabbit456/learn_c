//�ж�����2�����Ż���һ�� 
//ʱ�临�Ӷȣ�O��n/2�� 
#include <cstdlib> 
#include<cstdio>
using namespace std;
int main()
{
	int x,y;
	printf("������һ��������:\n");
	scanf("%d",&x);
	y=x/2;//y��x��һ�� 
	if(x>1)
	{
		for(int i=2;i<y;i++)//ö�ٵĴ���ֻ��ԭ����һ�� 
		{
			if(x%i==0) 
			{
				printf("������\n");//�����ӣ�������
				system("pause");
				return 0; 
			}
		}
	}
	else{
		printf("������\n");
		system("pause");
		return 0;
	}
	printf("������\n");
	system("pause") ;
	return 0; 
}

