//1193  분수 찾기

#include <stdio.h>

int num=1,x,y,N;
int xadd=1,yadd=-1;

int main() {
    scanf("%d",&N);
    while(num!=N) {
        num++;
        x+=xadd;
        y+=yadd;
        if(x==-1) {
            x=0;
            xadd=1;
            yadd=-1;
        }
        if(y==-1) {
            y=0;
            yadd=1;
            xadd=-1;
        }
    }
    printf("%d/%d",y+1,x+1);
    return 0;
}