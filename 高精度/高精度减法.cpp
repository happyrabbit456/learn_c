#include <iostream> 
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	char s[1000],z[1000];
	int na,nb;
	int ls=1;
	long long a[1000],b[1000],c[1000],g[1000],nc;
	//初始化 
	memset(s,0,sizeof(s));
	memset(z,0,sizeof(z));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(g,0,sizeof(g));
	//输入&&转换 
	cin>>s+1;
	na=strlen(s+1);
	for(int i=1;i<=na;i++){ 
		a[na-i+1]=s[i]-'0';
	} 
	//输入&&转换
	cin>>z+1;
	nb=strlen(z+1);
	for(int i=1;i<=nb;i++){
		b[nb-i+1]=z[i]-'0';
	}
	//判断大小; 
	if(na<nb)
	{
		ls=0;
	}
	else if(na==nb)
	{
		bool r=true;
		for(int i=na;i>=1;i--){
			if(a[i]<b[i]){
				ls=0;
				r=false;
				break;
			}
		}
		
		if(r) 
		{
			cout<<"0";
			cout<<endl; 
			system("pause");
			return 0;
		}			
	}
	//换位置 
	if(ls==0){
		for(int i=1;i<=na;i++){
			g[i]=a[i];
		}
		for(int i=1;i<=nb;i++){
			a[i]=b[i];
		}
		for(int i=1;i<=na;i++){
			b[i]=g[i];
		}
		int t=na;
		na=nb;
		nb=t;		
	}
	nc=na; 
	if(ls==0) cout<<"-";
	//核心代码 
	for(int i=1;i<=nb;i++){
		a[i]-=b[i];
	}
	
	for(int i=1;i<=na;i++){
		if(a[i]<0){
			a[i+1]--;
			a[i]+=10;
		}
	}
	while(a[na]==0&&na>=1) na--;
	for(int i=na;i>=1;i--){
		cout<<a[i];
	}
	cout<<endl; 
	system("pause");
	return 0;
}
