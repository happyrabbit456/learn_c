#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{	
	char s1='*',s2=' ';
	for(int i=1;i<=4;i++){
		for(int y=4-i;y>=1;y--){
			cout<<s2;
		}
		for(int j=2*i-1;j>=1;j--){
			cout<<s1;
		}
		cout<<endl;
	}
	for(int i=3;i>=1;i--){
		for(int y=4-i;y>=1;y--){
			cout<<s2;
		}
		for(int j=i*2-1;j>=1;j--){
			cout<<s1;
		}
		cout<<endl;
	}
	return 0;
}
