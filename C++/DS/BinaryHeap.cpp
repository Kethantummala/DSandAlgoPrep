#include<iostream>
#include<math.h>

using namespace std;

template<class T>
class MaxHeap {
	T* A;
	int n=0,MAXSIZE;
	
	public:
	MaxHeap(int MAXSIZE=20,T* B=NULL,int n=0) {
		this->MAXSIZE=MAXSIZE;
		A=(T*)calloc(MAXSIZE,sizeof(T));
		
		if(B) {
			this->n=n;
			for(int i=0;i<n;i++) {
				A[i]=B[i];
			}
			buildHeap();
		}
	}
	
	void buildHeap() {
		for(int i=(n/2)-1;i>=0;--i) {
			maxHeapify(i);
		}
	}
	
	void maxHeapify(int i) {
		int left=(i*2)+1;
		int right=(i*2)+2;
		
		int lInd=i;
		if(left<n && A[left]>A[lInd]) {
			lInd=left;
		}
		if(right<n && A[right]>A[lInd]) {
			lInd=right;
		}
		if(lInd!=i) {
			T temp=A[i];
			A[i]=A[lInd];
			A[lInd]=temp;
			maxHeapify(lInd);
		}
	}
	
	void insert(T x) {
		if(n==MAXSIZE) {
			cout<<"Overflow!"<<endl;
		}
		A[n]=x;
		int rootInd=((n-1)/2),curInd=n;
		while(rootInd>=0 && A[rootInd]<A[curInd]) {
			T temp=A[rootInd];
			A[rootInd]=A[curInd];
			A[curInd]=temp;
			curInd=rootInd;
			rootInd=(rootInd-1)/2;
		}
		++n;
	}
	
	T extractMax() {
		T x=A[0];
		A[0]=A[n-1];
		--n;
		maxHeapify(0);
		return x;
	}
	
	void display() {
		if(!n) {
			cout<<"Heap is empty!"<<endl;
		}
		for(int i=0;i<n;i++) {
			cout<<A[i]<<"\t";
		}
		cout<<endl;
	}
	
	void displayTree() {
		if(!n) {
			cout<<"Heap Tree is empty!"<<endl;
		}
		int levels=log2(n)+1,j=1;
		for(int i=0;i<levels;i++) {
			int leftspace=(levels-1)*2;
			cout<<string(leftspace,' ');
			int maxnodes=(levels*2);
			while(j<maxnodes) {
				cout<<A[j-1]<<"  ";
				++j;
			}
			
			cout<<endl;
		}
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