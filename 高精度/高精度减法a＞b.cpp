#include <cstdio> 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	char s[1000];
	int a[1000],b[1000];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cout<<"请输入两个整数,做减法"<<endl; 
	cin>>s+1;
	int na=strlen(s+1);
	for(int i=1;i<=na;i++) a[na-i+1]=s[i]-'0';
	cin>>s+1;
	int nb=strlen(s+1);
	for(int i=1;i<=nb;i++) b[nb-i+1]=s[i]-'0';
	for(int i=1;i<=na;i++) {
		a[i]-=b[i];
	}
	for(int i=1;i<=na;i++){
		if(a[i]<0){
			a[i+1]-=1;
			a[i]+=10;
		}
	}
	for(int i=na;i>=1;i--){
		cout<<a[i];
	}
	cout<<endl;
	system("pause");
	return 0;
}
