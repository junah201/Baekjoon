//3008  킹, 퀸, 룩, 비숍, 나이트, 폰

#include <stdio.h>

int check[6] = {1,1,2,2,2,8};
int input[6];

int main() {
    for(int i=0;i<6;i++) {
        scanf("%d",&input[i]);
        printf("%d ",check[i]-input[i]);
    }
    return 0;
}