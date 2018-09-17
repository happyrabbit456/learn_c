/*自守数：一个数平方后，尾数等于自己；*/
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
int main(){
	int x,y;
	cout<<"请输入x和y,判断x到y中的自守数"<<endl; 
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
