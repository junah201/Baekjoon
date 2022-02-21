//2292  벌집

#include <stdio.h>

int main(void)
{
    int a=1, i=1;
    int N;
    scanf("%d",&N);
    if(N==1) {
        printf("1");
        return 0;
    }
    while (1) {
        a += 6 * i;
        if (a>=N) {
            printf("%d",i+1);
            break;
        }
        i++;
    }
    return 0;
}