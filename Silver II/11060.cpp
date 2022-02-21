#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;

int N;

int map[1002];
int visited[1002];

int bfs() {
    queue <int> q;
    q.push(0);
    map[N-1] = 0;
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        for(int i=1;i<=map[idx];i++) {
            if(idx + i >= N) continue;
            if(visited[idx + i] == 0 || visited[idx + i] > visited[idx] + 1) {
                visited[idx + i] = visited[idx] + 1;
                q.push(idx + i);
            }
        }
    }
    if(visited[N-1] == 0 && N != 1) return -1;
    return visited[N-1];
}

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &map[i]);
    printf("%d", bfs());
    return 0;
}