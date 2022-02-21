// 2644 촌수계산
// https://www.acmicpc.net/source/39268819

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
vector<vector<int>> graph;
vector<bool> visited;

int bfs() {
    queue <pair<int, int>> q;
    q.emplace(A, 0);
    visited[A] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(cur.first == B) return cur.second;

        for(auto i : graph[cur.first]) {
            if(visited[i] == 0) {
                visited[i] = 1;
                q.emplace(i, cur.second + 1);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &N);
    graph.resize(N + 2);
    visited.resize(N + 2, 0);
    scanf("%d %d", &A, &B);
    scanf("%d", &M);
    int x, y;
    while(M--) {
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    printf("%d", bfs());
    return 0;
}