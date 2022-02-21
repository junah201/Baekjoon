// 0과 1
// https://www.acmicpc.net/source/39211372

#include <stdio.h>
#include <queue>

using namespace std;

int T, N;

struct block {
    int re;
    char value;
} pre[20002];

void bfs() {
    queue <int> q;
    int visited[20002] = {0,};
    q.push(1);
    visited[1] = 1;
    pre[1] = {-999, '1'};

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == 0) return;

        for(int i=0;i<=1;i++) {
            int temp = (cur * 10 + i) % N;
            if(visited[temp] == 0) {
                visited[temp] = 1;
                pre[temp].re = cur;
                pre[temp].value = i + '0';
                q.emplace(temp);
            }
        }
    }
}

void print(int idx) {
    if(idx == -999) return;
    print(pre[idx].re);
    printf("%c", pre[idx].value);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        bfs();
        print(0);
        printf("\n");
    }
    return 0;
}