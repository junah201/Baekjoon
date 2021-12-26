//11650  좌표 정렬하기

#include <stdio.h>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};

point xy[100000];

int N,temp1,temp2;

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &xy[i].x,&xy[i].y);
    }
    sort(xy, xy+N, [](point a, point b) {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    });
    for(int i=0;i<N;i++) {
        printf("%d %d\n", xy[i].x,xy[i].y);
    }
    return 0;
}