//11723  집합

#include <stdio.h>

int Arr[21];
char command[21];
int main() {
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf(" %s",command);
        if(command[0]=='a'&&command[1]=='d') {
            scanf("%d",&x);
            Arr[x]=1;
        }else if(command[0]=='r') {
            scanf("%d",&x);
            Arr[x]=0;
        }else if(command[0]=='c') {
            scanf("%d",&x);
            printf("%d\n",Arr[x]);
        }else if(command[0]=='t') {
            scanf("%d",&x);
            Arr[x]=!Arr[x];
        }else if(command[0]=='a'&&command[1]=='l') {
            for(int i=0;i<21;i++) {
                Arr[i]=1;
            }
        }else if(command[0]=='e') {
            for(int i=0;i<21;i++) {
                Arr[i]=0;
            }
        }
    }
    return 0;
}