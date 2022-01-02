//1038  감소하는 수

#include <stdio.h>
#include <algorithm>

using namespace std;

int N,cnt,i,Idx=0;
int result[10];
long long temp;
long long int map[1024] = {0};

int f(int idx) {
    if(idx == 10) {
        temp = 0;
        for(int i=9; i>=0; i--) {
            if(result[i] == 0) continue;
            temp *= 10;
            temp += i;
        }
        map[Idx++] = temp;
        return 0;
    }

    result[idx] = 1;
    f(idx+1);
    result[idx] = 0;
    f(idx+1);
    return 0;
}

int main() {
    scanf("%d",&N);
    if(N>1022) {
        printf("-1");
        return 0;
    }
    f(0);
    sort(map,map+1023);
    printf("%lld",map[N]);
    return 0;
}