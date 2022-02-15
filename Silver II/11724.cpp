// 11724 연결 요소의 개수
// https://www.acmicpc.net/source/39115647

#include <stdio.h>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> &graph, int node_a, int node_b) {
    graph[node_a].push_back(node_b);
    graph[node_b].push_back(node_a);
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int idx) {
    visited[idx] = 1;
    for(auto i : graph[idx]) if(visited[i] == 0) dfs(graph, visited, i);   
}

int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);

    vector<vector<int>> graph;
    graph.resize(N+1);

    vector<bool> visited;
    visited.resize(N+1, 0);

    int t1, t2;
    while(M--) {
        scanf("%d %d", &t1, &t2);
        addEdge(graph, t1, t2);
    }

    for(int i=1; i<=N; i++) {
        if(visited[i] == 0) {
            ans++;
            dfs(graph, visited, i);
        }
    }
    printf("%d", ans);
    return 0;
}