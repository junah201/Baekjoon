//18870  좌표 압축

#include <stdio.h>
#include <algorithm>

using namespace std;

struct point
{
    int x;
    int idx1;
    int idx2;
};

point x[1000000];
int N,idx=0;

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&x[i].x);
        x[i].idx1 = i;
    }
    sort(x, x+N, [](point a, point b) {
        if(a.x==b.x) return a.idx1<b.idx1;
        return a.x<b.x;
    });
    x[0].idx2 = idx++;
    for(int i=1;i<N;i++) {
        if(x[i].x==x[i-1].x) x[i].idx2 = x[i-1].idx2;
        else x[i].idx2 = idx++;
    }
    sort(x, x+N, [](point a, point b) {
        return a.idx1<b.idx1;
    });
    for(int i=0;i<N;i++) {
        printf("%d ", x[i].idx2);
    }
    return 0;
}