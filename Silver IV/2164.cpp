//2164  카드2

#include <stdio.h>
#include <queue>

using namespace std;

queue <int> q;
int N,i;

int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        q.push(i);
    }
    while(q.size()>1) {
        if(i%2==0) {
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
        i++;
    }
    printf("%d\n",q.front());
    return 0;
}