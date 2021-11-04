//1463  1로 만들기

#include <stdio.h>

int N,min=999999999;

int get(int x, int cnt) {
    if (x==1) {
        if (cnt<min) min=cnt;
        return 0;
    }
    if (x%2==0) {
        get(x/2,cnt+1);
    } else if(x%3==0) {
        get(x/3,cnt+1);
    }
    get(x-1,cnt+1);
    return 0;
}

int main() {
    scanf("%d", &N);
    if(N==1) {
        printf("1\n");
        return 0;
    }
    get(N,0);
    printf("%d",min);
    return 0;
}