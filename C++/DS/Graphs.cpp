#include<bits/stdc++.h>

using namespace std;

template<class T>
pair<list<T>*,int> createGraph(int V) {
	
	/*int V;
	cout<<"Enter the no.of nodes/Vertices in the graph:";
	cin>>V;*/
	
	list<T> *adj=new list<T>[V];
	
	return make_pair(adj,V);
}

template<class T>
void insert(pair<list<T>*,int> adj,T a,T b) {
	
	adj.first[a].push_back(b);
	
}

template<class T>
void bfs(pair<list<T>*,int> adj, T root) {
	
	bool *vis=new bool[adj.second]{false};
	
	queue<T> q;
	q.push(root);
	vis[root]=true;
	
	while(!q.empty()) {
		root=q.front();
		q.pop();
		cout<<root<<" ";
		for(auto it=adj.first[root].begin();it!=adj.first[root].end();it++) {
			if(!vis[*it]) {
				q.push(*it);
				vis[*it]=true;
			}
		}
	}
	cout<<endl;
	
}

template<class T>
void dfsUtil(pair<list<T>*,int> adj,bool **vis, T root) {
	
	stack<T> s;
	s.push(root);
	
	while(!s.empty()) {
		
		root=s.top();
		s.pop();
		if(!(*vis)[root]) {
			cout<<root<<" ";
			(*vis)[root]=true;
		}
		
		for(auto it=adj.first[root].begin();it!=adj.first[root].end();++it) {
			
			if(!(*vis)[*it]) {
				s.push(*it);
			}
		}
	}
	
}

template<class T>
void dfs(pair<list<T>*,int> adj) {
	
	bool *vis=new bool[adj.second]{false};
	
	for(int i=0;i<adj.second;i++) {
		dfsUtil(adj,&vis,i);
	}
	cout<<endl;
	
}

template<class T>
bool detectCycleDirected(pair<list<T>*,int> adj) {
	
	T root=0;
	
	bool vis[adj.second]={false};
	bool recStack[adj.second]{false};
	
	stack<T> s;
	s.push(root);
	recStack[root]=true;
	
	while(!s.empty()) {
		
		root=s.top();
		s.pop();
		
		if(!vis[root]) {
			vis[root]=true;
		}
		
		for(auto it=adj.first[0].begin();it!=adj.first[0].end();++it) {
			if(!vis[*it]) {
				s.push(*it);
				recStack[*it]=true;
			}
			else {
				if(recStack[*it])
					return true;
			}
		}
		
		recStack[root]=false;
		
	}
	return false;
	
}

int unionFind(int dset[],int i) {
	
	if(dset[i]==-1)
		return i;
	
	return unionFind(dset,dset[i]);
	
}

void unionMerge(int dset[],int i,int j) {
	int x=unionFind(dset,i);
	int y=unionFind(dset,j);
	dset[x]=y;
}

template<class T>
bool detectCycleUndirected(pair<list<T>*,int> adj) {
	
	int dset[adj.second]{-1};
	
	for(int i=0;i<adj.second;i++) {
		for(auto it=adj.first[i].begin();it!=adj.first[i].end();++it) {
			int x=unionFind(dset,i);
			int y=unionFind(dset,*it);
			if(x==y)
				return true;
			unionMerge(dset,x,y);
		}
	}
	return false;
	
}

template<class T>
bool detectCycleUndirected2(pair<list<T>*,int> adj) {
	
	T root=0;
	
	bool vis[adj.second]{false};
	stack<T> s;
	s.push(root);
	
	while(!s.empty()) {
		
		root=s.top();
		s.pop();
		
		if(!vis[root]) {
			vis[root]=true;
		}
		
		for(auto it=adj.first[root].begin();it!=adj.first[root].end();++it) {
			if(vis[*it] && *it!=root)
				return true;
			else {
				s.push(*it);
			}
		}
	}
	return false;
	
}

template<class T>
void printTopologicalSortUtil(pair<list<T>*,int> adj,int i,bool vis[],stack<T> &s) {
	
	vis[i]=true;
	
	for(auto it=adj.first[i].begin();it!=adj.first[i].end();++it) {
		if(!vis[*it]) {
			printTopologicalSortUtil(adj,*it,vis,s);
		}
	}
	s.push(i);
}

template<class T>
void printTopologicalSort(pair<list<T>*,int> adj) {
	
	bool vis[adj.second]{false};
	stack<T> s;
	
	for(int i=0;i<adj.second;++i) {
		if(!vis[i])
			printTopologicalSortUtil(adj,i,vis,s);
	}
	
	while(!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	
}

int main(int argc,char** argv) {
	
	pair<list<int>*,int> G1=createGraph<int>(4);
	
	insert(G1,0,1);
	insert(G1,0,2);
	insert(G1,1,2);
	insert(G1,2,0);
	insert(G1,2,3);
	insert(G1,3,3);
	
	bfs(G1,2);
	
	dfs(G1);
	
	if(detectCycleDirected(G1)) {
		cout<<"Cycle Detected!"<<endl;
	}
	else
		cout<<"No cycle!"<<endl;
	
	pair<list<int>*,int> G2=createGraph<int>(4);
	
	insert(G2,0,1);
	insert(G2,1,2);
	insert(G2,2,0);
	
	if(detectCycleUndirected(G2)) {
		cout<<"Cycle Detected!"<<endl;
	}
	else
		cout<<"No cycle!"<<endl;
	
	if(detectCycleUndirected2(G2)) {
		cout<<"Cycle Detected!"<<endl;
	}
	else
		cout<<"No cycle!"<<endl;
	
	pair<list<int>*,int> G3=createGraph<int>(3);
	
	insert(G2,0,1);
	insert(G2,1,2);
	
	if(detectCycleUndirected2(G3)) {
		cout<<"Cycle Detected!"<<endl;
	}
	else
		cout<<"No cycle!"<<endl;
	
	pair<list<int>*,int> G4=createGraph<int>(6);
	
	insert(G4,5,2);
	insert(G4,5,0);
	insert(G4,4,0);
	insert(G4,4,1);
	insert(G4,2,3);
	insert(G4,2,1);
	
	printTopologicalSort(G4);
	
	return 0;
}