#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N=12,N2;
int *A=new int[N],*B;


void display_array() {
	int n=N;
	cout<<"[";
	for(int i=0;i<n;i++) {
		cout<<A[i]<<",";
	}
	cout<<"]"<<endl;
}

void swap(int &a,int &b) {
	int t=a;
	a=b;
	b=t;
}

int gcd(int a,int b) {
	int ans=1,limit=a;
	if(a==b)
		return a;
	if(b<a) {
		limit=b;
	}
	for(int i=2;i<=limit;i++) {
		if(a%i==0 && b%i==0)
			ans=i;
	}
	return ans;
}

int unsorted_search(int x) {		//Linear search
	for(int i=0;i<N;i++) {
		if(A[i]==x) {
			cout<<"Found:"<<x<<" at index : "<<i<<endl;
			return i;
		}
	}
	cout<<"Element not found."<<endl;
	return -1;
}

int sorted_search(int x) {		//Binary search
	int low=0,high=N-1,mid=(low+high)/2;
	while(A[mid]!=x && low<(high-1)) {
		if(x<A[mid]) {
			high=mid;
		}
		else {
			low=mid;
		}
		mid=(low+high)/2;
	}
	if(A[mid]==x) {
		cout<<"Found:"<<x<<" at index : "<<mid<<endl;
		return mid;
	}
	else if(A[mid+1]==x) {
		cout<<"Found:"<<x<<" at index : "<<mid+1<<endl;
		return mid+1;
	}
	cout<<"Element not found."<<endl;
	return -1;
}

int sorted_search_ranged(int x,int low,int high) {		//Binary search
	int mid=(low+high)/2;
	while(A[mid]!=x && low<(high-1)) {
		if(x<A[mid]) {
			high=mid;
		}
		else {
			low=mid;
		}
		mid=(low+high)/2;
	}
	if(A[mid]==x) {
		cout<<"Found:"<<x<<" at index : "<<mid<<endl;
		return mid;
	}
	else if(A[mid+1]==x) {
		cout<<"Found:"<<x<<" at index : "<<mid+1<<endl;
		return mid+1;
	}
	cout<<"Element not found."<<endl;
	return -1;
}

void insert(int x,int ind) {
	int *temp=(int*)malloc(sizeof(int)*(++N));
	int i;
	for(i=0;i<N-1;i++) {
		temp[i]=A[i];
	}
	temp[i]=x;
	if(ind>=N) {
		cout<<"Inserted at end due to overflow, ";
	}
	else {
		swap(temp[ind],temp[i]);
		cout<<"Insertion at given position was successful, ";
	}
	A=temp;
	cout<<"Array after insertion: ";
	display_array();
}

void delete_array_ele(int x) {
	int i=unsorted_search(x),j;
	if(i==-1) {
		return;
	}
	int *temp=(int*)malloc(sizeof(int)*(--N));
	for(j=0;j<i;j++) {
		temp[j]=A[j];
	}
	while(j<N) {
		temp[j]=A[j+1];
		j++;
	}
	cout<<"Deletion successful, ";
	A=temp;
	cout<<"Array after deletion: ";
	display_array();
}

void reverse() {
	int i=0,j=N-1;
	while(i<N/2) {
		swap(A[i++],A[j--]);
	}
	cout<<"Reversed array: ";
	display_array();
}

void show_leaders() {
	int cmax=INT_MIN;
	reverse();
	cout<<"Leaders : ";
	for(int i=0;i<N;i++) {
		if(A[i]>cmax) {
			cout<<A[i]<<",";
		}
	}
	cout<<endl;
	reverse();
}

//	***************************

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int low, int high) 
{ 
    int pivot = A[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (A[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(A[i], A[j]); 
        } 
    } 
    swap(A[i + 1], A[high]); 
    return (i + 1); 
} 

void quickSort(int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(low, pi - 1); 
        quickSort(pi + 1, high); 
    } 
}

//	***************************

void check_sum_pair(int sum) {
	quickSort(0,N-1);
	int i=0,j=N-1;
	while(i<j) {
		if(A[i]+A[j]==sum) {
			cout<<"Pair exists!"<<endl;
			return;
		}
		if(A[i]+A[j]<sum) {
			i++;
		}
		else {
			j--;
		}
	}
	cout<<"Pair doesn't exist.."<<endl;
}

void moores_voting_algo_check() {
	int piv_ind=0,count=1;
	for(int i=piv_ind+1;i<N;i++) {
		if(A[i]==A[piv_ind]) {
			count++;
		}
		else {
			count--;
		}
		if(count==0) {
			piv_ind=i;
			count=1;
		}
	}
	if(count>1) {
		cout<<"Majority exists! and the winner is : "<<A[piv_ind]<<endl;
		return;
	}
	count=0;
	for(int i=0;i<N;i++) {
		if(A[i]==A[piv_ind])
			if(++count>(N/2)) {
				cout<<"Majority exists! and the winner is : "<<A[piv_ind]<<endl;
				return;
			}
	}
	cout<<"Majority doesn't exist"<<endl;
}

int odd_occuring_number() {
	int ans=A[0];
	for(int i=1;i<N;i++) {
		ans^=A[i];
	}
	return ans;
}

