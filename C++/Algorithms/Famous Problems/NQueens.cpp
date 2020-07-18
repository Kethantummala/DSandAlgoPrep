#include<iostream>

using namespace std;

void printMat(int** A,int n) {
	
	for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
	}
	
}

bool canPlace(int i,int j,int** A,int n) {
	
	int row,col;
	for(row=0;row<=i;row++) {
		if(A[row][j]==1) {
			return false;
		}
	}
	
	for(row=i,col=j;row>=0 && col>=0;row--,col--) {
		if(A[row][col]==1) {
			return false;
		}
	}
	
	for(row=i,col=j;row>=0 && col<n;row--,col++) {
		if(A[row][col]==1) {
				return false;
		}
	}
	
	return true;
	
}

bool nQueens(int** A,int row,int n) {
	
	if(row==n)
		return true;
	
	for(int j=0;j<n;j++) {
			
		if(canPlace(row,j,A,n)) {
			
			A[row][j]=1;
			
			if(nQueens(A,row+1,n)) {
				return true;
			}
			A[row][j]=0;
			
		}
		
	}
	
	return false;
	
}

int main(int argc,char** argv) {

	int n;
	cout<<"Enter n:";
	cin>>n;
	
	int** A=new int*[n];
	
	for(int i=0;i<n;i++) {
		A[i]=new int[n]{0};
	}
	
	if(nQueens(A,0,n)) {
		
		cout<<"We solved it!"<<endl;
		
		printMat(A,n);
	}
	else
		cout<<"It cannot be solved.."<<endl;

	return 0;
}