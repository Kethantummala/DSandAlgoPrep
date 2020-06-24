#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include<iostream>
#include<math.h>
#include<limits.h>

template<class T>
class MaxHeap {
	private:
	T *A;
	
	public:
	int MAX_SIZE,Size;
	
	MaxHeap(int ms=20,T *Arr=NULL,int n=0);
	void buildMaxHeap();
	void maxHeapify(int i);
	void insert(T x);
	void remove(int i);
	T extractMax();
	void display();
	void heapSort();
};

template<class T>
class MinHeap {
	private:
	T *A;
	
	public:
	int MAX_SIZE,Size;
	
	MinHeap(int ms=20,T *Arr=NULL,int n=0);
	void buildMinHeap();
	void minHeapify(int i);
	void insert(T x);
	void remove(int i);
	T extractMin();
	void display();
	void heapSort();
};

template<class T>
void sortKNearlySorted(T *A,int n,int k);

template<class T>
void printKLargestElements(MaxHeap<T> hep,int k);

void simulateMaxHeap();

void simulateMinHeap();

#endif