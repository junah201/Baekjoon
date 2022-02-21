// 9019 DSLR
// https://www.acmicpc.net/source/39102545

#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int T;
int input, answer;
char cmds[4] = {'D', 'S', 'L', 'R'};

int pre_num[10002];
char pre_cmd[10002];

int calculate(int num, char cmd) {
    if(cmd == 'D') {
        return (num * 2) % 10000;
    }
    else if(cmd == 'S') {
        return (num + 9999) % 10000;
    }
    else if(cmd == 'L') {
        int arr[4];
        for(int i=3;i>=0;i--) {
            arr[i] = num % 10;
            num /= 10;
        }
        return arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[0];
    }
    else if(cmd == 'R') {
        int arr[4];
        for(int i=3;i>=0;i--) {
            arr[i] = num % 10;
            num /= 10;
        }
        return arr[3] * 1000 + arr[0] * 100 + arr[1] * 10 + arr[2];
    }
}


void bfs() {
    for(int i=0;i<10002;i++) pre_num[i] = -1;
    for(int i=0;i<10002;i++) pre_cmd[i] = -1;
    queue <int> q;
    q.push(input);
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        if(idx == answer) return;
        for(int i=0;i<4;i++) {
            int result = calculate(idx, cmds[i]);
            if(pre_num[result] == -1) {
                q.push(result);
                pre_num[result] = idx;
                pre_cmd[result] = cmds[i];
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &input, &answer);
        bfs();
        int idx = answer;
        stack <char> s;
        while(1) {
            if(idx == input) break;
            s.push(pre_cmd[idx]);
            idx = pre_num[idx];
        }
        while(!s.empty()) {
            printf("%c",s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}