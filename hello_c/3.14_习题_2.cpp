#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	for(int i=1;i<=9;i++){
		for(int y=1;y<=i;y++){
			cout<<y<<"*"<<i<<"="<<y*i<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
