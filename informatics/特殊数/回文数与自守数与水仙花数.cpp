#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
bool pd1(int n){
	int v=n*n;
	int a=1;
	while(a<n){
		a*=10;
	}
	if(v%a == n){
		return true;
	}
	return false;
}
bool pd2(int n){
	int a=n%10;
	int b=n/10%10;
	int c=n/100;
	if(a*a*a+b*b*b+c*c*c == n){
		return true;
	}
	return false;
}
bool pd3(int n){
	int a[10000];
	int b=0;
	while(n>0){
		a[++b] = n%10;
		n/=10;
	}
	for(int i=1;i<=b/2;i++){
		if(a[i]!=a[b-i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	int q;
	char c;
	cout<<"输入一个正整数n(n<=999),判断自守数按(z),判断回文数按(h),判断水仙花数按(s)"<<endl;
	cin>>q>>c;
	if(c=='z'){
		if(pd1(q)){
			cout<<"YES" ; 
		}
		else{
			cout<<"NO";
		}
	}
	if(c=='h'){
		if(pd3(q)){
			cout<<"YES";
		}
		else cout<<"NO";
	}
	if(c=='s'){
		if(pd2(q)){
			cout<<"YES";
		}
		else cout<<"NO";
	}
	cout<<endl;
	system("pause");
	return 0;
}
