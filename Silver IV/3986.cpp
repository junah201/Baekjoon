//3986  좋은 단어

#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[100001];

int check() {
    stack <char> s;
    int len = strlen(str);
    if(len%2==1) return 0;
    for(int i=0;i<len;i++) {
        if(s.empty()) s.push(str[i]);
        else if(str[i]==s.top()) s.pop();
        else s.push(str[i]);
    }
    if(s.empty()) return 1;
    return 0;
}

int main() {
    int N,cnt=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",&str);
        cnt+=check();
    }
    printf("%d",cnt);
    return 0;
}