// 2447 별 찍기 - 10
// https://www.acmicpc.net/source/39284800

#include <stdio.h>

int N;
int map[6561][6561];

void get(int idx, int x, int y) {
    if(idx == 3) {
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) map[y+i][x+j] = 1;
        map[y+1][x+1] = 0;
        return;
    }
    int temp = idx / 3;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i==1 && j==1) continue;
            get(temp, x + i * temp, y + j * temp);
        }
    }
}

int main() {
    scanf("%d", &N);
    get(N, 0, 0);
    for(int y=0;y<=N;y++) {
        for(int x=0;x<=N;x++) {
            if(map[y][x] == 0) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}