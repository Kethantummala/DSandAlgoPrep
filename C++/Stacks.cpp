#include <iostream>
#include <string>

using namespace std;

template<class T>
class Stack {
	int cap,top;
	T *A;
	
	public:
	
	Stack(int n=100) {
		cap=n;
		A=new T[n];
		top=-1;
	}
	
	bool isFull() {
		if(top==(cap-1))
			return true;
		return false;
	}
	
	bool isEmpty() {
		if(top==-1)
			return true;
		return false;
	}
	
	T peek() {
		if(!isEmpty()) {
			return A[top];
		}
		T x;
		return x;
	}
	
	//Not a part of Stack ADT but using here for better understanding.
	void display() {
		cout<<"Stack : [";
		for(int i=top;i>=0;i--) {
			cout<<A[i]<<",";
		}
		cout<<"]"<<endl;
	}
	
	//outside declared member functions
	void push(T);
	T pop();
	
	
};

template<class T>
void Stack<T>::push(T x) {
		if(!isFull()) {
			A[++top]=x;
			return;
		}
		cout<<"Push failed."<<endl;
}

template<class T>
T Stack<T>::pop() {
		if(!isEmpty()) {
			return A[top--];
		}
		T x;
		return x;
		cout<<"Stack empty."<<endl;
}

bool isOperator(const char x) {
	switch(x) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':		return true;
		default:	return false;
	}
}

int precedence(const char x) {
	switch(x) {
		case '+': 
		case '-':
			 return 1;  
		case '*': 
		case '/':
			 return 2;  
		case '^': 
			 return 3;  
		default:
			 return 0;
	}
}

void convert(const string infix,string &postfix) {
	int n=infix.size();
	Stack<char> st(n);
	for(int i=0;i<n;i++) {
		char x=infix[i];
		if(isOperator(x)) {
			if(x=='(') {
				st.push(x);
			}
			else {
				if(x==')') {
					while(st.peek()!='\0') {
						if(st.peek()!='(') {
							postfix+=st.pop();
						}
						else {
							st.pop();
							break;
						}
					}
				}
				else {
					while((st.peek()!='\0') && precedence(x)<=precedence(st.peek())) {
						postfix+=st.pop();
					}
					st.push(x);
				}
			}
		}
		else {
			postfix+=x;
		}
	}
	while(st.peek()!='\0') {
		postfix+=st.pop();
	}
	cout<<"Converted Infix expression : ";
	cout<<infix<<"\t";
	cout<<"to\tPostfix expression : ";
	cout<<postfix<<endl;
}

int evaluate(string postfix) {
	int n=postfix.size();
	Stack<int> st(n);
	int op1,op2;//op=operand
	string cop;
	for(int i=0;i<n;i++) {
		char x=postfix[i];
		
		if(isOperator(x)) {
			st.push(stoi(cop));
			cop="";
			if(st.peek()!='\0')
				op2=st.pop();
			else {
				cout<<"Invalid expression!"<<endl;
				return -1;
			}
			
			if(st.peek()!='\0')
				op1=st.pop();
			else {
				cout<<"Invalid expression!"<<endl;
				return -1;
			}
			
			switch(x) {
			case '+':st.push(op1+op2); break;
			case '-':st.push(op1-op2); break;
			case '*':st.push(op1*op2); break;
			case '/':st.push(op1/op2); break;
			case '^':st.push(op1^op2); break;
			}
		}
		else if(x==' ') {
			st.push(stoi(cop));
			cop="";
		}
		else {
			cop+=x;
		}
	}
	return st.pop();
}

void reverse_string(string str) {
	cout<<"Reverse of : "<<str<<" is : ";
	int n=str.size();
	Stack<char> st(n);
	for(int i=0;i<n;i++) {
		st.push(str[i]);
	}
	str="";
	while(!st.isEmpty()) {
		str+=st.pop();
	}
	cout<<str<<endl;
}

//Two stacks using a single array is skipped cause its easy enough and just time consuming to implement.

