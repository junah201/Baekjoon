#include <bits/stdc++.h>
using namespace std;

int N, M, Q, cnt;
vector<vector<pair<int, int>>> graph;
vector<pair<int, pair<int, int>>> node;

void print_graph() {
    for(int i=1;i<=N;i++) {
        printf("=========\n");
        printf("%d\n", i);
        for(auto [idx, color] : graph[i]) {
            printf("%d => %d\n", idx, color);
        }
    }
}


int main() {
    scanf("%d %d %d", &N, &M, &Q);
    graph.resize(N+1);
    for(int i=0, start, end, color;i<N-1;i++) {
        scanf("%d %d %d", &start, &end, &color);
        int S_cnt = 0, E_cnt = 0;

        for(auto [tidx, tcolor] : graph[start]) {
            if(tcolor == color) {
                S_cnt = 1;
                break;
            }
        }

        for(auto [tidx, tcolor] : graph[end]) {
            if(tcolor == color) {
                E_cnt = 1;
                break;
            }
        }

        if(S_cnt && E_cnt) cnt -= 1;
        else if(S_cnt + E_cnt) cnt += 0;
        else cnt++;

        graph[start].emplace_back(end, color);
        graph[end].emplace_back(start, color);
        node.push_back({color, {start, end}});
    }

    for(int i=0, idx, color;i<Q;i++) {
        scanf("%d %d", &idx, &color);
        auto [orgin_color, tmp] = node[idx - 1];
        auto [start, end] = tmp;

        int orgin_S = 0, orgin_E = 0;
        int change_S = 0, change_E = 0;

        if(orgin_color == color) 
        {
            printf("%d\n" ,cnt);
            continue;
        }

        // print_graph();

        for(auto [tidx, tcolor] : graph[start]) {
            if(tcolor == orgin_color) {
                orgin_S++;
            }
            if(tcolor == color) {
                change_S++;
            }
        }

        for(auto [tidx, tcolor] : graph[end]) {
            if(tcolor == orgin_color) {
                orgin_E++;
            }
            if(tcolor == color) {
                change_E++;
            }
        }

        if(orgin_S >= 2 &&  orgin_E >= 2)
            cnt += 1;
        else if(orgin_S >= 2 || orgin_E >= 2)
            cnt += 0;
        else
            cnt -= 1;

        if(change_S && change_E)
            cnt -= 1;
        else if(change_S + change_E == 1)
            cnt += 0;
        else if(change_S + change_E == 0)
            cnt += 1;

        printf("%d\n", cnt);

        node[idx - 1].first = color;
        for(int i=0;i<graph[start].size();i++)
            if(graph[start][i].first == end) {
                graph[start][i].second = color;
                break;
            }
        for(int i=0;i<graph[end].size();i++)
            if(graph[end][i].first == start) {
                graph[end][i].second = color;
                break;
            }
    }
    return 0;
}