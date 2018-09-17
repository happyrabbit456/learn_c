#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n; 
	srand(time(NULL));
	cin>>n;
	int a=rand()%10;
	if(a==n){
		cout<<"OK.You are good!"<<endl;
	}
	else if(n>a){
		cout<<"The numder is big!"<<endl;
	}
	else if(n<a){
		cout<<"The numder is small!"<<endl;
	}
	return 0;
}
