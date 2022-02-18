#include <stdio.h>
#include <vector>

using namespace std;

int N, M;

struct Node {
    int next;
    int cost;
};

vector<vector<Node>> graph;
vector<int> cost;

int get(int idx) {
    
}

int main() {
    scanf("%d %d", &N, &M);
    
    graph.resize(N + 2);
    cost.resize(N + 2);

    for(int i=1;i<=N;i++) scanf("%d", &cost[i]);
    int t1, t2, c;
    for(int i=1;i<=N;i++) {
        scanf("%d %d %d", &t1, &t2, &c);
        graph[t1].push_back({t2, c});
        graph[t2].push_back({t1, c});
    }

    return 0;
}

/*
int main() {
    vector<vector<int>> graph;
    graph.resize(10);

    vector<bool> visited;
    visited.resize(10, 0);

    addEdge(graph, 0 , 1);

    return 0;
}
*/