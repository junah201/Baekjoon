// 5014  스타트링크
// https://www.acmicpc.net/source/39122200

#include <stdio.h>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visited[1000010];

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    queue <pair<int, int>> q;
    q.emplace(S, 0);
    visited[S] = 1;
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        
        if(idx.first == G) {
            printf("%d", idx.second);
            return 0;
        }
        if(idx.first + U <= F && visited[idx.first + U] == 0) {
            q.emplace(idx.first + U, idx.second + 1);
            visited[idx.first + U] = 1;
        }
        if(idx.first - D > 0 && visited[idx.first - D] == 0) {
            q.emplace(idx.first - D, idx.second + 1);
            visited[idx.first - D] = 1;
        }
    }
    printf("use the stairs");
    return 0;
}