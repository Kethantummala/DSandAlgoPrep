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

void reverse_Blocks(auto List1,auto& List2,int k) {
	while(!List1.empty()) {
		list<int> tempList;
		auto it1=List1.begin();
		auto it2=it1;
		advance(it2,k);
		if(it2==it1) {
			it2=List1.end();
		}
		tempList.splice(tempList.begin(),List1,it1,it2);
		tempList.reverse();
		List2.splice(List2.end(),tempList);
	}
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
	it2=next(it,9);
	swap(*it,*it2);
	print_List(List1);
	List1.reverse();
	print_List(List1);
	list<int> List2={5,9,6,1};
	List1.merge(List2);
	print_List(List1);
	List2.clear();
	reverse_Blocks(List1,List2,3);
	print_List(List2);
	return 0;
}