#include<bits/stdc++.h>

using namespace std;

template<class T>
struct node {
	T data;
	struct node<T>* left;
	struct node<T>* right;
};

template<class T>
struct TBTNode{
	T data;
	struct TBTNode<T>* left;
	struct TBTNode<T>* right;
	
	bool isThreaded;
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
TBTNode<T>* newTBTNode(T x) {
	TBTNode<T> *temp=(TBTNode<T>*)malloc(sizeof(TBTNode<T>));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	temp->isThreaded=false;
	
	
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

template<class T>
pair<int,int> findDiamaterDepth(struct node<T>* root) {
	if(root==NULL)
		return make_pair(0,0);
	
	//pair.first -> Diameter , pair.second -> depth
	pair<int,int> left=findDiamaterDepth(root->left);
	pair<int,int> right=findDiamaterDepth(root->right);
	
	int diam=max({left.first,right.first, left.second+right.second+1});
	
	return {diam,max(left.second,right.second)+1};
}

template<class T>
void printIterativeInorder(struct node<T>* root) {
	stack<struct node<T>*> s;
	while(1) {
		if(root==NULL) {
			if(s.empty())
				break;
			root=s.top();
			s.pop();
			cout<<root->data<<" ";
			root=root->right;
		}
		else {
			s.push(root);
			root=root->left;
		}
	}
}

template<class T>
void printMorrisInorder(struct node<T>* root) {
	struct node<T>* cur=root;
	
	while(cur) {
		if(!(cur->left)) {
			cout<<cur->data<<" ";
			cur=cur->right;
		}
		
		if(!cur)
			break;
		
		struct node<T>* predecessor=cur->left;
		while(predecessor->right!=NULL && predecessor->right!=cur) {
			predecessor=predecessor->right;
		}
		
		if(!predecessor->right) {
			predecessor->right=cur;
			cur=cur->left;
		}
		else {
			predecessor->right=NULL;
			cout<<cur->data<<" ";
			cur=cur->right;
		}
	}
}

template<class T>
TBTNode<T>* tbtLeftMost(TBTNode<T>* root) {
	if(!root)
		return NULL;
	
	while(root->left) {
		root=root->left;
	}
	return root;
}

template<class T>
void printTBTInorder(TBTNode<T>* root) {
	
	TBTNode<T>* cur=tbtLeftMost(root);
	
	while(cur) {
		
		cout<<cur->data<<" ";
		
		if(cur->isThreaded)
			cur=cur->right;
		else
			cur=tbtLeftMost(cur->right);
	}
}

template<class T>
int height(struct node<T>* root) {
	if(!root)
		return 0;
	return max(height(root->left),height(root->right))+1;
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
	
	pair<int,int> diadep=findDiamaterDepth(root);
	cout<<"\nDiameter of the tree:"<<diadep.first<<", depth of the root:"<<diadep.second<<endl;
	
	printf("\n***Iterative*** Inorder traversal(using 1 stack) of binary tree is \n"); 
	printIterativeInorder(root);
	
	printf("\n***Iterative***(Morris Inorder Traversal) Inorder traversal(Threaded Binary tree) of binary tree is \n"); 
	printMorrisInorder(root);
	
	struct TBTNode<int> *TBTRoot			 = newTBTNode(1);
	TBTRoot->left          = newTBTNode(2);
	TBTRoot->right         = newTBTNode(3);
	
	TBTRoot->left->left    = newTBTNode(4);
	TBTRoot->left->left->right=TBTRoot->left;
	TBTRoot->left->left->isThreaded=true;
	
	TBTRoot->left->right   = newTBTNode(5);
	TBTRoot->left->right->right=TBTRoot;
	TBTRoot->left->right->isThreaded=true;
	
	printf("\n***Iterative***(Threaded Binary Tree Inorder Traversal) Inorder traversal of binary tree is \n"); 
	printTBTInorder(TBTRoot);
	
	printf("\nHeight of binary tree is:%d \n",height(root));
	return 0;
}