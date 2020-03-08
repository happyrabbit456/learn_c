#include<cstdio>
#include<cstring> 
#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[110][110];
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=0;
		}
	}
	int dx[6]{0,0,-1,-1,0,0};
	int dy[6]{0,1,-1,1,0,-1}; 
	int k=4,t=1,x=1,y=3;
	a[1][1]=1;a[2][1]=2;a[1][2]=3;
	while(1){
		if(t>5) t=1;
		a[x][y]=k;
		k++;if(k>n*m) break;
		if(a[x+dx[t]][y+dy[t]]!=0){
			t++;if(t>5) t=1;
		}
		x+=dx[t];y+=dy[t];
		if(t==1||t==5) t++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%4d",a[i][j]);
		cout<<endl;
	}
	return 0;
}
