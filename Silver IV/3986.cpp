//3986  좋은 단어

#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char str[100001];

int check() {
    stack <char> s;
    int len = strlen(str);
    int in_A=0, in_B=0;
    if(len%2==1) return 0;
    for(int i=0;i<len;i++) {
        if(str[i]=='A') {
            if(in_A) {
                if(s.top()=='A') {
                    //printf("1 1 \n");
                    s.pop();
                    //in_A--;
                    in_A=0;
                }
                else {
                    //printf("1 0 \n");
                    return 0;
                }
            }
            else {
                //printf("1 2\n");
                s.push('A');
                //in_A++;
                in_A=1;
            }
        }
        else {
            if(in_B) {
                if(s.top()=='B') {
                    //printf("2 1 \n");
                    s.pop();
                    //in_B--;
                    in_B=0;
                }
                else {
                    //printf("2 0 \n");
                    return 0;
                }
            }
            else {
                //printf("2 2 \n");
                s.push('B');
                //in_B++;
                in_B=1;
            }
        }
    }
    if(in_A!=0 || in_B!=0) return 0;
    return 1;
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