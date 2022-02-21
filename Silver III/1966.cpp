//1966  프린터 큐

#include <stdio.h>
#include <queue>

using namespace std;

int T,N,M,temp,mx,cnt;
queue <int> a;
queue <int> b;

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        while(!a.empty()) a.pop();
        while(!b.empty()) b.pop();
        cnt=0;
        scanf("%d %d",&N,&M);
        for(int j=0;j<N;j++) {
            scanf("%d",&temp);
            //printf("%d ",temp);
            a.push(temp);
            b.push(j);
        }
        //printf("\n");
        while(1) {
            mx=a.front();
            for(int k=0;k<a.size();k++) {
                if(mx<a.front()) {
                    mx = a.front();
                    //printf("mx : %d\n",mx);
                }
                a.push(a.front());
                a.pop();
                b.push(b.front());
                b.pop();
            }
            while(1) {
                if(mx==a.front()) break;
                a.push(a.front());
                a.pop();
                b.push(b.front());
                b.pop();
            }
            cnt++;
            if(b.front()==M) {
                printf("%d\n",cnt);
                break;
            }
            a.pop();
            b.pop();
        }
    }
    return 0;
}