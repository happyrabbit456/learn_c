// helloboost.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost\thread.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;

void thread_fun()
{
	cout << "This is a thread." << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	boost::function<void()> f(thread_fun);
	boost::thread t(f);
	t.join();
	cout << "Thread quit." << endl;
	system("pause");
	return 0;
}

