#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s;
int a[10000],b[100000],t=0;
int main() {
	getline(cin,s);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int lens=s.size();
	for(int i=0; i<lens; i++) {
		a[i]=s[i]-'0';
	}
	s=s+s;
	for(int i=1; i<=lens; i++) {
		for(int j=0; j<lens; j++) {
			b[j]=a[j];
		}
//		int t=0;
		for(int j=lens-1; j>=0; j--) {
			b[j]=b[j]*i+t;
			t=b[j]/10;
			b[j]%=10;
		}
		string ss;
		ss="";
		for(int j=0; j<lens; j++) {
			ss=ss+(char)('0'+b[j]);
		}
		int f=s.find(ss,0);
		
//		cout<<ss<<" "<<s<<" "<<f<<endl;
		
		if(f==-1) {
			cout<<0;
			return 0;
		}
	}
	cout<<1;
	return 0;
}
