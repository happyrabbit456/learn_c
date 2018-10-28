#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib> 
using namespace std;
int main(){
	char s[2100];
	int a[2100],b[2100],c[21000],d[21000];
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	memset(d,0,sizeof(d));
	cin>>s+1;
	int na=strlen(s+1);
	for(int i=1;i<=na;i++) a[na-i+1]=s[i]-'0';
	cin>>s+1;
	int nb=strlen(s+1);
	int nc=nb+na;
	for(int i=1;i<=nb;i++) b[nb-i+1]=s[i]-'0';
	for(int i=1;i<=nb;i++){
		memset(c,0,sizeof(c));
		for(int j=1;j<=na;j++){
			c[i+j-1]=a[j]*b[i];
		}
		for(int j=1;j<=nc;j++) d[j]+=c[j] ;
	}
	for(int i=1;i<=nc;i++){
		if(d[i]>9){
			d[i+1]+=d[i]/10;
			d[i]%=10;
			if(i == nc) nc++;
		}
	}
	while(d[nc]==0&&nc>1) nc--;
	for(int i=nc;i>=1;i--) cout<<d[i];
	cout<<endl;
	system("pause");
	return 0;
}
