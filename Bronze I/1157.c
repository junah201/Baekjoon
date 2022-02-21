//1157  단어 공부

#include <stdio.h>
#include <string.h>

char input[1000001];
int check[26]={0,};
int max=0;
int count=0;

int get(char x) {
    if((int)x>=97) return (int)x-97;
    else return (int)x-65;
    return 0;
}

int main() {
    scanf("%s",&input);
    int len = strlen(input);
    for(int i=0;i<len;i++) check[get(input[i])]+=1;
    for(int i=0;i<26;i++) {
        if(check[i]>check[max]) {
            max=i;
            count=1;
        } else if(check[i]==check[max]){
            count+=1;
        }
    }
    if(count==1) printf("%c",max+65);
    else printf("?");
    return 0;
}