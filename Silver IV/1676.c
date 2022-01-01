//1676  팩토리얼 0의 개수

#include <stdio.h>

int two;
int five;
int N,temp;

int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        temp = i;
        while(temp%2==0) {
            temp/=2;
            two++;
            if(two>10) break;
        }
    }
    for(int i=1;i<=N;i++) {
        temp = i;
        while(temp%5==0) {
            temp/=5;
            five++;
        }
    }
    if(two<five) printf("%d",two);
    else printf("%d",five);
    return 0;
}