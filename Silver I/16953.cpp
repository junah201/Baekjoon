// 16953  A → B
// https://www.acmicpc.net/source/39116378

#include <stdio.h>
#include <queue>

using namespace std;

long long A, B;

int bfs() {
    queue <pair<long long, int>> q;
    q.emplace(A, 1);
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();

        if(idx.first == B) return idx.second;

        if(idx.first * 2 <= B) q.emplace(idx.first * 2, idx.second + 1);
        if(idx.first * 10 + 1 <= B) q.emplace(idx.first * 10 + 1, idx.second + 1);
    }
    return -1;
}

int main() {
    scanf("%d %d", &A, &B);
    printf("%d", bfs());
    return 0;
}