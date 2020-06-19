#include<iostream>
#include<math.h>

using namespace std;

template<class T>
class MaxHeap {	//insert, display, extractMax
	T *A;
	int MAX_SIZE,Size;
	MaxHeap(int ms=20,T *Arr=NULL,int n=0) {
		this.MAX_SIZE=ms;
		Size=n;
		for(int i=0;i<Size;++i) {
			this.insert(Arr[i]);
		}
	}
	
	
	void insert(T x) {
		
	}
};

void simulateMaxHeap() {
	cout<<endl<<"Simulating Max Heap"<<endl;
	
	int A[]={3,2,1,15};
	MaxHeap<int> hep(11,A,4);
	hep.display();
	//hep.displayTree();
	hep.insert(5);
	hep.display();
	//hep.displayTree();
	hep.insert(4);
	hep.display();
	//hep.displayTree();
	hep.insert(45);
	hep.display();
	//hep.displayTree();
	cout<<"Extracted max: "<<hep.extractMax()<<endl;
	hep.display();
	//hep.displayTree();
	cout<<"Extracted max: "<<hep.extractMax()<<endl;
	hep.display();
	//hep.displayTree();
}

int main(int argc,char* argv[]) {
	
	simulateMaxHeap();
	return 0;
}