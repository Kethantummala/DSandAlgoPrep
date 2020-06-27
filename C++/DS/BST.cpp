#include<bits/stdc++.h>

using namespace std;

template<class T>
struct node {
	T data;
	struct node<T>* left;
	struct node<T>* right;
};

template<class T>
class BST {
	
	T data;
	BST *left,*right;
	
	public:
	BST(T x=0);
	
	void insert(T x);
	
	void inorder();
	
	void del(T x);
	
	BST<T>* inorderSuccesor();
	
	T getMin();
	
	pair<T,T> inorderSucPred();
	
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

template<class T>
BST<T>* BST<T>::inorderSuccesor() {
	BST<T>* root=this->left;
	while(root->right) {
		root=root->right;
	}
	return root;
}

template<class T>
void BST<T>::del(T x) {
	BST<T>* root=this;
	if(!(root->data)) {
		cout<<"BST Underflow"<<endl;
		return;
	}
	while(root) {
		if(root->data==x) {
			if(root->left && root->right) {
				BST<T>* temp=root->inorderSuccesor();
				root->data=temp->data;
				root->left=temp->left;
				return;
			}
			else if(root->left) {
				root->data=root->left->data;
				root->left=root->left->left;
				return;
			}
			else if(root->right) {
				root->data=root->right->data;
				root->left=root->right->left;
				root->right=root->right->right;
				return;
			}
			else {
				root->data=0;
				return;
			}
		}
		else if(root->data>x) {
			root=root->left;
		}
		else {
			root=root->right;
		}
	}
	cout<<"Node with given value not found."<<endl;
}

template<class T>
T BST<T>::getMin() {
	BST<T>* root=this;
	while(root->left) {
		root=root->left;
	}
	return root->data;
}

template<class T>
pair<T,T> BST<T>::inorderSucPred() {
	BST<T>* root=this;
	T suc=INT_MAX,pred=INT_MIN;
	if(!root->data) {
		cout<<"Empty BST"<<endl;
		return make_pair(pred,suc);
	}
	
	if(root->left) {
		root=root->left;
		while(root->right) {
			root=root->right;
		}
		pred=root->data;
	}
	root=this;
	if(root->right) {
		root=root->right;
		while(root->left) {
			root=root->left;
		}
		suc=root->data;
	}
	return make_pair(pred,suc);
}

template<class T>
struct node<T>* newNode(T x) {
	struct node<T>* root=(struct node<T>*)malloc(sizeof(struct node<T>));
	root->data=x;
	root->left=NULL;
	root->right=NULL;
	return root;
}

template<class T>
bool btIsBST1(struct node<T>* broot,T min,T max) {
	bool lClean=true,rClean=true;
	if(!broot) {
		return true;
	}
	if(broot->left) {
		lClean=((min)<(broot->left->data) && (max)>=(broot->left->data) && btIsBST1(broot->left,min,(broot->data)+1));
	}
	if(broot->right)
		rClean=((max)>=(broot->right->data) && (min)<(broot->right->data) && btIsBST1(broot->right,(broot->data)+1,max));
	return (lClean && rClean);
}

template<class T>
void getInorder(struct node<T>* broot,vector<T> &in) {
	if(broot) {
		getInorder(broot->left,in);
		in.push_back(broot->data);
		getInorder(broot->right,in);
	}
}

template<class T>
bool btIsBST2(struct node<T>* broot) {
	vector<T> in;
	getInorder(broot,in);
	T prev=INT_MIN;
	for(auto it=in.begin();it!=in.end();++it) {
		if(*it<prev)
			return false;
		prev=*it;
	}
	return true;
}

void simulateBST() {
	BST<int> root,temp;
	root.insert(10);
	root.insert(20);
	root.insert(5);
	root.insert(9);
	root.insert(15);
	root.inorder();
	cout<<endl;
	
	pair<int,int> SP=root.inorderSucPred();
	cout<<"Inorder Predecessor:"<<SP.first<<",Successor:"<<SP.second<<endl;
	
	cout<<"Minimum value is the BST is:"<<root.getMin()<<endl;
	
	root.del(5);
	root.inorder();
	cout<<endl;
	root.del(10);
	root.inorder();
	cout<<endl;
	
	SP=root.inorderSucPred();
	cout<<"Inorder Predecessor:"<<SP.first<<",Sucessor:"<<SP.second<<endl;
	
	cout<<"Minimum value is the BST is:"<<root.getMin()<<endl;
	
	struct node<int>* broot=newNode(10);
	broot->left=newNode(5);
	broot->right=newNode(20);
	broot->left->right=newNode(9);
	broot->right->left=newNode(15);
	
	if(btIsBST1(broot,INT_MIN,INT_MAX))
		cout<<"Given BT is a BST";
	else
		cout<<"Given BT is not a BST";
	cout<<endl;
	
	if(btIsBST2(broot))
		cout<<"Given BT is a BST";
	else
		cout<<"Given BT is not a BST";
	cout<<endl;
}

int main(int argc,char** argv) {
	simulateBST();
	return 0;
}