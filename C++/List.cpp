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

list<int> sum_Dir1(auto L1,auto L2) {
	list<int> ans;
	int carry=0;
	auto it1=L1.begin(),it2=L2.begin();
	while(it1!=L1.end() || it2!=L2.end()) {
		int a,b;
		if(it1==L1.end()) {
			a=0;
			b=*it2;
			it2++;
		}
		else if(it2==L2.end()) {
			b=0;
			a=*it1;
			it1++;
		}
		else {
			a=*it1;
			b=*it2;
			it1++;
			it2++;
		}
		a=a+b+carry;
		carry=a/10;
		ans.push_back(a%10);
	}
	if(carry)
		ans.push_back(carry);
	return ans;
}

list<int> sum_Dir2(auto L1,auto L2) {
	L1.reverse();
	L2.reverse();
	list<int> ans=sum_Dir1(L1,L2);
	ans.reverse();
	return ans;
}

void rotate(auto& L1,int k) {
	list<int> temp;
	auto it=L1.begin();
	advance(it,k);
	temp.splice(temp.begin(),L1,it,L1.end());
	L1.insert(L1.begin(),temp.begin(),temp.end());
}

int main() {
	list<int> List1={7,5,9,4,6},List2={8,4};
	/*for(int i=0;i<10;i++) {
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
	List1.merge(List2);
	print_List(List1);
	List2.clear();
	reverse_Blocks(List1,List2,3);
	print_List(List2);
	cout<<"Dir1 sum:"<<"\t";
	print_List(sum_Dir1(List1,List2));
	List1={1,0,0};
	List2={9,0};
	cout<<"Dir2 sum:"<<"\t";
	print_List(sum_Dir2(List1,List2));*/
	
	rotate(List1,3);
	print_List(List1);
	return 0;
}