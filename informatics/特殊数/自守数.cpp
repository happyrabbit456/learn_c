/*��������һ����ƽ����β�������Լ���*/
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
int main(){
	int x,y;
	cout<<"������x��y,�ж�x��y�е�������"<<endl; 
	cin>>x>>y;
	for(int i=x;i<=y;i++){
		int w=i*i;
		int n=1;
		while(n<i){
			n*=10;
		}
		if(w%n == i){
			cout<<i<<endl;
		}
	}
	system("pause");
	return 0;
}
