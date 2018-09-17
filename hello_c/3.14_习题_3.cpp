#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	for(int i=1;i<=5;i++){
		for(int y=5-i;y>=1;y--){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}	
	return 0;
}
