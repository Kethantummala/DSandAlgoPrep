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
	
}

int main(int argc,char** argv) {
	
	pair<list<int>*,int> G1=createGraph<int>(5);
	
	insert(G1,1,0);
	insert(G1,0,2);
	insert(G1,2,1);
	insert(G1,0,3);
	insert(G1,1,4);
	
	bfs(G1,2);
	
	dfs(G1);
	
	return 0;
}