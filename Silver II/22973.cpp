#include <stdio.h>
#include <queue>

using namespace std;

long long K;

struct num {
    long long value, add, time;
};

long long bfs() {
    queue <num> q;
    q.push({0,1,0});
    while(!q.empty()) {
        auto idx = q.front();
        q.pop();
        
        if(idx.value == K) return idx.time;

        printf("v: %d, a: %d, t:  %d\n", idx.value, idx.add, idx.time);

        if(!(K > 0 && K < idx.value + idx.add)) q.push({idx.value + idx.add, idx.add * 2, idx.time + 1});
        if(!(K < 0 && K > idx.value - idx.add)) q.push({idx.value - idx.add, idx.add * 2, idx.time + 1});
    }
    return -1;
}

int main() {
    scanf("%lld", &K);
    printf("%lld", bfs());
    return 0;
}