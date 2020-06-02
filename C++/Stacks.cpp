#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

template<class T>
void displayStack(stack<T> s) {
	while(!s.empty()) {
		cout<<s.top()<<"\t";
		s.pop();
	}
	cout<<endl;
}

template<class T>
void displayVector(vector<T> v) {
	typename vector<T>::iterator it=v.begin();
	while(it!=v.end()) {
		cout<<*it<<"\t";
		++it;
	}
	cout<<endl;
}

bool isOperator(char c) {
	switch(c) {
		case '+':
		case '-':
		case '*':
		case '^':
		case '/': return true;
		default: return false;
	}
}

int precedence(char c) {
	switch(c) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		default : return 0;
	}
}

string convertToPost(string infix) {
	stack<char> s;
	string postfix="";
	int n=infix.size();
	for(int i=0;i<n;i++) {
		if(isOperator(infix[i])) {
			while(!s.empty() && precedence(infix[i])<=precedence(s.top())) {
				postfix+=s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
		else if(infix[i]=='(') {
			s.push(infix[i]);
		}
		else if(infix[i]==')') {
			while(!s.empty() && s.top()!='(') {
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			postfix+=infix[i];
		}
	}
	while(!s.empty()) {
		postfix+=s.top();
		s.pop();
	}
	return postfix;
}

double evaluatePost(string postfix) {
	stack<double> s;
	for(char c:postfix) {
		if(isOperator(c)) {
			double b=s.top();
			s.pop();
			double a=s.top();
			s.pop();
			switch(c) {
				case '+': s.push(a+b);
									break;
				case '-': s.push(a-b);
									break;
				case '*': s.push(a*b);
									break;
				//case '^': s.push(a^b);
				//					break;
				case '/': s.push(a/b);
									break;
			}
		}
		else {
			s.push((double)(c-'0'));
		}
	}
	return s.top();
}

string reverseStringUsingStack(string str) {
	stack<char> s;
	string reversed;
	for(char c:str) {
		s.push(c);
	}
	while(!s.empty()) {
		reversed+=s.top();
		s.pop();
	}
	return reversed;
}

bool balanced(string seq) {
	stack<char> s;
	for(char c:seq) {
		if(c=='(' || c=='{' || c=='[') {
			s.push(c);
		}
		else {
			if(c==')') {
				if(s.top()=='(') {
					s.pop();
				}
				else
					return false;
			}
		else if(c=='}') {
				if(s.top()=='{') {
					s.pop();
				}
				else
					return false;
			}
			else {
			if(s.top()=='[') {
					s.pop();
				}
				else
					return false;
			}
		}
	}
	if(s.empty())
		return true;
}

void nextGreaterElement(int A[],int n) {
	stack<int> s;
	for(int i=0;i<n;i++) {
		if(s.empty() || A[i]<=s.top()) {
			s.push(A[i]);
		}
		else {
			while(!s.empty() && s.top()<A[i]) {
				cout<<s.top()<<"\t"<<A[i]<<endl;
				s.pop();
			}
			s.push(A[i]);
		}
	}
	while(!s.empty()) {
		cout<<s.top()<<"\t"<<-1<<endl;
		s.pop();
	}
}

void insertAtBottom(stack<int> &s,int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(y);
}

void rSR(stack<int> &s) {//reverseStackRecursively
	if(s.empty()) {
		return;
	}
	int y=s.top();
	s.pop();
	rSR(s);
	insertAtBottom(s,y);
}

void sortedInsert(stack<int> &s,int x) {
	if(!s.empty() && x>s.top()) {
		int temp=s.top();
		s.pop();
		sortedInsert(s,x);
		s.push(temp);
	}
	else
		s.push(x);
}

void sortStack(stack<int> &s) {
	if(s.empty())
		return;
	int temp=s.top();
	s.pop();
	sortStack(s);
	sortedInsert(s,temp);
}

vector<int> stockSpan(vector<int> &v) {
	stack<int> s;
	int n=v.size();
	vector<int> ans;
	for(int i=0;i<n;i++) {
		if(s.empty() || v[s.top()]>v[i]) {
			s.push(i);
			ans.push_back(1);
			continue;
		}
		else {
			while(!s.empty() && v[s.top()]<=v[i]) {
				s.pop();
			}
			if(!s.empty())
				ans.push_back(i-s.top());
			else
				ans.push_back(i+1);
		}
	}
	return ans;
}

void specialPush(stack<int> &s,stack<int> &min,int x) {
	if(s.empty()) {
		s.push(x);
		min.push(x);
		return;
	}
	if(x<=min.top())
		min.push(x);
	s.push(x);
}

void specialPop(stack<int> &s,stack<int> &min) {
	if(s.top()==min.top()) {
		min.pop();
	}
	s.pop();
}

void simulateSpecialStack() {
	cout<<endl<<"***Simulating special stack(min element available)***"<<endl;
	
	stack<int> s2;
	stack<int> min2;
	specialPush(s2,min2,5);
	cout<<"Original stack: ";
	displayStack(s2);
	cout<<"Min Stack: ";
	displayStack(min2);
	specialPush(s2,min2,6);
	cout<<"Original stack: ";
	displayStack(s2);
	cout<<"Min Stack: ";
	displayStack(min2);
	specialPush(s2,min2,1);
	cout<<"Original stack: ";
	displayStack(s2);
	cout<<"Min Stack: ";
	displayStack(min2);
	
	specialPop(s2,min2);
	cout<<"Original stack: ";
	displayStack(s2);
	cout<<"Min Stack: ";
	displayStack(min2);
	specialPop(s2,min2);
	cout<<"Original stack: ";
	displayStack(s2);
	cout<<"Min Stack: ";
	displayStack(min2);
	specialPop(s2,min2);
	cout<<"Original stack: ";
	displayStack(s2);
	cout<<"Min Stack: ";
	displayStack(min2);
}

template<class T>
class stackUsingQueue2 {
	queue<T> q1;
	queue<T> q2;
	int count=0;
	
	public:
	void push(T x) {
		if(q1.empty()) {
			q1.push(x);
		}
		else {
			q2.push(x);
			while(!q1.empty()) {
				q2.push(q1.front());
				q1.pop();
			}
			queue<T> q=q1;
			q1=q2;
			q2=q;
		}
		++count;
	}
	
	void pop() {
		if(q1.empty()) {
			cout<<"Underflow!"<<endl;
		}
		else {
			q1.pop();
			--count;
		}
	}
	
	void display() {
		queue<T> q=q1;
		if(q1.empty()) {
			cout<<"Stack empty!"<<endl;
			return;
		}
		while(!q1.empty()) {
			cout<<q1.front()<<"\t";
			q1.pop();
		}
		q1=q;
		cout<<endl;
	}
};

void simulateStackUsingQueue2() {
	cout<<endl<<"***Simulating stack using Two queues***"<<endl;
	stackUsingQueue2<int> qs;
	qs.push(5);
	qs.display();
	qs.push(1);
	qs.display();
	qs.push(7);
	qs.display();
	qs.pop();
	qs.display();
	qs.pop();
	qs.display();
}

template<class T>
class stackUsingQueue {
	queue<T> q1;
	int count=0;
	
	public:
	void push(T x) {
		if(q1.empty()) {
			q1.push(x);
		}
		else {
			q1.push(x);
			for(int i=0;i<count;++i) {
				q1.push(q1.front());
				q1.pop();
			}
		}
		++count;
	}
	
	void pop() {
		if(q1.empty()) {
			cout<<"Underflow!"<<endl;
		}
		else {
			q1.pop();
			--count;
		}
	}
	
	void display() {
		queue<T> q=q1;
		if(q1.empty()) {
			cout<<"Stack empty!"<<endl;
			return;
		}
		while(!q1.empty()) {
			cout<<q1.front()<<"\t";
			q1.pop();
		}
		q1=q;
		cout<<endl;
	}
};

void simulateStackUsingQueue() {
	cout<<endl<<"***Simulating stack using One queue***"<<endl;
	stackUsingQueue<int> qs;
	qs.push(5);
	qs.display();
	qs.push(1);
	qs.display();
	qs.push(7);
	qs.display();
	qs.pop();
	qs.display();
	qs.pop();
	qs.display();
}

int main() {
	cout<<"Postfix of 'a+b*(c^d-e)^(f+g*h)-i' is: "<<convertToPost("a+b*(c^d-e)^(f+g*h)-i")<<endl;
	
	cout<<"'231*+9-' = "<<evaluatePost("231*+9-")<<endl;
	
	cout<<"Reverse of 'GeeksQuiz' is: "<<reverseStringUsingStack("GeeksQuiz")<<endl;
	
	cout<<"The given bracket sequence is: "<<(balanced("{()}[]")?"Balanced":"Not Balanced")<<endl;
	
	int TArray1[]={11, 13, 21, 3};
	nextGreaterElement(TArray1,4);
	
	stack<int> s;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	displayStack(s);
	rSR(s);
	displayStack(s);
	
	cout<<"Unsorted Stack: ";
	displayStack(s);
	sortStack(s);
	cout<<"Sorted Stack: ";
	displayStack(s);
	
	vector<int> v={100, 80, 60, 70, 60, 75, 85};
	vector<int> ans=stockSpan(v);
	cout<<"Stock span: ";
	displayVector(ans);
	
	simulateSpecialStack();
	
	simulateStackUsingQueue2();
	
	simulateStackUsingQueue();
  return 0;
}