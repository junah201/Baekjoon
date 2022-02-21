//19944  뉴비의 기준은 뭘까?

#include <stdio.h>

int N,M;

int main() {
    scanf("%d %d",&N,&M);
    if(M<=2) printf("NEWBIE!");
    else if(M<=N) printf("OLDBIE!");
    else printf("TLE!");
    return 0;
}