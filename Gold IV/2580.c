//2580  스도쿠

#include <stdio.h>

int map[10][10];
int ten[10];
int is_print = 0;

void print_map() {
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

int get_pos(int pos) {
    if(pos<=3) return 1;
    else if(pos<=6) return 4;
    return 7;
}

void check(int x,int y) {
    //초기화
    for(int i=1;i<=9;i++) ten[i]=1;
    //x 체크
    for(int i=1;i<=9;i++) {
        ten[map[y][i]] = 0;
    }
    //y 체크
    for(int i=1;i<=9;i++) {
        ten[map[i][x]] = 0;
    }
    //3x3 체크
    for(int i=get_pos(y);i<get_pos(y)+3;i++) {
        for(int j=get_pos(x);j<get_pos(x)+3;j++) {
            ten[map[i][j]] = 0;
        }
    }
}

void f(int x,int y) {
    //출력되었을때
    if(is_print) return;
    //종료 조건
    else if(x==1&&y==10) {
        print_map();
        is_print=1;
        return;
    }
    //해당 값이 0이 아닐때
    else if(map[y][x]!=0) {
        if(x==9) f(1,y+1);
        else f(x+1,y);
        return;
    }
    //해당 값이 0일때
    else {
        for(int i=1;i<=9;i++) {
            check(x,y);
            if(ten[i]) {
                map[y][x]=i;
                if(x==9) f(1,y+1);
                else f(x+1,y);
                map[y][x]=0;
            }
        }
    }
    return;
}

int main() {
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            scanf("%d",&map[i][j]);
        }
    }
    f(1,1);
    return 0;
}