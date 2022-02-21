// 1697  숨바꼭질
// https://www.acmicpc.net/source/39107570

#include <stdio.h>
#include <queue>

using namespace std;

int N, K;
int visited[100005];

int calculate(int num, int idx) {
    if(idx == 0) return num + 1;
    else if(idx == 1) return num - 1;
    else return num * 2;
}

int bfs() {
    queue <pair<int, int>> q;
    q.emplace(N, 0);
    visited[N] = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();

        if(idx.first == K) return idx.second;

        for(int i=0;i<3;i++) {
            int result = calculate(idx.first, i);
            if(result > 100000 || result < 0) continue;
            if(visited[result] == 0) {
                q.emplace(result, idx.second + 1);
                visited[result] = 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%d", bfs());
    return 0;
}