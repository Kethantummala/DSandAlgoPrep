#include<bits/stdc++.h>

using namespace std;

template<class T>
struct CLLNode {
	T data;
	struct CLLNode<T>* next;
};

template<class T>
void printCLL(struct CLLNode<T>* last) {
	struct CLLNode<T>* temp=last;
	if(last) {
		temp=last->next;
	}
	else {
		cout<<"Empty list"<<endl;
		return;
	}
	while(temp!=last) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<last->data<<" ";
	cout<<endl;
}

template<class T>
void push(struct CLLNode<T>** last,T x,bool atEnd) {
	struct CLLNode<T>* newNode=(struct CLLNode<T>*)malloc(sizeof(struct CLLNode<T>));
	newNode->data=x;
	if(!(*last)) {
		(*last)=newNode;
		(*last)->next=(*last);
		return;
	}
	newNode->next=(*last)->next;
	if(atEnd) {
		(*last)->next=newNode;
		*last=(*last)->next;
	}
	else {
		(*last)->next=newNode;
	}
}

template<class T>
void splitCLL(struct CLLNode<T>** last,struct CLLNode<T>** sp1,struct CLLNode<T>** sp2) {
	*sp1=(*last)->next;
	*sp2=(*last)->next;
	while(1) {
		if((*sp2)->next!=(*last)) {
			(*sp2)=(*sp2)->next;
			(*sp1)=(*sp1)->next;
			if((*sp2)->next!=(*last)) {
				(*sp2)=(*sp2)->next;
			}
			else {
				(*sp2)=(*sp2)->next;
				struct CLLNode<T>* tmp=(*sp1)->next;
				(*sp1)->next=(*last)->next;
				(*last)->next=tmp;
				return;
			}
		}
		else {
			(*sp2)=(*sp2)->next;
			struct CLLNode<T>* tmp=(*sp1)->next;
			(*sp1)->next=(*last)->next;
			(*last)->next=tmp;
			return;
		}
	}
}

template<class T>
void sortedInsert(struct CLLNode<T>** last,T x) {
	struct CLLNode<T>* cur=(*last)->next;
	struct CLLNode<T>* newNode=(struct CLLNode<T>*)malloc(sizeof(struct CLLNode<T>));
	newNode->data=x;
	if((*last)->data<x) {
		newNode->next=(*last)->next;
		(*last)=newNode;
		return;
	}
	else if((*last)->next->data>x) {
		newNode->next=(*last)->next;
		(*last)->next=newNode;
		return;
	}
	while(cur->next->data<x) {
		cur=cur->next;
	}
	newNode->next=cur->next;
	cur->next=newNode;
}

int main(int argc,char** argv) {
	struct CLLNode<int>* last=NULL;
	push(&last,3,true);
	push(&last,7,true);
	push(&last,9,true);
	push(&last,11,true);
	printCLL(last);
	
	struct CLLNode<int>* sp1=NULL;
	struct CLLNode<int>* sp2=NULL;
	splitCLL(&last,&sp1,&sp2);
	printCLL(sp1);
	printCLL(sp2);
	
	sortedInsert(&last,8);
	printCLL(last);
}