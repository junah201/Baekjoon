//15596  정수 N개의 합

#include <vector>

long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(int i=0;i<a.size();i++) ans+=a[i];
    return ans;
}