// 1260  DFS와 BFS
// https://www.acmicpc.net/source/39104290

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;

void addEdge(vector<vector<int>> &graph, int node_a, int node_b)
{
    graph[node_a].push_back(node_b);
    graph[node_b].push_back(node_a);
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int idx) {
    visited[idx] = 1;
    printf("%d ",idx);
    for(auto i : graph[idx]) {
        if(visited[i] == 0) {
            dfs(graph, visited, i);
        }
    }
}

void bfs(vector<vector<int>> &graph, vector<bool> &visited, int start) {
    queue <int> q;
    q.push(start);
    visited[start] = 1;
    int idx;
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        printf("%d ", idx);
        for(auto i : graph[idx]) {
            if(visited[i]==0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &V);

    vector<vector<int>> graph;
    graph.resize(N+1);

    vector<bool> visited;
    visited.resize(N+1, 0);

    int t1,t2;
    while(M--) {
        scanf("%d %d", &t1, &t2);
        addEdge(graph, t1, t2);
    }
    for(int i=0;i<graph.size();i++) sort(graph[i].begin(), graph[i].end());
    dfs(graph, visited, V);
    printf("\n");
    visited.resize(0, 0);
    visited.resize(N+1, 0);
    bfs(graph, visited, V);
    return 0;
}