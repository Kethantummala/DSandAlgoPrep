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
	T rowSums[rows]={0},ans=0;
	for(int left=0;left<cols;++left) {
		for(int z=0;z<rows;++z) {
			rowSums[z]=0;
		}
		for(int right=left;right<cols;++right) {
			for(int i=0;i<rows;++i) {
				rowSums[i]+=mat[i][right];
			}
			
			//Run Kadane's algo
			T max=INT_MIN,sum=0;
			for(int j=0;j<rows;++j) {
				if(sum+rowSums[j]>0) {
					sum+=rowSums[j];
				}
				else {
					sum=0;
				}
				if(sum>max) {
					max=sum;
				}
			}
			if(ans<max)
				ans=max;
		}
	}
	return ans;
}

template<class T>
T** multiplyNaive(T **mat1,int rows1,int cols1,T **mat2,int rows2,int cols2) {
	T **ans=createMatrix<int>(rows1,cols2);
	
	for(int i=0;i<rows1;++i) {
		for(int j=0;j<cols2;++j) {//cols in mat2
			T sum=0;
			for(int k=0;k<rows2;++k) {//rows in mat2
				sum+=mat1[i][k]*mat2[k][j];
			}
			ans[i][j]=sum;
		}
	}
	return ans;
}

template<class T>
void fillPerimeter(T **mat,char x,int rs,int re,int cs,int ce) {
	while(rs<re && cs<ce) {
		for(int i=cs;i<ce;++i) {
			mat[rs][i]=x;
		}
		rs++;
		for(int i=rs;i<re;++i) {
			mat[i][ce-1]=x;
		}
		ce--;
		if(rs<re) {
			for(int i=ce;i>=cs;--i) {
				mat[re-1][i]=x;
			}
			re--;
		}
		if(cs<ce) {
			for(int i=re;i>=rs;--i) {
				mat[i][cs]=x;
			}
			cs++;
		}
		if(x=='X')
			x='O';
		else
			x='X';
	}
}

template<class T>
T** createAlternatingXOMatrix(int rows,int cols) {
	T **mat=new T*[rows];
	for(int i=0;i<rows;++i) {
		mat[i]=new T[cols];
	}
	fillPerimeter(mat,'X',0,rows,0,cols);
	return mat;
}

template<class T>
struct SM {
	T data;
	int row;
	int nextCol;
	
	SM(T d,int r,int nC) : data(d),row(r),nextCol(nC){}
	
	bool operator<(const struct SM& S) const{
		return data>S.data;
	}
};

template<class T>
void printSorted(T **mat,int rows,int cols) {
	
	priority_queue<SM<T>> minHeap;
	
	for(int i=0;i<rows;++i) {
		minHeap.push(SM<T>(mat[i][0],i,1));
	}
	while(minHeap.size()) {
		SM<T> cur=minHeap.top();
		cout<<cur.data<<" ";
		minHeap.pop();
		if(cur.nextCol<cols) {
			minHeap.push(SM<T>(mat[cur.row][cur.nextCol],cur.row,cur.nextCol+1));
		}
	}
	cout<<endl;
}

template<class T>
void sumsOfKSizeSubSquares(T **mat,int rows,int cols,int k) {
	T **newMat=createMatrix<T>(rows-(k-1),cols);
	
	for(int i=0;i<rows-(k-1);++i)
		for(int j=0;j<cols;++j) {
			newMat[i][j]=0;
		}
	
	//Column wise sums are calculated by the two loops
	for(int j=0;j<cols;j++) {
		for(int i=0;i<k;++i) {
			newMat[0][j]+=mat[i][j];
		}
	}
	for(int j=0;j<cols;j++) {
		for(int i=k;i<rows;++i) {
			newMat[i-(k-1)][j]=newMat[i-k][j];
			newMat[i-(k-1)][j]-=mat[i-k][j];
			newMat[i-(k-1)][j]+=mat[i][j];
		}
	}
	
	//Final sums are calculated here with help of Column wise sums in the following two loops
	for(int i=0;i<rows-(k-1);i++) {
		T sum=0;
		for(int j=0;j<k;++j) {
			sum+=newMat[i][j];
		}
		cout<<sum<<" ";
		for(int j=k;j<cols;++j) {
			sum-=newMat[i][j-k];
			sum+=newMat[i][j];
			cout<<sum<<" ";
		}
		cout<<endl;
	}
}

template<class T>
int countRCSeperatedIslands(T **mat,int rows,int cols) {
	int ans=0;
	for(int i=0;i<rows;++i) {
		for(int j=0;j<cols;++j) {
			if(mat[i][j]=='X') {
				if((i>0 && mat[i-1][j]=='O') || i==0) {
					if((j>0 && mat[i][j-1]=='O') || j==0) {
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

template<class T>
T commonElementInAllRows(T **mat,int rows,int cols) {
	unordered_map<T,int> hash;
	for(int j=0;j<cols;++j) {
		hash[mat[0][j]]=1;
	}
	for(int i=1;i<rows;i++) {
		for(int j=0;j<cols;++j) {
			if(hash.find(mat[i][j])!=hash.end()) {
				hash[mat[i][j]]++;
			}
		}
	}
	for(auto it=hash.begin();it!=hash.end();++it) {
		if((*it).second==rows)
			return (*it).first;
	}
	return -1;
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
	
	int rows4=4,cols4=5,**mat4=createMatrix<int>(rows4,cols4);
	mat4[0][0]=1;
	mat4[0][1]=2;
	mat4[0][2]=3;
	mat4[0][3]=4;
	mat4[0][4]=10;
	
	mat4[1][0]=-1;
	mat4[1][1]=0;
	mat4[1][2]=4;
	mat4[1][3]=5;
	mat4[1][4]=7;
	
	mat4[2][0]=-4;
	mat4[2][1]=4;
	mat4[2][2]=10;
	mat4[2][3]=11;
	mat4[2][4]=13;
	
	mat4[3][0]=-4;
	mat4[3][1]=-1;
	mat4[3][2]=1;
	mat4[3][3]=2;
	mat4[3][4]=4;
	
	cout<<"Max sum of any rectangular sub matrix in mat4 is:"<<maxSumRectangle(mat4,rows4,cols4)<<endl;
	
	int rows5=2,cols5=2,**mat5=createMatrix<int>(rows5,cols5);
	mat5[0][0]=-4;
	mat5[0][1]=2;
	mat5[1][0]=7;
	mat5[1][1]=-13;
	
	int rows6=2,cols6=3,**mat6=createMatrix<int>(rows6,cols6);
	mat6[0][0]=-8;
	mat6[0][1]=-3;
	mat6[0][2]=4;
	
	mat6[1][0]=3;
	mat6[1][1]=8;
	mat6[1][2]=10;
	
	int **mulmat561=multiplyNaive(mat5,rows5,cols5,mat6,rows6,cols6);
	cout<<"\nMultiplied matrix of mat5 and mat6 is:"<<endl;
	printMatrix(mulmat561,rows5,cols6);
	
	int rows7=6,cols7=7;
	char **mat7=createAlternatingXOMatrix<char>(rows7,cols7);
	printMatrix(mat7,rows7,cols7);
	
	printSorted(mat4,rows4,cols4);
	
	sumsOfKSizeSubSquares(mat4,rows4,cols4,3);
	
	cout<<"No of Row and Column wise seperated islands are:"<<countRCSeperatedIslands(mat7,rows7,cols7)<<endl;
	
	cout<<"The common element in all rows in mat4 is:"<<commonElementInAllRows(mat4,rows4,cols4)<<endl;
	return 0;
}