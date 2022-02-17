// 1158  오세푸스 문제
// https://www.acmicpc.net/source/39227571

#include <stdio.h>
#include <queue>

using namespace std;

queue <int> q;
queue <int> r;
int N,K,i=1;

int main() {
    scanf("%d %d",&N,&K);
    for(i=1;i<=N;i++) {
        q.push(i);
    }
    while(!q.empty()) {
        for(int i=0;i<K-1;i++) {
            q.push(q.front());
            q.pop();
        }
        r.push(q.front());
        q.pop();

    }
    printf("<");
    while(!r.empty()) {
        printf("%d",r.front());
        if(r.size()!=1) printf(", ");
        r.pop();
    }
    printf(">");
    return 0;
}