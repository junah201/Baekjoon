//2775  부녀회장이 될테야

#include <stdio.h>

int get(int a, int b) {
    if(a==0) return b;
    int result=0;
    for(int i=0;i<b;i++) result += get(a-1,b-i);
    return result;
}

int main() {
    int T;scanf("%d",&T);
    int n,k;
    for(int i=0;i<T;i++) {
        scanf("%d %d",&k,&n);
        printf("%d\n",get(k,n));
    }
    return 0;
}