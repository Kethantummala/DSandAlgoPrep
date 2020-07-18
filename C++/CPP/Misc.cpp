#include<iostream>

using namespace std;

class A {
	
	public:
	static int count;
	static int hc;
	
	A() {
		count++;
	}
	~A() {
		count--;
	}
	
	void* operator new(size_t size) {
		A::hc++;
	}
	
	void operator delete(void* ptr) {
		A::hc--;
		free(ptr);
	}
	
};

int A::count=0;
int A::hc=0;

int main(int argc,char** argv) {

	A a,b,c;
	
	A* ptr=(A*)malloc(sizeof(A));
	
	A* ptr2=new A,*ptr3=new A;
	
	//free(ptr2);
	
	delete ptr2;
	
	cout<<"Total no.of objects of A created are:"<<A::count<<endl;
	cout<<"no.of objects of A created in Heap are:"<<A::hc<<endl;
	return 0;
}