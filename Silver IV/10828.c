//10828 스택

#include <stdio.h>

int n,x,stack[20000],top=-1;
char command[10];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s",command);
        if(command[0]=='p' && command[1]=='u') {
            scanf("%d",&x);
            stack[++top]=x;
        }
        else if(command[0]=='p' && command[1]=='o') {
            if(top==-1) printf("-1\n");
            else printf("%d\n",stack[top--]);
        }
        else if(command[0]=='t') {
            if(top==-1) printf("-1\n");
            else printf("%d\n",stack[top]);
        } 
        else if(command[0]=='s') {
            printf("%d\n",top+1);
        }
        else if(command[0]=='e') {
            if(top==-1) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}