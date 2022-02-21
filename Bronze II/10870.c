//10870  파보나치 수 5

#include <stdio.h>

int N;

int get(int idx) {
    if(idx==0) return 0;
    else if(idx==1) return 1;
    else return get(idx-1) + get(idx-2);
}

int main() {
    scanf("%d",&N);
    printf("%d",get(N));
    return 0;
}