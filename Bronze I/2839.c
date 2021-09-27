//2839  설탕 배달

#include <stdio.h>

int main() {
    int N; scanf("%d",&N);
    int F=N/5+1,T=0;
    for(int i=0;;i++) {
        if(F-i<0) {
            printf("-1");
            goto EXIT;
        }
        for(int j=0;;j++) {
            if(5*(F-i)+3*(T+j)>N) break;
            else if(5*(F-i)+3*(T+j)==N) {
                printf("%d",(F-i)+(T+j));
                goto EXIT;
            }
        }
    }
    EXIT:
        return 0;
}