#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int corrnt;

int ans;

void dfs(int idx, int value) {
    if(idx == v.size()) {
        if(corrnt == value) ans++;
        return;
    }
    dfs(idx + 1, value | v[idx]);
    dfs(idx + 1, value);
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        char tmp[102];
        scanf(" %s", tmp);
        int tmp_len = strlen(tmp);
        int tmp_int = 0;
        for(int j=0;j<tmp_len;j++) {
            tmp_int |= (1 << tmp[j] - 'A');
        }
        v.push_back(tmp_int);
    }

    corrnt = (1<<26) - 1;

    dfs(0, 0);

    printf("%d", ans);
    return 0;
}