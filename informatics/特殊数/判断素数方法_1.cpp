//�ж�����_1������ö��
//ʱ�临�Ӷȣ�O��n��  
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int x;
	printf("������һ��������\n");
	scanf("%d",&x);
	if(x==1)//����һ������ 1�����ʣ� 
	{
		printf("������\n");
		system("pause");
		return 0;
	}
	if(x>1){
		for(int i=2;i<x;i++){
			if(x%i==0){
				printf("������\n");//�����ӣ�������
				system("pause");
				return 0; 
			}
		}
	}
	printf("������");
	printf("\n");
	system("pause");
	return 0; 
}
