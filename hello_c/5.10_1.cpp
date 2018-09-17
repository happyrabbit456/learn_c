#include <iostream>
using namespace std;
int n=10;
void f1(){
	int n=20;
	cout<<"f1 n:"<<n<<endl;
}
void f2(int n){
	cout<<"f2 n:"<<n<<endl;
}
void f3(){
	printf("f3 n:%d\n",n);
}
void test(){
	int n=5;
	cout<<n<<endl;
	
	cout<<"global:"<<::n<<endl;
	
	::n=500;
	cout<<::n<<endl;
	
	
}
int main(){
	
	int n=30;
	f1();//20;
	f2(n);//30;
	f3();//10;
	{
		int n=40;
		printf("block n:%d\n",n);//40;
	}
	printf("main n:%d",n);//30;
	
	test();
	
	return 0;
}
