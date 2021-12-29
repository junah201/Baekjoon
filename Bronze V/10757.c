//10757  큰 수 A+B

#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

char num1[10001], num2[10001];
int A[10001],B[10001],C[10001];
int len1,len2;

int main() {
    scanf("%s %s", num1, num2);
    len1 = strlen(num1);
    len2 = strlen(num2);
    for(int i=0;i<len1;i++) {
        A[i] = num1[len1-1-i]-'0';
    }
    for(int i=0;i<len2;i++) {
        B[i] = num2[len2-1-i]-'0';
    }
    for(int i=0;i<max(len1,len2);i++) {
        C[i] += A[i]+B[i];
        if(C[i]>=10) {
            C[i+1] += C[i]/10;
            C[i] %= 10;
        }
    }
    if(C[max(len1,len2)]>0) {
        printf("%d", C[max(len1,len2)]);
    }
    for(int i=max(len1,len2)-1;i>=0;i--) {
        printf("%d", C[i]);
    }
    return 0;
}