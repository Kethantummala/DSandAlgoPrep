#include<iostream>
#include<queue>

using namespace std;

template<class T>
class CircularQueue {
	T* A;
	int n,front=0,back=0,size=0;
	
	public:
	CircularQueue(int n=10) {
		this->n=n;
		A=(T*)malloc(sizeof(T)*n);
		for(int i=0;i<n;i++) {
			T t;
			A[i]=t;
		}
	}
	
	bool isFull() {
		return size==n;
	}
	
	bool isEmpty() {
		return size==0;
	}
	
	void enqueue(T x) {
		if(isFull()) {
			cout<<"Overflow"<<endl;
			return;
		}
		T t;
		A[back]=x;
		back=(back+1)%n;
		size++;
	}
	
	T dequeue() {
		T t;
		if(isEmpty()) {
			cout<<"Underflow"<<endl;
			return t;
		}
		T x=A[front];
		A[front]=t;
		front=(front+1)%n;
		--size;
		return x;
	}
	
	T get_front() {
		return A[front];
	}
	
	T get_rear() {
		return A[back-1];
	}
	
	void display() {
		if(isEmpty()) {
			cout<<"Custom Circualr Queue is Empty"<<endl;
			return;
		}
		int i=front,j=size;
		while(j--) {
			cout<<A[i]<<"\t";
			i=(i+1)%n;
		}
		cout<<endl;
	}
};

void simulateCustomQueue() {
	cout<<"Simulating Custom Circular Queue"<<endl;
	
	CircularQueue<int> q(3);
	q.enqueue(10);
	q.display();
	q.enqueue(20);
	q.display();
	q.enqueue(30);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(40);
	q.display();
	q.get_front();
	q.get_rear();
}

int main() {
	
	simulateCustomQueue();
	
	
	return 0;
}