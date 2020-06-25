#include<bits/stdc++.h>

using namespace std;

template<class T>
class BST {
	T data;
	BST *left,*right;
	
	public:
	BST(T x=0);
	
	void insert(T x);
	
	void inorder();
	
};

template<class T>
BST<T>::BST(T x):data(x),left(NULL),right(NULL) {}

template<class T>
void BST<T>::insert(T x) {
	BST<T> *root=this;
	if(!(root->data)) {
		root->data=x;
		return;
	}
	while(root) {
		if((root->data)<x) {
			if(root->right)
				root=root->right;
			else {
				root->right=new BST<T>(x);
				return;
			}
		}
		else {
			if(root->left)
				root=root->left;
			else {
				root->left=new BST<T>(x);
				return;
			}
		}
	}
}

template<class T>
void BST<T>::inorder() {
	if(!(this->data)) {
		return;
	}
	if(this->left)
	(this->left)->inorder();
	cout<<(this->data)<<" ";
	if(this->right)
	(this->right)->inorder();
}

void simulateBST() {
	BST<int> root;
	root.insert(10);
	root.insert(20);
	root.insert(5);
	root.inorder();
}

int main(int argc,char** argv) {
	simulateBST();
	return 0;
}