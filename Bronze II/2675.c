//2675  문자열 반복

#include <stdio.h>
#include <string.h>

int T,P;
char string[100];

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d %s",&P,&string);
        for(int i=0;i<strlen(string);i++) {
            for(int j=0;j<P;j++) printf("%c", string[i]);
        }
        printf("\n");
    }
    return 0;
}