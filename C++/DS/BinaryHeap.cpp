#include<iostream>
#include<math.h>
#include<limits.h>

using namespace std;

template<class T>
class MaxHeap {	//insert, display, extractMax
	T *A;
	
	public:
	int MAX_SIZE,Size;
	
	MaxHeap(int ms=20,T *Arr=NULL,int n=0) {
		this->MAX_SIZE=ms;
		Size=n;
		A=(T*)calloc(sizeof(T),ms);
		if(Arr) {
			for(int i=0;i<n;i++) {
				A[i]=Arr[i];
			}
			buildMaxHeap();
		}
	}
	
	void buildMaxHeap() {
		for(int i=Size/2;i>=0;--i) {
			maxHeapify(i);
		}
	}
	
	void maxHeapify(int i) {
		
		int lInd=(i*2)+1,rInd=(i*2)+2;
		int max=i;
		
		if(lInd<Size && A[lInd]>A[max]) {
			max=lInd;
		}
		if(rInd<Size && A[rInd]>A[max]) {
			max=rInd;
		}
		if(max!=i) {
			T temp=A[max];
			A[max]=A[i];
			A[i]=temp;
			
			maxHeapify(max);
		}
	}
	
	void insert(T x) {
		if(Size>MAX_SIZE) {
			cout<<"Overflow!"<<endl;
			return;
		}
		A[Size++]=x;
		int cur=Size-1,par=(cur-1)/2;
		while(par>=0 && A[par]<A[cur]) {
			T temp=A[cur];
			A[cur]=A[par];
			A[par]=temp;
			
			cur=par;
			par=(cur-1)/2;
		}
	}
	
	void remove(int i) {
		A[i]=A[Size-1];
		--Size;
		maxHeapify(i);
	}
	
	T extractMax() {
		T x=A[0];
		remove(0);
		return x;
	}
	
	void display() {
		cout<<"The Heap is: ";
		for(int i=0;i<Size;++i) {
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	
	void heapSort() {
		int n=Size;
		while(Size) {
			
			T temp=A[0];
			A[0]=A[Size-1];
			A[Size-1]=temp;
			
			--Size;
			maxHeapify(0);
		}
		Size=n;
	}
	
};

template<class T>
void sortKNearlySorted(T *A,int n,int k) {
	MaxHeap<T> hep2(k+1);
	int j=0;
	for(int i=0;i<n;i++) {
		if(hep2.Size==k+1) {
			A[j]=hep2.extractMax();
			j++;
		}
		hep2.insert(A[i]);
	}
	while(hep2.Size) {
		A[j++]=hep2.extractMax();
	}
}

template<class T>
void printKLargestElements(MaxHeap<T> hep,int k) {
	cout<<k<<" largest elements in the heap are:";
	while(k) {
		cout<<hep.extractMax()<<" ";
		--k;
	}
	cout<<endl;
}

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
	cout<<"Sorted Heap is:"<<endl;
	hep.heapSort();
	hep.display();
	hep.buildMaxHeap();
	hep.display();
	printKLargestElements(hep,3);
}

int main(int argc,char* argv[]) {
	
	simulateMaxHeap();
	int A[]={6, 5, 10, 9, 8, 3, 2};
	sortKNearlySorted(A,7,3);
	cout<<"Descending(Max Heap) Sorted Array:";
	for(int i=0;i<7;i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}