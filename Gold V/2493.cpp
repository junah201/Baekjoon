// 2493 탑
// https://www.acmicpc.net/source/39324550

#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

stack<int> s;
stack<int> idx;


int n,temp,top,add;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&temp);
        while(!s.empty()) {
            if(s.top()>temp) {
                printf("%d ",idx.top());
                break;
            } else {
                s.pop();
                idx.pop();
            }
        }
        if(s.empty()) {
            printf("%d ",0);
        }
        s.push(temp);
        idx.push(i+1);
    }
    return 0;
}