#include <cstdio>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main(int argc, char *argv[])
{
//	for(int  i=0;i<argc;i++)
//		cout<<argv[i]<<endl;
	
	float x=3.1415;
	float *p=&x;
	int b=10;
	*p=6.2830;
	cout<<"x="<<(*p)<<" "<<x;
	return 0;
}
