#include<bits/stdc++.h>
#include<typeinfo>

using namespace std;

template<class T>
void printType(T x) {
	cout<<"\nType of x:"<<typeid(x).name()<<endl;
	if(is_same<T,char>::value)
		cout<<"Found a char!"<<endl;
}

int main(int argc,char* *argv) {
	int a=2;
	float b=3.5;
	char c='c';
	printType(a);
	printType(b);
	printType(c);
	return 0;
}