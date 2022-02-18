// 2448 별 찍기 - 11
// https://www.acmicpc.net/source/39282750

#include <stdio.h>

int N;
int map[1024 * 3][1024 * 6];

void get(int idx, int x, int y) {
    if(idx == 3) {
        map[y][x] = 1;
        map[y+1][x-1] = 1;
        map[y+1][x+1] = 1;
        map[y+2][x-2] = 1;
        map[y+2][x-1] = 1;
        map[y+2][x] = 1;
        map[y+2][x+1] = 1;
        map[y+2][x+2] = 1;
        return;
    }
    get(idx / 2, x - idx/2, y + idx/2);
    get(idx / 2, x, y);
    get(idx / 2, x + idx/2, y + idx/2);
}

int main() {
    scanf("%d", &N);
    get(N, N-1, 0);
    for(int y=0;y<=N-1;y++) {
        for(int x=0;x<=N*2-1;x++) {
            if(map[y][x] == 0) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}