/*
			Contains Solutions for 1-11
*/

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
	
	public:
	T data;
	BST *left,*right;
	
	//Methods
	BST(T x=0);
	
	BST<T>* getInstance();
	
	void insert(T x);
	
	void inorder();
	
	void del(T x);
	
	BST<T>* inorderPredecessor();
	
	T getMin();
	
	pair<T,T> inorderSucPred();
	
	void lowestCommonAncestor(T v1,T v2);
	
	void inorderSuccessor(T x);
	
	void kThSmallest(int &c,int k);
	
	void printSortedOrderOfBSTs(BST<T> root2);
	
	void correctTheSwappedBST();
	void getSwappedNodes(BST<T> **first,BST<T> **middle,BST<T> **last,BST<T> **prev);
	
	T ceil(T x);
	T floor(T x);
};

template<class T>
BST<T>::BST(T x):data(x),left(NULL),right(NULL) {}

template<class T>
BST<T>* BST<T>::getInstance() {
	return this;
}

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
BST<T>* BST<T>::inorderPredecessor() {
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
				BST<T>* temp=root->inorderPredecessor();
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

template<class T>
void BST<T>::lowestCommonAncestor(T v1,T v2) {
	BST<T>* root=this;
	while(root) {
		if(root->data>v1 && root->data>v2) {
			root=root->left;
		}
		else if(root->data<v1 && root->data<v2){
			root=root->right;
		}
		else {
			cout<<"lowest Common Ancestor of "<<v1<<" and "<<v2<<" is:"<<root->data<<endl;
			return;
		}
	}
	cout<<"No lowest common ancestor."<<endl;
}

template<class T>
void BST<T>::inorderSuccessor(T x) {
	BST<T>* root=this;
	
	while(root && root->data!=x) {
		if(root->data>x) {
			root=root->left;
		}
		else
			root=root->right;
	}
	if(!root) {
		cout<<"No Successor"<<endl;
		return;
	}
	else {
		if(root->right) {
			root=root->right;
			while(root->left) {
				root=root->left;
			}
			cout<<"Successor of "<<x<<" is:"<<root->data<<endl;
			return;
		}
		T ans=this->data;
		root=this;
		while(root) {
			if(root->data>x) {
				ans=root->data;
				root=root->left;
			}
			else if(root->data<x)
				root=root->right;
			else {
				cout<<"Successor of "<<x<<" is:"<<ans<<endl;
				return;
			}
		}
	}
}

template<class T>
void BST<T>::kThSmallest(int &c,int k) {
	BST<T>* root=this;
	if(root) {
		if(root->left)
			root->left->kThSmallest(c,k);
		++c;
		if(c==k) {
			cout<<k<<"th smallest element is:"<<root->data<<endl;
			return;
		}
		if(root->right) {
			root->right->kThSmallest(c,k);
		}
	}
}

template<class T>
void BST<T>::printSortedOrderOfBSTs(BST<T> root2) {
	stack<BST<T>*> s1,s2;
	BST<T>* cur1=this;
	BST<T>* cur2=root2.getInstance();
	
	if(!cur1->data) {
		cur2->inorder();
		return;
	}
	
	else if(!cur2->data) {
		cur1->inorder();
		return;
	}
	
	while(cur1 || !s1.empty() || cur2 || !s2.empty()) {
		
		if(cur1 || cur2) {
			
			if(cur1) {
				s1.push(cur1);
				cur1=cur1->left;
			}
			if(cur2) {
				s2.push(cur2);
				cur2=cur2->left;
			}
			
		}
		
		else {
			
			if(s1.empty()) {
				while(!s2.empty()) {
					BST<T>* tRoot=s2.top();
					s2.pop();
					tRoot->left=NULL;
					tRoot->inorder();
				}
				return;
			}
			if(s2.empty()) {
				while(!s1.empty()) {
					BST<T>* tRoot=s1.top();
					s1.pop();
					tRoot->left=NULL;
					tRoot->inorder();
				}
				return;
			}
			
			cur1=s1.top();
			s1.pop();
			cur2=s2.top();
			s2.pop();
			
			if(cur1->data<cur2->data) {
				cout<<cur1->data<<" ";
				cur1=cur1->right;
				s2.push(cur2);
				cur2=NULL;
			}
			else {
				cout<<cur2->data<<" ";
				cur2=cur2->right;
				s1.push(cur1);
				cur1=NULL;
			}
			
		}
		
	}
	
}

template<class T>
void BST<T>::getSwappedNodes(BST<T>** first,BST<T>** middle,BST<T>** last,BST<T>** prev) {
	
	if(this) {
		
		if(this->left)
			(this->left)->getSwappedNodes(first,middle,last,prev);
		
		if(*prev && (this->data)<((*prev)->data)) {
			if(*first) {
				*last=this;
			}
			else {
				*first=*prev;
				*middle=this;
			}
		}
		*prev=this;
		if(this->right)
			this->right->getSwappedNodes(first,middle,last,prev);
	}
	
}

template<class T>
void BST<T>::correctTheSwappedBST() {
	BST<T> *first,*middle,*last,*prev;
	first=middle=last=prev=NULL;
	
	this->getSwappedNodes(&first,&middle,&last,&prev);
	
	if(first && last) {
		T temp=first->data;
		first->data=last->data;
		last->data=temp;
	}
	else if(first && middle) {
		T temp=first->data;
		first->data=middle->data;
		middle->data=temp;
	}
	else {
		cout<<"No Swapping required."<<endl;
	}
	
}

template<class T>
T BST<T>::ceil(T x) {
	
	if(this->data==x) {
		return x;
	}
	if(this->data<x) {
		if(this->right)
			return this->right->ceil(x);
		return -1;
	}
	
	if(this->left)
		return this->left->ceil(x);
	return this->data;
}

template<class T>
T BST<T>::floor(T x) {
	
	if(this->data==x) {
		return x;
	}
	if(this->data>x) {
		if(this->left)
			return this->left->floor(x);
		return -1;
	}
	
	if(this->right)
		return this->right->floor(x);
	return this->data;
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
	
	BST<int> root2;
	root2.insert(20);
	root2.insert(8);
	root2.insert(22);
	root2.insert(12);
	root2.insert(4);
	root2.insert(14);
	root2.insert(10);
	
	root2.inorder();
	root2.lowestCommonAncestor(10,22);
	
	root2.inorderSuccessor(12);
	root2.inorderSuccessor(4);
	root2.inorderSuccessor(22);
	root2.inorderSuccessor(8);
	
	int c=0;
	root2.kThSmallest(c,3);
	
	cout<<"Elements in 'root' node:";
	root.inorder();
	cout<<endl;
	cout<<"Elements in 'root2' node:";
	root2.inorder();
	cout<<endl;
	
	root.printSortedOrderOfBSTs(root2);
	cout<<endl;
	
	BST<int>* temp2=root2.getInstance();
	/*while(temp2) {
		cout<<"Data:"<<temp2->data<<endl;
		temp2=temp2->left;
	}*/
	
	temp2->left->data=22;
	temp2->right->data=8;
	cout<<"Before the Swap correction."<<endl;
	root2.inorder();
	cout<<endl;
	root2.correctTheSwappedBST();
	cout<<"After the Swap correction."<<endl;
	root2.inorder();
	cout<<endl;
	
	cout<<"Ceil of 23 in root2 is:"<<root2.ceil(23)<<endl;
	cout<<"Floor of 3 in root2 is:"<<root2.floor(3)<<endl;
	
}

int main(int argc,char** argv) {
	simulateBST();
	return 0;
}