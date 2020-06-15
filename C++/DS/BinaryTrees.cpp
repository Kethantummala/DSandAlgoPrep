#include<bits/stdc++.h>

using namespace std;

template<class T>
struct node {
	T data;
	struct node<T>* left;
	struct node<T>* right;
};

template<class T>
struct node<T>* newNode(T x) {
	struct node<T> *temp=(struct node<T>*)malloc(sizeof(struct node<T>));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
};

template<class T>
void printPreorder(struct node<T>* root) {
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

template<class T>
void printInorder(struct node<T>* root) {
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

template<class T>
void printPostorder(struct node<T>* root) {
	if(root==NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

template<class T>
void printBreadthTraversal(struct node<T>* root) {
	queue<struct node<T>*> q;
	q.push(root);
	while(q.size()) {
		struct node<T>* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

int main(int argc,char* *argv) {
	struct node<int>* root=newNode(1);
	root->left          = newNode(2);
	root->right         = newNode(3);
	root->left->left    = newNode(4);
	root->left->right   = newNode(5);
	
	printf("\nPreorder traversal of binary tree is \n"); 
	printPreorder(root); 

	printf("\nInorder traversal of binary tree is \n"); 
	printInorder(root);   

	printf("\nPostorder traversal of binary tree is \n"); 
	printPostorder(root);
	
	printf("\nBreadth first traversal of binary tree is \n"); 
	printBreadthTraversal(root);
	return 0;
}