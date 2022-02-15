// 2660 회장 뽑기
// https://www.acmicpc.net/source/39120421

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int N, ans, cnt;
vector <vector<int>> graph;
vector <bool> visited;
vector <int> grade;

void addEdge(int node_a, int node_b) {
    graph[node_a].push_back(node_b);
    graph[node_b].push_back(node_a);
}

int bfs(int start) {
    int result = 0;
    queue <pair<int, int>> q;
    q.emplace(start, 0);
    visited[start] = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        if(result < idx.second) result = idx.second;
        for(auto i : graph[idx.first]) {
            if(visited[i] == 0) {
                visited[i] = 1;
                q.emplace(i, idx.second + 1);
            }
        }
    }
    return result;
}

int main() {
    scanf("%d", &N);
    graph.resize(N+1);
    grade.resize(0);
    grade.resize(N+1,0);
    ans = 987654321;
    int t1,t2;
    while(1) {
        scanf("%d %d", &t1, &t2);
        if(t1 == -1 && t2 == -1) break;
        addEdge(t1,t2);
    }
    for(int i=1;i<=N;i++) {
        visited.resize(0, 0);
        visited.resize(N+1, 0);
        grade[i] = bfs(i);
        if(grade[i] < ans) ans = grade[i];
    }
    for(int i=1;i<grade.size();i++) if(grade[i] == ans) cnt++;
    printf("%d %d\n", ans, cnt);
    for(int i=1;i<grade.size();i++) if(grade[i] == ans) printf("%d ", i);
    return 0;
}