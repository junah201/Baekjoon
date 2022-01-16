//1874  스택 수열

#include <stdio.h>
#include <stack>

using namespace std;

int N,idx,ridx,value,map[100000];
int result[100000];

stack<int> s;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d",&map[i]);
    value = 1;
    for(int i=0;i<N;i++) {
        while(s.empty() || s.top() <map[i]) {
            s.push(value++);
            result[ridx++]=1;
        }
        if(s.top() == map[i]) {
            s.pop();
            result[ridx++]=0;
            idx++;
        }
        else {
            printf("NO\n");
            return 0;
        }
    }
    for(int i=0;i<ridx;i++) {
        if(result[i]) printf("+\n");
        else printf("-\n");
    }
    return 0;
}