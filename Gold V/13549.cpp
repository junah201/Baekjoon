// 13549  숨바꼭질 3
// https://www.acmicpc.net/source/39288110

#include <stdio.h>
#include <queue>

using namespace std;

int N, K;
int visited[200002];
queue <pair<int, int>> q;

int main() {
    scanf("%d %d", &N, &K);
    q.emplace(N, 0);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        if(cur.first == K) {
            printf("%d", cur.second);
            return 0;
        }

        if(cur.first * 2 <= 200000 && visited[cur.first * 2] == 0) {
            q.emplace(cur.first * 2, cur.second);
            visited[cur.first * 2] = 1;
        }
        if(cur.first - 1 >= 0 && visited[cur.first - 1] == 0) {
            q.emplace(cur.first - 1, cur.second + 1);
            visited[cur.first - 1] = 1;
        }
        if(cur.first + 1 <= 200000 && visited[cur.first + 1] == 0) {
            q.emplace(cur.first + 1, cur.second + 1);
            visited[cur.first + 1] = 1;
        }
    }
    return 0;
}