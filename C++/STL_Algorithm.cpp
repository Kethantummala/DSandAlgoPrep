#include<iostream>
#include<algorithm>
#include<vector>

int main() {
	std::vector<int> v={5,6,20,25,20};
	std::sort(v.begin(),v.end());
	v.erase(std::unique(v.begin(),v.end()),v.end());
	auto it=v.begin();
	while(it!=v.end()) {
		std::cout<<*it<<" ";
		it++;
	}
	return 0;
}