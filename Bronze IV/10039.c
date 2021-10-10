//10039  평균 점수

#include <stdio.h>

int a,sum=0;
int main() {
    for(int i=0;i<5;i++) {
        scanf("%d",&a);
        if(a<40) sum+=40;
        else sum+=a;
    }
    printf("%d",sum/5);
    return 0;
}