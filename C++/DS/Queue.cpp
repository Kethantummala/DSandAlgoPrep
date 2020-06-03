#include<iostream>
#include<queue>
#include<stack>
#include<deque>
#include<utility>

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
	cout<<endl<<"Simulating Custom Circular Queue"<<endl;
	
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

void enqueueStack(stack<int> &s,int x) {
	s.push(x);
}

int dequeueStack(stack<int> &s) {
	if(s.empty()) {
		cout<<"Underflow"<<endl;
		return -1;
	}
	int x=s.top();
	s.pop();
	if(s.empty())
		return x;
	int t=dequeueStack(s);
	s.push(x);
	return t;
}

void simulateQueueUsingStack() {
	cout<<endl<<"Simualting Queue using single stack"<<endl;
	
	int x;
	stack<int> s;
	enqueueStack(s,5);
	enqueueStack(s,16);
	cout<<"Dequeue resulted: "<<dequeueStack(s)<<endl;
	cout<<"Dequeue resulted: "<<dequeueStack(s)<<endl;
	cout<<"Dequeue resulted: "<<dequeueStack(s)<<endl;
}

int printTour(pair<int,int> p[],int n) {
	int pe=p[0].first,d=p[0].second,start=0,end=1;
	while(start!=end) {
		while(pe-d<0 && start<n) {
			pe-=p[start].first;
			d-=p[start].second;
			++start;
		}
		if(start==n) {
			return -1;
		}
		pe+=p[end].first;
		d+=p[end].second;
		end=(end+1)%n;
	}
	return start;
}

void simulateCircularPetrolPumpTour() {
	cout<<endl<<"Simulating Circular Petrol Pump Tour Problem"<<endl;
	pair<int,int> arr[] = {{6, 4}, {3, 6}, {7, 3}};
  int n = sizeof(arr)/sizeof(arr[0]);
  int start = printTour(arr, n);
  (start == -1)? cout<<"No solution"<<endl: cout<<"Start = "<<start<<endl;
}

void displayDeque(deque<int> d) {
	cout<<"Displaying Deque"<<endl;
	while(!d.empty()) {
		cout<<d.front()<<" ";
		d.pop_front();
	}
	cout<<endl;
}

void simulateSlidingWindowMaximum() {
	cout<<endl<<"Simulating Sliding Window Maximum problem"<<endl;
	
	int A[]={1, 2, 3, 1, 4, 5, 2, 3, 6},k=3;
	int n=9;
	deque<int> d;
	
	for(int i=0;i<k;++i) {
		while(!d.empty() && A[d.back()]<=A[i]) {
			d.pop_back();
		}
		d.push_back(i);
		displayDeque(d);
	}
	
	for(int i=3;i<n;i++) {
		//Print max of previous window
		cout<<A[d.front()]<<"\t"<<endl;
		//Removing indices of older window
		while(!d.empty() && d.front()<(i-k)+1) {
			d.pop_front();
		}
		//Removing Indices of smaller elements
		while(!d.empty() && A[d.back()]<=A[i]) {
			d.pop_back();
		}
		d.push_back(i);
	}
	cout<<d.front()<<"\t"<<endl;
}

void binaryUsingQueue(int n) {
	cout<<endl<<"Printing numbers 1 to "<<n<<" in Binary format."<<endl;
	queue<string> q;
	q.push("1");
	while(n--) {
		string s1=q.front();
		q.pop();
		
		cout<<s1<<endl;
		string s2=s1;
		q.push(s1.append("0"));
		q.push(s2.append("1"));
	}
}

int main() {
	
	simulateCustomQueue();
	
	simulateQueueUsingStack();
	
	simulateCircularPetrolPumpTour();
	
	simulateSlidingWindowMaximum();
	
	binaryUsingQueue(15);
	return 0;
}