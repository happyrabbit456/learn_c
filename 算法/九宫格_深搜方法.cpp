#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int gong[10][10];
int hang[10][10];
int lie[10][10];
int map[10][10];
int tot;
bool pdf(int x,int y,int i){
	if(gong[(y%3==0?y/3:y/3+1)+(x-1)/3*3][i]==0) return true;
	return false;
}
void f(int x,int y){
	if(y>9){
		f(x+1,1);
		return ;
	}
	if(x>9){
		cout<<"方法 "<<++tot<<" :"<<endl;
		for(int j=1;j<=9;j++){
			cout<<"--";
		}
		cout<<"----";
		cout<<endl;
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(j==1)cout<<"| ";
				cout<<map[i][j]<<" ";
				if(j%3==0) cout<<"| ";
			}
			if(i%3==0){
				cout<<endl<<" ";
				for(int j=1;j<=9;j++){
					cout<<"--";
				}
				cout<<"---";
			}
			cout<<endl;
		}
		return ;
	}
	if(map[x][y]==0){
		for(int i=1;i<=9;i++){
			if(hang[x][i]==0&&lie[y][i]==0&&pdf(x,y,i)){
				map[x][y]=i;
				hang[x][i]=1;
				lie[y][i]=1;
				gong[(y%3==0?y/3:y/3+1)+(x-1)/3*3][i]=1;
				f(x,y+1);
				map[x][y]=0;
				hang[x][i]=0;
				lie[y][i]=0;
				gong[(y%3==0?y/3:y/3+1)+(x-1)/3*3][i]=0;
			}
		}
	}
	else{
		f(x,y+1);
	}
}
int main(){
	/*
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0 0
	
	
	6 0 0 3 5 0 2 0 0
	0 0 3 0 0 0 0 0 9
	5 0 4 0 0 2 1 0 0
	1 0 0 7 0 9 0 0 0
	7 0 0 0 0 0 0 0 5
	0 0 0 8 0 5 0 0 1
	0 0 7 6 0 0 9 0 3
	8 0 0 0 0 0 6 0 0
	0 0 1 0 8 3 0 0 7
	方法 1 :
	----------------------
	6 1 9 | 3 5 4 | 2 7 8 |
	2 7 3 | 1 6 8 | 4 5 9 |
	5 8 4 | 9 7 2 | 1 3 6 |
	----------------------
	1 4 5 | 7 3 9 | 8 6 2 |
	7 9 8 | 2 1 6 | 3 4 5 |
	3 2 6 | 8 4 5 | 7 9 1 |
	----------------------
	4 5 7 | 6 2 1 | 9 8 3 |
	8 3 2 | 5 9 7 | 6 1 4 |
	9 6 1 | 4 8 3 | 5 2 7 |
	----------------------
	
	*/
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>map[i][j];
			if(map[i][j]!=0){
				hang[i][map[i][j]]=1;
				lie[j][map[i][j]]=1;
				if(i<=3){
					if(j>=1&&j<=3) gong[1][map[i][j]]=1;
					if(j>=4&&j<=6) gong[2][map[i][j]]=1;
					if(j>=7&&j<=9) gong[3][map[i][j]]=1;
				}
				if(i<=6&&i>=4){
					if(j>=1&&j<=3) gong[4][map[i][j]]=1;
					if(j>=4&&j<=6) gong[5][map[i][j]]=1;
					if(j>=7&&j<=9) gong[6][map[i][j]]=1;
				}
				if(i>=7&&i<=9){
					if(j>=1&&j<=3) gong[7][map[i][j]]=1;
					if(j>=4&&j<=6) gong[8][map[i][j]]=1;
					if(j>=7&&j<=9) gong[9][map[i][j]]=1;
				}
			}
		}
	}
	f(1,1);
	return 0;
}
