//5622  다이얼

#include <stdio.h>
#include <string.h>

int alpha[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
char input[16];
int sum = 0,len;

int main() {
    scanf("%s",input);
    len = strlen(input);
    for(int i=0;i<len;i++) {
        sum+=alpha[input[i]-'A'];
    }
    printf("%d",sum);
    return 0;
}