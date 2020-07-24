/*#include<bits/stdc++.h>
#include<typeinfo>

using namespace std;

template<class T>
void printType(T x) {
	cout<<"\nType of x:"<<typeid(x).name()<<endl;
	if(is_same<T,char>::value)
		cout<<"Found a char!"<<endl;
}

int main(int argc,char* *argv) {
	int a=2;
	float b=3.5;
	char c='c';
	printType(a);
	printType(b);
	printType(c);
	return 0;
}*/

#include<iostream>
#include<stack>

using namespace std;

void func1(int *A,int n) {
    int left[n+1];
    int right[n+1];
    for(int i=0;i<n;++i) {
        left[i]=-1;
        right[i]=n;
    }
    
    stack<int> s;
    
    for(int i=0;i<n;++i) {
        while(!s.empty() && A[s.top()]>=A[i]) {
            s.pop();
        }
        
        if(!s.empty()) {
            left[i]=s.top();
        }
        s.push(i);
    }
    
    while(!s.empty())
        s.pop();
        
    for(int i=n-1;i>=0;--i) {
        while(!s.empty() && A[s.top()]>=A[i]) {
            s.pop();
        }
        
        if(!s.empty()) {
            right[i]=s.top();
        }
        s.push(i);
    }
    
    int ans[n+1];
		for(int i=0;i<=n;i++) {
			ans[i]=0;
		}
    
    for(int i=0;i<n;++i) {
        int len=right[i]-left[i]-1;
        ans[len]=max(ans[len],A[i]);
    }
    
    for(int i=n-1;i>=1;i--) {
        ans[i]=max(ans[i],ans[i+1]);
    }
    cout<<"test";
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    
}

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;++i) {
	        cin>>A[i];
	    }
	    func1(A,n);
	}
	return 0;
}