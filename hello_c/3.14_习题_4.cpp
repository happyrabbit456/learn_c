#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int sum=0;
	for(int i=1;i<=20;i++){
		for(int y=1;y<=i;y++){
			sum=sum+y;			
		}
	}
	cout<<sum;
	return 0;
}
