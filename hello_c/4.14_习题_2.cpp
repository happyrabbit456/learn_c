#include <iostream> 
#include <cstdio>
using namespace std;
int main()
{
	int a;
	cin>>a;
	switch(a){
		case 1:
			cout<<1;
			break;
		case 3:
			cout<<2;
			break;
		default:
			cout<<a;
			break;
	}
	return 0;
}
