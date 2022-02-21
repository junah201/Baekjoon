// 11899 괄호 끼워넣기
// https://www.acmicpc.net/source/39324852

#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

stack <int> s;

char string[52];
int len;

int main() {
    scanf("%s", string);
    len = strlen(string);
    for(int i=0;i<len;i++) {
        if(string[i] == '(') s.push(1);
        else {
            if(!s.empty() && s.top() == 1) s.pop();
            else s.push(-1);
        }
    }
    printf("%d", s.size());
    return 0;
}