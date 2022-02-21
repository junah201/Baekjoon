//10845  큐

#include <stdio.h>

int N,X,idx,A[20000];
char cmd[10];

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",&cmd);
        if(cmd[0]=='p' && cmd[1]=='u') {
            scanf("%d",&X);
            A[idx++]=X;
        }
        else if(cmd[0]=='p' && cmd[1]=='o') {
            if(idx==0) printf("-1\n");
            else {
                printf("%d\n",A[0]);
                for(int i=0;i<idx;i++) {
                    A[i]=A[i+1];
                }
                idx--;
            }
        }
        else if(cmd[0]=='s') {
            printf("%d\n",idx);
        }
        else if(cmd[0]=='e') {
            if(idx==0) printf("1\n");
            else printf("0\n");
        }
        else if(cmd[0]=='f') {
            if(idx==0) printf("-1\n");
            else printf("%d\n",A[0]);
        }
        else if(cmd[0]=='b') {
            if(idx==0) printf("-1\n");
            else printf("%d\n",A[idx-1]);
        }
    }
    return 0;
}