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
	int dx[5]{0,0,1,1,-1};
	int dy[5]{0,1,-1,0,1};
	int x=1,y=1,k=1,t=1;
	while(1){
		a[x][y]=k;
		k++;if(k>n*m) break;
		while(a[x+dx[t]][y+dy[t]]!=0){
			t++;if(t>4) t=1;
		}
		x+=dx[t];y+=dy[t];
		if(t==1||t==3) t++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%4d",a[i][j]);
		cout<<endl;
	}
	return 0;
}
