//10866 덱

#include <stdio.h>

int N,idx,X,A[10000];
char cmd[10];

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",&cmd);
        //push_front
        if(cmd[0]=='p' && cmd[5]=='f') {
            scanf("%d",&X);
            for(int i=idx;i>=0;i--) {
                A[i+1]=A[i];
            }
            A[0]=X;
            idx++;
        }
        //push_back
        else if(cmd[0]=='p' && cmd[5]=='b') {
            scanf("%d",&X);
            A[idx]=X;
            idx++;
        }
        //pop_front
        else if(cmd[0]=='p' && cmd[4]=='f') {
            if(idx==0) printf("-1\n");
            else {
                printf("%d\n",A[0]);
                for(int i=0;i<idx;i++) {
                    A[i]=A[i+1];
                }
                idx--;
            }
        }
        //pop_back
        else if(cmd[0]=='p' && cmd[4]=='b') {
            if(idx==0) printf("-1\n");
            else printf("%d\n",A[--idx]);
        }
        //size
        else if(cmd[0]=='s') {
            printf("%d\n",idx);
        }
        //emtpy
        else if(cmd[0]=='e') {
            if(idx==0) printf("1\n");
            else printf("0\n");
        }
        //front
        else if(cmd[0]=='f') {
            if(idx==0) printf("-1\n");
            else printf("%d\n",A[0]);
        }
        //back
        else if(cmd[0]=='b') {
            if(idx==0) printf("-1\n");
            else printf("%d\n",A[idx-1]);
        }
    }
    return 0;
}