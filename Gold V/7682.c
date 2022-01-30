// 7682 틱택토
// https://www.acmicpc.net/source/38356885

#include <stdio.h>

char input[20];
char map[4][4];
//  o개수 x개수 정답 개수
int oCnt = 0, xCnt = 0, aCnt, _Cnt, A1;
int is = 0;
int O, X;

int check() {
    O = 0;
    X = 0;
    //탐색
    for(int i=0;i<3;i++) {
        //가로
        if(map[i][0] + map[i][1] + map[i][2] == 3*'O') {
            O++;
        }
        if(map[i][0] + map[i][1] + map[i][2] == 3*'X') {
            X++;
        }
        //세로
        if(map[0][i] + map[1][i] + map[2][i] == 3*'O') {
            O++;
        }
        if(map[0][i] + map[1][i] + map[2][i] == 3*'X') {
            X++;
        }
    }
    //대각선 ↘
    if(map[0][0] + map[1][1] + map[2][2] == 3*'O') {
        O++;
    }
    if(map[0][0] + map[1][1] + map[2][2] == 3*'X') {
        X++;
    }
    //대각선 ↙
    if(map[2][0] + map[1][1] + map[0][2] == 3*'O') {
        O++;
    }
    if(map[2][0] + map[1][1] + map[0][2] == 3*'X') {
        X++;
    }
    return O+X;
}

int get() {
    if(input[0] == 'e') return -1;
    oCnt = 0;
    xCnt = 0;
    for(int i=0;i<9;i++) {
        //map에 입력
        map[i/3][i%3] = input[i];
        //cnt
        if(input[i]=='O') oCnt++;
        else if(input[i]=='X') xCnt++;
    }
    //xoxoxoxoxo 3 x
    if(oCnt!=xCnt && xCnt!=oCnt+1) {
        return 0;
    }
    //가득 차면
    if(oCnt + xCnt == 9) {
        check();
        if(O>0) return 0;
        else return 1;
    }
    //탐색
    aCnt = check();
    if(aCnt==1) {
        if(O==1 && oCnt<xCnt) return 0;
        else if(X==1 && xCnt==oCnt)  return 0;
        else return 1;
    }
    if(aCnt==0) {
        return 0;
    }
    for(int i=0;i<9;i++) {
        if(O==0 || X==0) {
            if(map[i/3][i%3]=='.') continue;
            char temp = map[i/3][i%3];
            map[i/3][i%3] = '.';
            if(check()==0) {
                return 1;
            }
            map[i/3][i%3] = temp;
        }
        else return 0;
    }
    return 0;
}

int main() {
    while(1) {
        scanf("%s", input);
        int result = get();
        if(result==1) printf("valid\n");
        else if(result==0) printf("invalid\n");
        else break;
    }
    return 0;
}