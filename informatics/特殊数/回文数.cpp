/*回文数：从左到右、从右到左读，都是一样的数；*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
bool pu(int b){
	int a[100000];
	int n=0;
	while(b>0){
		a[++n]=b%10;
		b/=10;
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cout<<"请输入一个正整数n,判断是否为回文数(n<=100000):"<<endl; 
	cin>>n; 
	if(pu(n)){
		cout<<"YES"<<endl;
		system("pause");
		return 0;
	}
	cout<<"NO"<<endl;
	system("pause");
	return 0;
}
