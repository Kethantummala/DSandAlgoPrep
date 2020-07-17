/*
					Solutions for 12-16
*/

#include<bits/stdc++.h>

using namespace std;

template<class T>
class node {
	public:
	T data;
	node<T>* left;
	node<T>* right;
	
	node(T x): data(x),left(NULL),right(NULL){}
};

//DLL Functions
template<class T>
void printDLL(node<T>* root) {
	while(root) {
		cout<<root->data<<" ";
		root=root->right;
	}
	cout<<endl;
}

//BST Functions
template<class T>
void inorder(node<T>* root) {
	
	if(root) {
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	
}

template<class T>
node<T>* insert(node<T>* root,T x) {
	if(!root) {
		node<T>* n=new node<T>(x);
		return n;
	}
	
	if(root->data>x)
		 root->left=insert(root->left,x);
	else
		root->right=insert(root->right,x);
	
	return root;
}

//Function to add node to front of dll.
template<class T>
void pushBeg(node<T>** root,T x) {
	node<T>* n=new node<T>(x);
	n->left=NULL;
	
	n->right=(*root);
	if(*root)
		(*root)->left=n;
	(*root)=n;
}

template<class T>
int countNodes(node<T>* droot) {
	int ans=0;
	while(droot) {
		ans+=1;
		droot=droot->right;
	}
	
	return ans;
}

//Problem 12 Functions
template<class T>
node<T>* recur1(node<T>** droot, int start,int end) {
	
	if(start>end)
		return NULL;
	
	int mid=start+(end-start)/2;
	
	node<T>* left=recur1(droot,start,mid-1);
	
	node<T>* no=new node<T>((*droot)->data);
	no->left=left;
	
	*droot=(*droot)->right;
	
	no->right=recur1(droot,mid+1,end);
	
	return no;
	
}

template<class T>
node<T>* sortedListToBST(node<T>* droot) {
	
	int n=countNodes(droot);
	
	return recur1(&droot,0,n-1);
	
}

//Problem 13(Method 3(Supplementary)) Functions

template<class T>
void BSTToDLL(node<T>* root,node<T>** head,node<T>** tail) {
	
	if(!root)
		return;
	
	BSTToDLL(root->left,head,tail);
	
	root->left=*tail;
	
	if(!(*tail))
		*head=root;
	else
		(*tail)->right=root;
	
	*tail=root;
	
	BSTToDLL(root->right,head,tail);
	
}

//Zero Triplets Problem Functions

template<class T>
bool ZTripPresent(node<T>* head,node<T>* tail,T x) {
	
	while(head!=tail) {
		
		T sum=head->data+tail->data;
		
		if(head && sum==x)
			return true;
		
		if(head && sum>x) {
			tail=tail->left;
		}
		else
			head=head->right;
	}
	return false;
	
}

template<class T>
bool ZTripletExists(node<T>* broot) {
	
	if(!broot)
		return false;
	
	node<T> *head=NULL;//head
	node<T> *tail=NULL;
	
	BSTToDLL(broot,&head,&tail);
	
	node<T>* cur=head;
	
	while(cur && cur->data<=0) {
		
		if(ZTripPresent(cur->right,tail,(-1*(cur->data))))
			return true;
		
		cur=cur->right;
		
	}
	
	return false;
	
}

//Problem 13 Functions

template<class T>
bool isPairPresent(node<T>* broot,T sum) {
	
	if(!broot)
		return false;
	
	stack<node<T>*> s1,s2;
	node<T>* temp1=broot;
	node<T>* temp2=broot;
	
	while(1) {
		
		while(temp1) {
			s1.push(temp1);
			temp1=temp1->left;
		}
		
		while(temp2) {
			s2.push(temp2);
			temp2=temp2->right;
		}
		
		if(s1.empty() || s2.empty()) break;
		
		temp1=s1.top();
		temp2=s2.top();
		
		T val1=temp1->data,val2=temp2->data,csum=val1+val2;
		
		if(csum==sum) {
			if(val1==val2) return false;
			return true;
		}
		
		else if(csum<sum) {
			s1.pop();
			temp1=temp1->right;
			temp2=NULL;
		}
		
		else {
			s2.pop();
			temp2=temp2->left;
			temp1=NULL;
		}
		
	}
	
	return false;
	
}

//Problem 14 Functions

unsigned long long int fact(int n,unsigned long long int *arr) {
	
	unsigned long long int ans=1;
	
	while(n) {
		ans*=n--;
	}
	return ans;
}

unsigned long long int binomialCoefficient(unsigned long long int n,unsigned long long int r) {
	unsigned long long int ans=1;
	
	for(int i=0;i<r;++i) {
		
		ans*=(n-i);
		ans/=i+1;
		
	}
	
	return ans;
	
}

unsigned long long int catalan(int n,unsigned long long int *arr) {
	
	return binomialCoefficient(2*n,n)/(n+1);
	
}

unsigned long long int noOfPossibleBSTs(int n,unsigned long long int *arr) {
	
	return catalan(n,arr);
	
}	

//Problem 15 Functions
template<class T>
struct node<T>* RecursiveMergeDLLs(struct node<T>* droot1,struct node<T>* droot2,struct node<T>* prev) {
	
	struct node<T>* ans=NULL;
	
	if(!droot1) {
		return droot2;
	}
	if(!droot2) {
		return droot1;
	}
	//cout<<droot1->data<<","<<droot2->data<<" ";
	if(droot1->data<droot2->data) {
		ans=droot1;
		ans->left=prev;
		ans->right=RecursiveMergeDLLs(droot1->right,droot2,droot1);
	}
	else {
		ans=droot2;
		ans->left=prev;
		ans->right=RecursiveMergeDLLs(droot1,droot2->right,droot2);
	}
	
	return ans;
}

template<class T>
struct node<T>* mergeBSTs(struct node<T>* r1,struct node<T>* r2) {
	
	struct node<T>* dll1=NULL,*tail1=NULL;
	BSTToDLL(r1,&dll1,&tail1);
	struct node<T>* dll2=NULL,*tail2=NULL;
	BSTToDLL(r2,&dll2,&tail2);
	
	struct node<T>* prev=NULL,*mergedDLL=NULL;
	mergedDLL=RecursiveMergeDLLs(dll1,dll2,prev);
	
	return sortedListToBST(mergedDLL);
	
}

//Problem 16
template<class T>
int countBTNodes(struct node<T>* btroot) {
	
	if(!btroot)
		return 0;
	
	return countBTNodes(btroot->left)+1+countBTNodes(btroot->right);
	
}

template<class T>
void storeInorder(struct node<T>* btroot,T *arr,int *iPtr) {
	
	if(!btroot)
		return;
	
	storeInorder(btroot->left,arr,iPtr);
	
	arr[*iPtr]=btroot->data;
	(*iPtr)++;
	
	storeInorder(btroot->right,arr,iPtr);
	
}

template<class T>
struct node<T>* arrayToBST(T *arr,int start,int end) {
	
	if(start>end)
		return NULL;
	
	int mid=start+(end-start)/2;
	
	struct node<T>* root=new node<T>(arr[mid]);
	
	root->left=arrayToBST(arr,start,mid-1);
	
	root->right=arrayToBST(arr,mid+1,end);
	
	return root;
	
}

template<class T>
struct node<T>* BTToBST(struct node<T>* btroot) {
	
	int n=countBTNodes(btroot);
	
	T arr[n];
	int ind=0;
	storeInorder(btroot,arr,&ind);
	
	sort(arr,arr+n);
	
	return arrayToBST(arr,0,n-1);
	
}

template<class T>
void simulateBST2() {
	
	node<T>* root = NULL;  
	root = insert(root, 6);
	root = insert(root, -13);
	root = insert(root, 14);
	root = insert(root, -8);
	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 7);
	
	inorder(root);
	cout<<endl<<endl;
	//_______________________Initial check______________________________
	
	node<T>* droot=new node<T>(20);
	pushBeg(&droot,17);
	pushBeg(&droot,9);
	pushBeg(&droot,1);
	pushBeg(&droot,-1);
	pushBeg(&droot,-19);
	
	cout<<"DLL before creation of BST:";
	printDLL(droot);
	node<T>* cBST=sortedListToBST(droot);
	cout<<"DLL after creation of BST:";
	printDLL(droot);
	cout<<"BST:";
	inorder(cBST);
	
	cout<<endl<<endl;
	//_______________________Problem 12______________________________
	
	node<T> *cDLL=NULL;//head
	node<T> *tail=NULL;
	BSTToDLL(cBST,&cDLL,&tail);
	cout<<"DLL:";
	printDLL(cDLL);
	
	cout<<endl<<endl;
	//_______________________Problem 13(Method 3(Pre-requisite))______________________________
	
	if(ZTripletExists(root))
		cout<<"A Zero Triplet Exists!"<<endl;
	else
		cout<<"No, A Zero triplet doesn't exist!"<<endl;
	
	cout<<endl<<endl;
	//_______________________Bonus problem(Find if Zero Triplet exists)_______________________
	
	node<T>* root2 = NULL;  
	root2 = insert(root2, 6);
	root2 = insert(root2, -13);
	root2 = insert(root2, 14);
	root2 = insert(root2, -8);
	root2 = insert(root2, 15);
	root2 = insert(root2, 13);
	root2 = insert(root2, 7);
	
	if(isPairPresent(root2,27))
		cout<<"A Pair Exists!"<<endl;
	else
		cout<<"No, Pair doesn't exist!"<<endl;
	
	cout<<endl<<endl;
	//_______________________Problem 13(Method-4)______________________________
	
	int n=30;
	unsigned long long int arr[2*n+1]={0};
	arr[1]=1;
	cout<<"No of possible BST's with '"<<n<<"' nodes:"<<noOfPossibleBSTs(n,arr);
	
	cout<<endl<<endl;
	//_______________________Problem 14_______________________
	
	node<T>* root3 = NULL;  
	root3 = insert(root3, 6);
	root3 = insert(root3, -13);
	root3 = insert(root3, 14);
	root3 = insert(root3, -8);
	root3 = insert(root3, 15);
	root3 = insert(root3, 13);
	root3 = insert(root3, 7);
	
	node<T>* root4 = NULL;  
	root4 = insert(root4, 62);
	root4 = insert(root4, -130);
	root4 = insert(root4, 4);
	root4 = insert(root4, -8);
	
	struct node<T>* mergedRoot=mergeBSTs(root3,root4);
	
	inorder(mergedRoot);
	
	cout<<endl<<endl;
	//_______________________Problem 15_______________________
	
	struct node<T>* root5=new node<T>(10);
	root5->left=new node<T>(30);
	root5->right=new node<T>(15);
	root5->left->left=new node<T>(20);
	root5->right->right=new node<T>(5);
	
	struct node<T>* nBST=BTToBST(root5);

	inorder(nBST);
	
	cout<<endl<<endl;
	//_______________________Problem 16_______________________
}

int main(int argc,char** argv) {
	simulateBST2<int>();
	return 0;
}