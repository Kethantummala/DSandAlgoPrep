#include<bits/stdc++.h>

#define rows 4
#define cols 4

using namespace std;

template<class T>
void searchDC(T A[rows][cols],int rLow,int rHigh,int cLow,int cHigh,T x) {//Time Complexity -> T(n) = 3T(n/2) + O(1) / O(n^1.58)
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
void searchBest(T A[rows][cols],int n,T x) {//Time Complexity -> O(n)
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

int main(int argc, char* *argv) {
	
	int mat[4][4] = { 	{ 10, 20, 30, 40 }, 
                      { 15, 25, 35, 45 }, 
                      { 27, 29, 37, 48 }, 
                      { 32, 33, 39, 50 } }; 
	
  searchDC(mat,0,3,0,3,29);
	searchBest(mat,4,29);
	return 0;
}