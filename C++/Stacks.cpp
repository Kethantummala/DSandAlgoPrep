#include <iostream>

using namespace std;

template<class T>
class Stack {
	int cap,top;
	T *A;
	
	public:
	
	Stack(int n) {
		cap=n;
		A=new T[n];
		top=-1;
	}
	
	bool isFull() {
		if(top==(cap-1))
			return true;
		return false;
	}
	
	bool isEmpty() {
		if(top==-1)
			return true;
		return false;
	}
	
	T peek() {
		if(!isEmpty) {
			return A[top];
		}
		return NULL;
	}
	
	int getTop() {
		return top;
	}
	
	//Not a part of Stack ADT but using here for better understanding.
	void display() {
		cout<<"Stack : [";
		for(int i=0;i<=top;i++) {
			cout<<A[i]<<",";
		}
		cout<<"]"<<endl;
	}
	
	//outside declared member functions
	void push(T);
	T pop();
	
	
};

template<class T>
void Stack<T>::push(T x) {
		if(!isFull()) {
			A[++top]=x;
			return;
		}
		cout<<"Push failed."<<endl;
}

template<class T>
T Stack<T>::pop() {
		if(!isEmpty()) {
			return A[top--];
		}
		return NULL;
		cout<<"Stack empty."<<endl;
}

int main() {
	int A[]={1,2,3,4,5,6};
	int n=sizeof(A)/sizeof(int);
	Stack<int> s(n);
	for(int i=0;i<n;i++) {
		s.push(A[i]);
	}
	s.display();
  return 0; 
} 