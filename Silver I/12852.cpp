// 12852  1로 만들기 2
// https://www.acmicpc.net/source/39268371

#include <stdio.h>
#include <queue>

using namespace std;

int N;
queue <int> q;
pair <int, int> visited[1000002];

void print(int idx, int cnt) {
    if(idx == 0) {
        printf("%d\n", cnt - 1);
        return;
    }
    print(visited[idx].first, cnt + 1);
    printf("%d ", idx);
}

int main() {
    scanf("%d", &N);
    q.push(N);
    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        if(idx == 1) break;

        if(idx % 3 == 0 && visited[idx/3].first == 0) {
            visited[idx/3].first = idx;
            visited[idx/3].second = 1;
            q.push(idx/3); 
        }
        if(idx % 2 == 0 && visited[idx/2].first == 0) {
            visited[idx/2].first = idx;
            visited[idx/2].second = 2;
            q.push(idx/2);
        }
        if(visited[idx - 1].first == 0) {
            visited[idx-1].first = idx;
            visited[idx-1].second = 3;
            q.push(idx - 1);
        }
    }
    print(1, 0);
    return 0;
}