int kadanes_algo_max_subarray() {
	int sum=0,ans=0;
	for(int i=0;i<N;i++) {
		if(sum+A[i]<A[i]) {
			sum=A[i];
		}
		else {
			sum+=A[i];
		}
		if(sum>ans) {
			ans=sum;
		}
	}
	return ans;
}

int find_missing_num_in_range(int start) {	//Dont need end cause it has to be start+N for this question to be meaningful.
	int a=start,b=0;
	for(int i=0;i<N;i++) {
		b^=A[i];
		a^=++start;
	}
	return a^b;
}

void find_sorted_rotated_1(int x) {
	int low=0,high=N-1,mid=(low+high)/2,piv_ind;
	while(low<(high-1)) {
		cout<<"low:"<<low<<",high:"<<high<<",mid:"<<mid<<endl;
		if(A[mid]>A[high]) {
			low=mid;
		}
		else if(A[low]>A[mid]){
			high=mid;
		}
		mid=(low+high)/2;
	}
	piv_ind=high;
	if(sorted_search_ranged(x,0,piv_ind-1)==-1)
		sorted_search_ranged(x,piv_ind,N-1);
}

void find_sorted_rotated_2(int x) {
	int low=0,high=N-1,mid=(low+high)/2;
	while(A[mid]!=x && low<(high-1)) {
		if(A[low]<A[mid]) {
			if(x<A[mid] && x>=A[low]) {
				sorted_search_ranged(x,low,mid);
				return;
			}
			else {
				low=mid;
			}
		}
		else {
			if(x>A[mid] && x<=A[high]) {
				sorted_search_ranged(x,mid+1,high);
				return;
			}
			else {
				high=mid;
			}
		}
		mid=(low+high)/2;
	}
	if(A[mid]==x) {
		cout<<"Found:"<<x<<" at index : "<<mid<<endl;
	}
	else if(A[mid+1]==x) {
		cout<<"Found:"<<x<<" at index : "<<mid+1<<endl;
	}
}

void merge_unequal_sorted_arrays() {
	//push all elements in A to right end.
	int j=N-1;
	for(int i=N-1;i>=0;i--) {	//N=N2+m
		if(A[i]!=-1) {
			A[j--]=A[i];
		}
	}
	display_array();
	int k=0;//index of second array elements.
	j++;//To get frist index of first array elements.
	for(int i=0;i<N;i++) {
		if(B[k]<=A[j] || j==N) {
			A[i]=B[k++];
		}
		else {
			A[i]=A[j++];
			A[j-1]=-1;
		}
	}
	display_array();
}

int median_two_sorted_arrays() {
	int m1=-1,m2=-2,l1=0,l2=0,h1=N-1,h2=N2-1;
	while((h1-l1)>1 || (h2-l2)>1) {
		int t1=(l1+h1)/2;
		if((h1-l1)+1%2==0)
			m1=A[t1]+A[t1-1];
		else
			m1=A[t1];
		int t2=(l2+h2)/2;
		if((h2-l2)+1%2==0)
			m2=B[t2]+B[t2-1];
		else
			m2=B[t2];
		
		//cout<<t1<<","<<t2<<","<<m1<<","<<m2<<endl;			Debugging
		if(m1==m2)
			return m1;
		
		if(m1<m2) {
			l1=t1;
			h2=t2;
		}
		else {
			h1=t1;
			l2=t2;
		}
	}
	return (max(A[l1],A[l2])+min(A[h1],B[h2]))/2;
}

void rotate_juggling(int d) {
	int g=gcd(d,N),j,piv=0;
	for(int i=0;i<d;i++) {
		j=piv;
		while(j<(N-g)) {
			swap(A[j],A[j+g]);
			j+=g;
		}
		piv++;
		if(piv>=g) {
			piv=0;
		}
	}
	cout<<"After rotation:";
	display_array();
}

int maxsum_nonadjacent() {
	int inc=A[0],ans,exc=0;
	ans=((inc>exc)?inc:exc);
	for(int i=1;i<N;i++) {
		inc=exc+A[i];
		exc=ans;
		ans=max(inc,exc);
	}
	return ans;
}

int main() {
	int temp[]={5, 5, 10, 100, 10, 5};
	N=sizeof(temp)/sizeof(int);
	A=temp;

	/*int temp2[] = {2,13,17,30,45};
	N2=sizeof(temp2)/sizeof(int);
	B=temp2;*/
	
	/*for(int i=0;i<N;i++) {
		A[i]=i+1;
	}
	display_array();
	insert(69,0);
	insert(70,9);
	delete_array_ele(69);
	reverse();
	show_leaders();
	check_sum_pair(0);
	moores_voting_algo_check();
	cout<<"Number occuring odd no.of times in Array is : "<<odd_occuring_number()<<endl;
	cout<<"Largest contiguous sum of any subarray in Array is : "<<kadanes_algo_max_subarray()<<endl;
	cout<<"Missing number is : "<<find_missing_num_in_range(1)<<endl;
	find_sorted_rotated_1(3);
	find_sorted_rotated_2(3);
	merge_unequal_sorted_arrays();
	cout<<"Median:"<<median_two_sorted_arrays()<<endl;
	rotate_juggling(5);*/
	cout<<"Max non-adjacent sum : "<<maxsum_nonadjacent()<<endl;
  return 0;
}