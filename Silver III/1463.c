//1463  1로 만들기

#include <stdio.h>

//재귀 풀이 - 시간초과
/*
int N,cnt=0,min_cnt;

int get(int a, int cnt) {
    if(a==1) {
        if(cnt<min_cnt) min_cnt = cnt;
        return 0;
    }
    if(a%3==0) get(a/3, cnt+1);
    if(a%2==0) get(a/2, cnt+1);
    if(a!=1) get(a-1, cnt+1);
    return 0;
}

int main() {
    scanf("%d", &N);
    if(N==1) {
        printf("0\n");
        return 0;
    }
    min_cnt=N;
    get(N,cnt);
    printf("%d", min_cnt);
    return 0;
}
*/