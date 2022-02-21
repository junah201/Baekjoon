//2824  파티가 끝나고 난 뒤

#include <stdio.h>

int L,P;
int input;

int main() {
    scanf("%d %d",&L,&P);
    for(int i=0;i<5;i++) {
        scanf(" %d",&input);
        printf("%d ",input-L*P);
    }
    return 0;
}