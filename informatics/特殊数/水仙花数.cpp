/*水仙花数：在三位数中，有一些数字满足条件：各数位的数的平方和等于这个数字本身；*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
int main(){
	cout<<"100到999中的水仙花数:"<<endl;
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
