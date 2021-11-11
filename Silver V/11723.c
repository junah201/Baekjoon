//11723  집합

#include <stdio.h>
#include <string.h>

char command[10];
int arr[21];
int T,X;

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf(" %s %d",command,&X);
        if(strcmp(command, "add")) {
            arr[X]=1;
        }else if(strcmp(command, "remove")) {
            arr[X]=0;
        }else if(strcmp(command, "check")) {
            printf("%d\n",arr[X]!=0);
        }else if(strcmp(command, "toggle")) {
            arr[X]=!(arr[X]);
        }else if(strcmp(command, "all")) {
            for(int j=0;j<21;j++) {
                arr[j]=1;
            }
        }else if(strcmp(command, "empty")) {
            for(int j=0;j<21;j++) {
                arr[j]=0;
            }
        }
    }
    return 0;
}
