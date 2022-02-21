//1316  그룹 단어 체커

#include <stdio.h>
#include <string.h>

int N,len,cnt;
char str[101];
int alpha[26];

int check() {
    for(int i=0;i<len;i++) {
        if(alpha[str[i]-'a']==0) {
            alpha[str[i]-'a']++;
        }
        else if(str[i]==str[i-1]) {
            alpha[str[i]-'a']++;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",str);
        len=strlen(str);
        for(int i=0;i<26;i++) alpha[i]=0;
        cnt += check();
    }
    printf("%d",cnt);
    return 0;
}