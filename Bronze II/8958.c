//8958  OX퀴즈

#include <stdio.h>
#include <string.h>
int N,grade,add;
char input[81];

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",&input);
        grade = 0;
        add = 0;
        for(int i=0;i<strlen(input);i++) {
            if(input[i]=='O'){
                add+=1;
                grade+=add;
            } else {
                add=0;
            }
        }
        printf("%d\n",grade);   
    }
    return 0;
}