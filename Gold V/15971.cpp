// 15971  두 로봇
// 

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N,A,B;
vector <pair<int,int>> v[101010];
int check[101010];
int result=2087654321;

int dfs(int idx, int len, int max) {
	if(idx == B) {
		if(len-max<result) result=len-max;
		return 0;
	}
	for(int i=0;i<v[idx].size();i++) {
		if(check[v[idx][i].first] == 0) {
			check[v[idx][i].first] = 1;
			if(max<v[idx][i].second) dfs(v[idx][i].first, len+v[idx][i].second, v[idx][i].second);
			else dfs(v[idx][i].first, len+v[idx][i].second, max);
			check[v[idx][i].first] = 0;
		}
	}
	return 0;
}

int main() {
    scanf("%d %d %d", &N, &A, &B);
    int x, y, len;
	for(int i=0;i<N-1;i++) {
		scanf("%d %d %d",&x,&y,&len);
		v[x].push_back(make_pair(y, len));
		if(x==y) continue;
		v[y].push_back(make_pair(x, len));
	}
	check[A] = 1;
	dfs(A,0,0);
	printf("%d",result);
    return 0;
}