bool check_brackets_balanced(const string exp) {
	int n=exp.size();
	Stack<char> s(n);
	for(int i=0;i<n;i++) {
		char x=exp[i];
		if(x=='(' || x=='[' || x=='{') {
			s.push(x);
		}
		else {
			if(s.isEmpty()) {
				return false;
			}
			if(x==')') {
				if(s.pop()!='(')
					return false;
			}
			else if(x==']') {
				if(s.pop()!='[')
					return false;
			}
			else {
				if(s.pop()!='{')
					return false;
			}
		}
	}
	if(!s.isEmpty())
		return false;
	return true;
}

void misordered_print_next_greater_element(const int A[],int n) {  //Checking if current element is greater than any previous element.	LEFT->RIGHT
	Stack<int> s(n);
	s.push(A[0]);
	for(int i=1;i<n;i++) {
		while(!s.isEmpty() && A[i]>=s.peek()) {
			cout<<"Next greater element of "<<s.pop()<<" is :"<<A[i]<<endl;
		}
		s.push(A[i]);
	}
	while(!s.isEmpty()) {
		cout<<"Next greater element of "<<s.pop()<<" is :"<<"-1"<<endl;
	}
}

void reverseordered_print_next_greater_element(const int A[],int n) {		//Checking if current element has a greater element in stack.	RIGHT->LEFT
	Stack<int> s(n);
	for(int i=n-1;i>=0;i--) {
		while(!s.isEmpty() && s.peek()<A[i]) {
			s.pop();
		}
		if(s.isEmpty()) {
			cout<<"Next greater element of "<<A[i]<<" is :"<<-1<<endl;
		}
		else {
			cout<<"Next greater element of "<<A[i]<<" is :"<<s.peek()<<endl;
		}
		s.push(A[i]);
	}
}

void insertAtBottom(Stack<int> &s,int x) {
	if(!s.isEmpty()) {
		int t=s.pop();
		insertAtBottom(s,x);
		s.push(t);
	}
	else {
		s.push(x);
	}
}

void reverse_stack_recursion(Stack<int> &s) {
	if(!s.isEmpty()) {
		int x=s.pop();
		reverse_stack_recursion(s);
		insertAtBottom(s,x);
	}
}

void sorted_insertion(Stack<int> &s,int x) {
	if(!s.isEmpty()) {
		if(x>s.peek()) {
			int t=s.pop();
			sorted_insertion(s,x);
			s.push(t);
		}
		else
			s.push(x);
	}
	else
		s.push(x);
}

void sort_stack(Stack<int> &s) {
	if(!s.isEmpty()) {
		int x=s.pop();
		sort_stack(s);
		sorted_insertion(s,x);
	}
}

void stock_span(int A[],int &spans[],int n) {
	
}

int main() {
	int A[]={100,80,60,70,60,75,85};
	int n=sizeof(A)/sizeof(int);
	/*Stack<int> s(n);
	for(int i=0;i<n;i++) {
		s.push(A[i]);
	}
	s.display();
	string infix="a+b*(c^d-e)^(f+g*h)-i";
	string postfix;
	convert(infix,postfix);
	postfix="100 200+2/5*7+";
	cout<<"Evaluation of postfix : "<<postfix<<"\t\t->\tresult : "<<evaluate(postfix)<<endl;
	string revstring="hey";
	reverse_string(revstring);
	postfix="{()}[]";
	string ans=check_brackets_balanced(postfix)?"Balanced":"Not Balanced";
	cout<<"The expression : "<<postfix<<" is : "<<ans<<endl;
	misordered_print_next_greater_element(A,n);
	reverseordered_print_next_greater_element(A,n);
	cout<<"Stack being reversed: "<<endl;
	s.display();
	reverse_stack_recursion(s);
	cout<<"Reversed Stack : "<<endl;
	s.display();
	cout<<"Unsorted stack: "<<endl;
	s.display();
	sort_stack(s);
	cout<<"Sorted Stack : "<<endl;
	s.display();*/
	int spans[n];
	stock_span(A,&spans,n);
	cout<<"Spans : [";
	for(int i=0;i<n;i++) {
		cout<<spans[i]<<",";
	}
	cout<<"]"<<endl;
  return 0; 
} 