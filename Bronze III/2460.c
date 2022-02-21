//2460  지능형 기차 2

#include <stdio.h>

int max=0;
int now;
int add,del;

int main() {
    for(int i=0;i<10;i++) {
        scanf("%d %d",&del,&add);
        now=now+add-del;
        if(now > max) max = now;
    }
    printf("%d",max);
    return 0;
}