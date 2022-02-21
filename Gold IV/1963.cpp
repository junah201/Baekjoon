// 1963  소수 경로
// https://www.acmicpc.net/source/39067391

#include <stdio.h>
#include <queue>

using namespace std;

int T, result;

struct num {
    int value;
    int time;
} start, idx, temp;

bool is_prime(int num) {
    for(int i=2;i*i<=num;i++) if(num%i==0) return 0;
    return 1;
}

int change(int value, int jali, int x) {
    int arr[4];
    for(int i=3;i>=0;i--) {
        arr[i] = value % 10;
        value /= 10;
    }
    arr[jali] = x;
    value = 0;
    for(int i=0;i<4;i++) {
        value *= 10;
        value += arr[i];
    }
    return value;
}

int bfs(int check[10010]) {
    queue <num> q;
    q.push(start);
    while(!q.empty()) {
        idx = q.front();
        if(idx.value==result) return idx.time;
        q.pop();
        for(int i=0;i<=3;i++) {
            for(int j=0;j<=9;j++) {
                if(i==0 && j==0) continue;
                int changed = change(idx.value, i, j);
                if(idx.value == changed) continue;
                if(check[changed] == 0 && is_prime(changed)) {
                    check[changed] = 1;
                    temp.value = changed;
                    temp.time = idx.time + 1;
                    q.push(temp);
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        int check[10010] = {0,};
        scanf("%d", &start.value);
        start.time = 0;
        scanf("%d", &result);
        int ans = bfs(check);
        if(ans == -1) printf("Impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}