#include<bits/stdc++.h>

using namespace std;

template<class T>
struct XORNode {
	T data;
	struct XORNode* XORP;
};

template<class T>
struct DLLNode {
	T data;
	struct DLLNode<T>* prev;
	struct DLLNode<T>* next;
};

template<class T>
struct XORNode<T>* XOR(struct XORNode<T>* ptr1,struct XORNode<T>* ptr2) {
	return (struct XORNode<T>*)((uintptr_t)(ptr1)^(uintptr_t)(ptr2));
}

template<class T>
void printXORList(struct XORNode<T>* head) {
	struct XORNode<T> *cur=head,*prev=NULL,*next;
	
	while(cur) {
		cout<<cur->data<<" ";
		
		next=XOR(prev,cur->XORP);
		prev=cur;
		cur=next;
	}
}

template<class T>
void printDLL(struct DLLNode<T>* head) {
	struct DLLNode<T>* temp=head;
	while(temp) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

template<class T>
void XORInsert(struct XORNode<T>** head,T x) {
	struct XORNode<T>* newNode=(struct XORNode<T>*)malloc(sizeof(struct XORNode<T>));
	newNode->data=x;
	
	newNode->XORP=XOR<T>(*head,NULL);
	if(*head) {
		(*head)->XORP=XOR<T>((*head)->XORP,NULL);
		(*head)->XORP=XOR<T>(newNode,(*head)->XORP);
	}
	*head=newNode;
}

template<class T>
void insert(struct DLLNode<T>* head,T x) {
	struct DLLNode<T>* temp=(struct DLLNode<T>*)malloc(sizeof(struct DLLNode<T>));
	temp->data=x;
	struct DLLNode<T>* cur=head;
	if(!cur) {
		head=temp;
		return;
	}
	while(cur->next) {
		cur=cur->next;
	}
	temp->prev=cur;
	temp->next=cur->next;
	cur->next=temp;
}

int main(int argc,char** argv) {
	struct XORNode<int> *head = NULL;
	XORInsert(&head, 10);  
	XORInsert(&head, 20);  
	XORInsert(&head, 30);  
	XORInsert(&head, 40);  
	
	printXORList(head);
	
	struct DLLNode<int>* head2=NULL;
	insert(head2,10);
	insert(head2,20);
	insert(head2,30);
	insert(head2,40);
	printDLL<int>(head2);
	
	return 0;
}