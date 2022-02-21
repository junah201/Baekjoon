//2606  바이러스

#include <stdio.h>
#include <vector>

using namespace std;

int N,M,x,y,cnt;

vector<int> v[101];
int check[101];

int dfs(int idx) {
    check[idx] = 1;
	for(int i=0;i<v[idx].size();i++) {
		if(check[v[idx][i]]==0) {
            dfs(v[idx][i]);
        }
	}
	return 0;
}

int main() {
    scanf("%d\n%d", &N, &M);
    for(int i=0;i<M;i++) {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        if(x==y) continue;
        v[y].push_back(x);
    }
    dfs(1);
    for(int i=2;i<=N;i++) cnt+=check[i];
    printf("%d",cnt);
    return 0;
}