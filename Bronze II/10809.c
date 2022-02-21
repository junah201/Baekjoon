//10809  알파벳 찾기

#include <stdio.h>
#include <string.h>

char input[101];
int check[26];

int main() {
    scanf("%s",&input);
    for(int i=0;i<26;i++) check[i] = -1;
    for(int i=0;i<strlen(input);i++) if(check[(int)input[i]-97]==-1)check[(int)input[i]-97] = i;
    for(int i=0;i<26;i++) printf("%d ",check[i]);
}