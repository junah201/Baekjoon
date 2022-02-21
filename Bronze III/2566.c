//2566  최댓값

#include <stdio.h>

int input[9][9];
int max=0;
int x,y;
int main() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++){
            scanf("%d",&input[i][j]);
            if(input[i][j]>max) {
                max=input[i][j];
                x=i;
                y=j;
            }
        }
    }
    printf("%d\n%d %d",max,x+1,y+1);
    return 0;
}