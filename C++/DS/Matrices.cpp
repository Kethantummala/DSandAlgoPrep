#include<bits/stdc++.h>

using namespace std;

template<class T>
void printMatrix(T **mat,int rows,int cols) {
	for(int i=0;i<rows;++i) {
		for(int j=0;j<cols;++j) {
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

template<class T>
void searchDC(T **A,int rLow,int rHigh,int cLow,int cHigh,T x) {//Time Complexity -> T(n) = 3T(n/2) + O(1) / O(n^1.58)
	int rMid=(rLow+rHigh)/2,cMid=(cLow+cHigh)/2;
	if(A[rMid][cMid]==x) {
		cout<<"Found "<<x<<" at ["<<rMid<<","<<cMid<<"]"<<endl;
		return;
	}
	
	if(rMid!=rHigh || cMid!=cLow)
		searchDC(A,rLow,rMid,cMid,cHigh,x);
	
	if(rLow==rHigh && cLow+1==cHigh) {
		if(A[rLow][cHigh]==x) {
			cout<<"Found "<<x<<" at ["<<rLow<<","<<cHigh<<"]"<<endl;
			return;
		}
	}
	
	if(A[rMid][cMid]<x && rMid+1<=rHigh) {
		searchDC(A,rMid+1,rHigh,cLow,cHigh,x);
	}
	else {
		if(cMid-1>=cLow) {
			searchDC(A,rLow,rHigh,cLow,cMid-1,x);
		}
	}
}

template<class T>
void searchBest(T **A,int n,T x) {//Time Complexity -> O(n)
	int row=0,col=n-1;
	
	while(row<n && col>=0) {
		
		if(A[row][col]==x) {
			cout<<"Found "<<x<<" at ["<<row<<","<<col<<"]"<<endl;
			return;
		}
		
		if(A[row][col]<x) {
			row++;
		}
		
		if(A[row][col]>x) {
			col--;
		}
	}
	
	cout<<"Not Found!"<<endl;
	
}

template<class T>
void printSpiral(T **mat,int rs,int re,int cs,int ce) {
	int i;
	while(rs<re && cs<ce) {
		for(i=cs;i<ce;++i) {
			cout<<mat[rs][i]<<" ";
		}
		rs++;//Move top boundary of imaginary rectangular space, 1 row down.
		for(i=rs;i<re;++i) {
			cout<<mat[i][ce-1]<<" ";
		}
		ce--;//Move right boundary of imaginary rectangular space, 1 row left.
		if(rs<re) {// To care of uneven dimensional matrices
			for(i=ce-1;i>=cs;--i) {
				cout<<mat[re-1][i]<<" ";
			}
			re--;//Move bottom boundary of imaginary rectangular space, 1 row up.
		}
		if(cs<ce) {// To care of uneven dimensional matrices
			for(i=re-1;i>=rs;--i) {
				cout<<mat[i][cs]<<" ";
			}
			cs++;//Move left boundary of imaginary rectangular space, 1 row right.
		}
	}
	cout<<endl;
}

template<class T>
T** createMatrix(int rows,int cols) {// Generates a matrix with sequential numbers strating from 1 and returns it.
	int **mat;
	mat=new int*[rows];
	for(int i=0;i<rows;++i) {
		mat[i]=new int[cols];
	}
	
	int value=1;
	for(int i=0;i<rows;++i) {
		for(int j=0;j<cols;++j) {
			mat[i][j]=value++;
		}
	}
	return mat;
}

template<class T>
void transformBooleanMatrix(T **mat,int rows,int cols) {
	int rowFlag=0,colFlag=0;
	for(int i=0;i<cols;++i) {
		if(mat[0][i]==1) {
			rowFlag=1;
			break;
		}
	}
	for(int i=0;i<rows;++i) {
		if(mat[i][0]==1) {
			colFlag=1;
			break;
		}
	}
	
	for(int i=1;i<rows;++i) {
		for(int j=1;j<cols;++j) {
			if(mat[i][j]==1) {
				mat[i][0]=1;
				mat[0][j]=1;
			}
		}
	}
	
	for(int i=1;i<rows;++i) {
		for(int j=1;j<cols;++j) {
			if(mat[i][0]==1 || mat[0][j]==1) {
				mat[i][j]=1;
			}
		}
	}
	
	if(rowFlag) {
		for(int j=0;j<cols;++j) {
			mat[0][j]=1;
		}
	}
	if(colFlag) {
		for(int i=0;i<rows;++i) {
			mat[i][0]=1;
		}
	}
}

template<class T>
void printUniqueRows1(T **mat,int rows,int cols) {//Just checking previous rows.
	cout<<"\nPrinting Unique Rows in the given matrix(Function 1):"<<endl;
	for(int i=0;i<rows;++i) {
		bool unique=true;
		for(int k=0;k<i;++k) {
			unique=false;
			for(int j=0;j<cols;++j) {
				if(mat[i][j]!=mat[k][j]) {
					unique=true;
					break;
				}
			}
			if(unique)
				break;
		}
		if(unique) {
			for(int j=0;j<cols;++j) {
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}

template<class T>
void printUniqueRows2(T **mat,int rows,int cols) {//Consider each row as a binary number and convert it into a decimal number and
// store it in a BST(Balanced BST has Search in Log(n)). Add a new node if decimal is not present in BST and print the row.
	cout<<"\nPrinting Unique Rows in the given matrix(Function 2):"<<endl;
}

template<class T>
void printUniqueRows3(T **mat,int rows,int cols) {//Use hash to store each row as a string(represented by its cols i.e 1's and 0's) and search in O(1) if similar row exists.
	cout<<"\nPrinting Unique Rows in the given matrix(Function 3):"<<endl;
	unordered_set<string> hash;
	for(int i=0;i<rows;++i) {
		string key;
		for(int j=0;j<cols;++j) {
			key+=to_string(mat[i][j]);
		}
		if(hash.find(key)==hash.end()) {
			for(int j=0;j<cols;++j) {
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
			hash.insert(key);
		}
	}
}

template<class T>
int maxSizeSquareSubMatrix(T **mat,int rows,int cols) {
	T **mat2=createMatrix<T>(rows,cols);
	int ans=0;
	for(int i=0;i<rows;++i) {
		mat2[i][0]=mat[i][0];
	}
	for(int j=0;j<cols;++j) {
		mat2[0][j]=mat[0][j];
	}
	for(int i=1;i<rows;++i) {
		for(int j=1;j<cols;++j) {
			mat2[i][j]=min({mat[i][j-1],mat[i-1][j],mat[i-1][i-1]})+1;
			if(mat2[i][j]>ans)
				ans=mat2[i][j];
		}
	}
	return ans;
}

template<class T>
T** getTranspose(T **mat,int rows,int cols) {
	T **mat2=new T*[cols];
	for(int i=0;i<cols;i++) {
		mat2[i]=new int[rows];
	}
	for(int i=0;i<rows;i++) {
		for(int j=0;j<cols;++j) {
			mat2[j][i]=mat[i][j];
		}
	}
	return mat2;
}

template<class T>
T maxSumRectangle(T **mat,int rows,int cols) {
	T rowSums[rows]={0},ans;
	for(int left=0;left<cols;++left) {
		for(int right=left;right<cols;++right) {
			for(int i=0;i<rows;++i) {
				rowSums[i]+=mat[i][right];
			}
			
			//Run Kadane's algo
			T max,sum;
			int top=0,bottom=0;
			for(int j=0;j<rows;++j) {
				bottom=j;
				if(sum>max) {
					max=sum;
				}
				if(sum+rowSums[j]>0) {
					sum+=rowSums[j];
				}
				else {
					top=j;
					sum=rowSums[j];
				}
			}
			if(ans<max)
				ans=max;
		}
	}
	return ans;
}

int main(int argc, char* *argv) {
	
	int **mat,rows1=4,cols1=4;
	mat=createMatrix<int>(rows1,cols1);
	
  searchDC(mat,0,rows1-1,0,cols1-1,5);
	searchBest(mat,rows1,5);
	
	printSpiral<int>(mat,0,rows1,0,cols1);
	
	int **mat2,rows2=3,cols2=6;
	mat2=createMatrix<int>(rows2,cols2);
	printSpiral<int>(mat2,0,rows2,0,cols2);
	
	int rows3=3,cols3=4,**mat3=createMatrix<int>(rows3,cols3);
	for(int i=0;i<rows3;++i) {
		for(int j=0;j<cols3;++j) {
			mat3[i][j]=0;
		}
	}
	mat3[0][0]=1;
	mat3[1][2]=1;
	mat3[0][3]=1;
	
	transformBooleanMatrix(mat3,rows3,cols3);
	printMatrix(mat3,rows3,cols3);
	
	printUniqueRows1(mat3,rows3,cols3);
	printUniqueRows2(mat3,rows3,cols3);
	printUniqueRows3(mat3,rows3,cols3);
	cout<<"Maximum size of square sub-matrix with all 1s is:"<<maxSizeSquareSubMatrix(mat3,rows3,cols3)<<endl;
	
	int **mat3Transpose=getTranspose(mat3,rows3,cols3);
	cout<<"Transpose of matrix3 is:"<<endl;
	printMatrix(mat3Transpose,cols3,rows3);
	cout<<endl;
	
	int rows4=4,cols4=5,**mat4=createMatrix<int>(rows4,cols4);
	mat4[0][0]=1;
	mat4[0][1]=2;
	mat4[0][2]=-1;
	mat4[0][3]=-4;
	mat4[0][4]=-20;
	
	mat4[1][0]=-8;
	mat4[1][1]=-3;
	mat4[1][2]=4;
	mat4[1][3]=2;
	mat4[1][4]=1;
	
	mat4[2][0]=3;
	mat4[2][1]=8;
	mat4[2][2]=10;
	mat4[2][3]=1;
	mat4[2][4]=3;
	
	mat4[3][0]=-4;
	mat4[3][1]=-1;
	mat4[3][2]=1;
	mat4[3][3]=7;
	mat4[3][4]=-6;
	
	cout<<"Max sum of any rectangular sub matrix in mat4 is:"<<maxSumRectangle(mat4,rows4,cols4)<<endl;
	return 0;
}