/*ˮ�ɻ���������λ���У���һЩ������������������λ������ƽ���͵���������ֱ���*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
int main(){
	cout<<"100��999�е�ˮ�ɻ���:"<<endl;
	for(int i=100;i<=999;i++){
		int a=i%10;
		int b=i/10%10;
		int c=i/100;
		if(a*a*a+b*b*b+c*c*c == i){
			cout<<i<<endl;
		}
	}
	system("pause");
	return 0;
}
