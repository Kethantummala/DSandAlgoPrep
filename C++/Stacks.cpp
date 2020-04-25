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
		for(int i=0;i<=top;i++) {
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

int main() {
	int A[]={1,2,3,4,5,6};
	int n=sizeof(A)/sizeof(int);
	Stack<int> s(n);
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
  return 0; 
} 