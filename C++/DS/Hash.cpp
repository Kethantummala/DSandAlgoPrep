#include<bits/stdc++.h>

using namespace std;

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
}

void noEmp(string ceo,unordered_multimap<string,string> mantoemp,unordered_map<string,int> ans) {
	if(mantoemp.find(ceo)==mantoemp.end()) {
		ans[ceo]=0;
		return;
	}
	unsigned int bucketno=mantoemp.bucket(ceo);
	auto it=mantoemp.begin(bucketno);
	while(it!=mantoemp.end(bucketno)) {
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
		mantoemp.insert((*it).second,(*it).first);
		if((*it).first==(*it).second) {
			ceo=(*it).first;
		}
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
		cout<<(*it).first<<"-"<<(*it).second;
	}
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
	return 0;
}