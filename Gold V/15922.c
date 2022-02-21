//15922  아우으 우아으이야!!

#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):-(a))

int N,ans,x,y,bx,by;

int main() {
    scanf("%d", &N);
    scanf("%d %d", &bx, &by);
    ans = abs(bx-by);
    for(int i=0;i<N-1;i++) {
        scanf("%d %d", &x, &y);
        if(by<=x && x<y) {
            ans += abs(y-x);
        }
        else if(x < by && by <= y) {
            ans += abs(by-y);
        }
        by = max(y,by);
    }
    printf("%d",ans);
    return 0;
}