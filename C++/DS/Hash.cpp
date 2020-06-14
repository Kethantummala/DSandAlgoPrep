#include<bits/stdc++.h>

using namespace std;

template<class T>
void displayList(list<T> l) {
	for(auto it=l.begin();it!=l.end();++it) {
		cout<<*it<<"->";
	}
	cout<<endl;
}

void findPair(int* A,int n,int sum) {
	unordered_set <int> h;
	for(int i=0;i<n;i++) {
		int cpart=sum-A[i];
		if(h.find(A[i])!=h.end()) {
			cout<<cpart<<"\t"<<A[i]<<endl;
			return;
		}
		h.insert(cpart);
	}
	cout<<"-1"<<endl;
}

bool isSubsetOf1(int* A,int* B,int n1,int n2) {
	set<int> s;
	for(int i=0;i<n1;i++) {
		s.insert(A[i]);
	}
	for(int i=0;i<n2;i++) {
		if(s.find(B[i])==s.end()) {
			return false;
		}
	}
	return true;
}

bool containsDuplicatesWithinK(int* A,int n,int k) {
	unordered_map<int,int> h;
	for(int i=0;i<n;i++) {
		if(h.find(A[i])!=h.end()) {
			int Ind=h[A[i]];
			if(Ind>=(i-k)) {
				h[A[i]]=i;
				return true;
			}
		}
		h[A[i]]=i;
	}
	return false;
}

void getItinerary(vector<pair<string,string>> data) {
	unordered_map<string,string> Straightmap,Reversemap;
	string start,currentCity;
	for(pair<string,string> i:data) {
		Straightmap.insert(i);
		Reversemap.insert({i.second,i.first});
	}
	for(auto it=Straightmap.begin();it!=Straightmap.end();++it) {
		if((Reversemap.find((*it).first))==Reversemap.end()) {
			start=(*it).first;
		}
	}
	currentCity=start;
	while(Straightmap.find(currentCity)!=Straightmap.end()) {
		string nextCity=Straightmap[currentCity];
		cout<<currentCity<<"->"<<nextCity<<",";
		currentCity=nextCity;
	}
	cout<<endl;
}

void noEmp(string ceo,unordered_multimap<string,string> mantoemp,unordered_map<string,int> &ans) {
	if(mantoemp.find(ceo)==mantoemp.end()) {
		ans[ceo]=0;
		return;
	}
	auto ceoEmps =mantoemp.equal_range(ceo);
	
	auto it=ceoEmps.first;
	while(it!=ceoEmps.second) {
		if(ans.find(it->second)==ans.end())
			noEmp(it->second,mantoemp,ans);
		ans[ceo]+=1+ans[it->second];
		++it;
	}
}

unordered_map<string,int> noEmployeesUnderEmployee(unordered_map<string,string> data) {
	unordered_multimap<string,string> mantoemp;
	unordered_map<string,int> ans;
	string ceo;
	for(auto it=data.begin();it!=data.end();++it) {
		if(it->first==it->second) {
			ceo=it->first;
			continue;
		}
		mantoemp.insert(make_pair(it->second,it->first));
		
	}
	noEmp(ceo,mantoemp,ans);
	return ans;
}

void simulateEmployeesUnderEmployee() {
	unordered_map<string,string> data={{ "A", "C" },
																		{ "B", "C" },
																		{ "C", "F" },
																		{ "D", "E" },
																		{ "E", "F" },
																		{ "F", "F" }};
	unordered_map<string,int> ans=noEmployeesUnderEmployee(data);
	for(auto it=ans.begin();it!=ans.end();++it) {
		cout<<(*it).first<<"-"<<(*it).second<<endl;
	}
}

template<class T>
list<T> findUnion(list<T> l1,list<T> l2) {
	list<T> ans;
	unordered_set<int> hashset;
	for(auto it=l1.begin();it!=l1.end();++it) {
		if(hashset.find(*it)==hashset.end()) {
			hashset.insert(*it);
			ans.push_back(*it);
		}
	}
	for(auto it=l2.begin();it!=l2.end();++it) {
		if(hashset.find(*it)==hashset.end()) {
			hashset.insert(*it);
			ans.push_back(*it);
		}
	}
	return ans;
}

template<class T>
list<T> findIntersection(list<T> l1,list<T> l2) {
	list<T> ans;
	unordered_set<int> hashset;
	for(auto it=l1.begin();it!=l1.end();++it) {
		if(hashset.find(*it)==hashset.end()) {
			hashset.insert(*it);
		}
	}
	for(auto it=l2.begin();it!=l2.end();++it) {
		if(hashset.find(*it)!=hashset.end()) {
			ans.push_back(*it);
		}
	}
	return ans;
}

void simulateLinkedListUnionAndIntersection() {
	list<int> l1,l2,ans;
	l1.push_back(10);
	l1.push_back(15);
	l1.push_back(4);
	l1.push_back(20);
	
	/*l2.insert(8);
	l2.insert(4);
	l2.insert(2);
	l2.insert(10);*/
	l2={8,4,2,10};
	
	cout<<"Union:";
	ans=findUnion(l1,l2);
	displayList(ans);
	cout<<"Intersection:";
	ans=findIntersection(l1,l2);
	displayList(ans);
}

int main(int argc,char* argv[]) {
	int A[]={1,2,3,9},B[]={5,9};
	int n1=sizeof(A)/sizeof(A[0]),n2=sizeof(B)/sizeof(B[0]);
	int sum=8;
	findPair(A,n1,sum);
	
	(isSubsetOf1(A,B,n1,n2))?cout<<"Second array is subset of first array"<<endl:cout<<"Second array is not a subset of first array"<<endl;
	
	int C[]={1, 2, 3, 4, 1, 1, 3, 4};
	int n3=8;
	int k=3;
	containsDuplicatesWithinK(C,n3,k)?cout<<"TRUE"<<endl:cout<<"FALSE"<<endl;
	
	vector<pair<string,string>> data={{"Chennai","Banglore"},{"Bombay","Delhi"},{"Goa","Chennai"},{"Delhi","Goa"}};
	getItinerary(data);
	
	simulateEmployeesUnderEmployee();
	
	simulateLinkedListUnionAndIntersection();
	return 0;
}