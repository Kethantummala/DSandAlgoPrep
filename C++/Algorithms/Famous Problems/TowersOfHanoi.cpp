#include<iostream>

using namespace std;

void recurHanoi(int eleInd,int src,int dest,int aux) {
	
	if(eleInd==1) {
		cout<<"Moving "<<eleInd<<" from peg"<<src<<" to peg"<<dest<<endl;
		return;
	}
	
	recurHanoi(eleInd-1,src,aux,dest);
	cout<<"Moving "<<eleInd<<" from peg"<<src<<" to peg"<<dest<<endl;
	recurHanoi(eleInd-1,aux,dest,src);
	
}

int main(int argc,char** argv) {

	recurHanoi(4,1,2,3);
	
	return 0;
}