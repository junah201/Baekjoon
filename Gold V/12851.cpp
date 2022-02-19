#include <stdio.h>
#include <queue>

using namespace std;

int N, K;
queue <pair<int, int>> q;
int ans, cnt;
int visited[100002];

int main() {
    scanf("%d %d", &N, &K);
    q.emplace(N, 0);

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        visited[cur.first] = 1;

        if(cnt) {
            if(ans != cur.second) break;
            if(K != cur.first) continue;
            cnt++;
        }

        if(!cnt && cur.first == K) {
            cnt = 1;
            ans = cur.second;
        }

        if(cur.first * 2 <= 100000 && cur.first < K && visited[cur.first * 2] == 0) {
            q.emplace(cur.first * 2, cur.second + 1);
        }
        if(cur.first + 1 <= 100000 && cur.first < K && visited[cur.first + 1] == 0) {
            q.emplace(cur.first + 1, cur.second + 1);
        }
        if(cur.first - 1 >= 0 && visited[cur.first - 1] == 0) {
            q.emplace(cur.first - 1, cur.second + 1);
        }
    }
    printf("%d\n%d", ans, cnt);
    return 0;
}