//1977  완전제곱수

#include <stdio.h>

int n,m,min,sum,i;

int main() {
    scanf("%d %d",&n,&m);
    for(i=1;i*i<=m;i++) {
        if(i*i>=n) {
            min=i*i;
            sum=i*i;
            break;
        }
    }
    for(i=i+1;i*i<=m;i++) {
        sum+=i*i;
    }
    if(sum==0) printf("-1");
    else printf("%d\n%d",sum,min);
    return 0;
}