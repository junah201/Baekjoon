//1032  명령 프롬포트

#include <stdio.h>
#include <string.h>

int N;
char str[51],temp[51];

int main() {
    scanf("%d",&N);
    scanf("%d",str);
    for(int i=0;i<N-1;i++) {
        scanf("%s",temp);
        for(int j=0;j<strlen(temp);j++) {
            if(str[j]!=temp[j]) {
                str[j]='?';
                printf("%s\n",str)
            }
        }
    }
    printf("%s\n",str);
    return 0;
}