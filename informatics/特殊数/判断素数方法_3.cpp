//�ж�����3�������Ż�����ά 
//ʱ�临�Ӷȣ�O(��n)  
#include <cstdio>
#include <cmath>//sqrt��������Ҫ�� 
#include <cstdlib> 
int main()
{
	int x,y;
	printf("������һ��������:\n");
	scanf("%d",&x);
	y=sqrt(x+1);//y��ʾx�Ŀ������ӵ�ȡ����+1�Ǳ��� 
	if(x>1)
	{
		for(int i=2;i<=y;i++)//ö�ٵĴ���ֻ��ԭ���Ŀ����Ŵ� 
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

