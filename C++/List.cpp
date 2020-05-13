#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void print_List(list<int> L1) {
	list<int>::iterator it=L1.begin();
	while(it!=L1.end()) {
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
}

void insert_After_Value(list<int>& L1,int x,int newx) {
	list<int>::iterator it=find(L1.begin(),L1.end(),x);
	L1.insert(it,newx);
}

void length_Iterative(list<int> L1) {
	auto it=L1.begin();
	int count=0;
	while(it!=L1.end()) {
		count++;
		it++;
	}
	cout<<"Length of list : "<<count<<endl;
}

int length_Recursive(list<int>& L1,list<int>::iterator it) {
	if(it==L1.end())
		return 0;
	return 1+length_Recursive(L1,++it);
}

int main() {
	list<int> List1;
	for(int i=0;i<10;i++) {
		List1.push_back(i+1);
	}
	List1.push_front(69);
	insert_After_Value(List1,2,169);
	print_List(List1);
	List1.remove(169);
	list<int>::iterator it=List1.begin(),it2;
	advance(it,2);
	List1.erase(it);
	print_List(List1);
	length_Iterative(List1);
	cout<<"Length of list(Recursive) : "<<length_Recursive(List1,List1.begin())<<endl;
	it=List1.begin();
	*it=269;
	print_List(List1);
	it2=next(it,9);
	swap(*it,*it2);
	return 0;
}