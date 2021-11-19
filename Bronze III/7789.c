//7789  텔레프라임

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[8],b[8];

int check(int x) {
    for(int i=2;i*i<x;i++) {
        if(x%i==0) return 0;
    }
    return 1;
}

int main() {
    scanf("%s %s",&a,&b);
    if(check(atoi(a))&&check(atoi(strcat(b, a)))) printf("Yes");
    else printf("No");
    return 0;
}