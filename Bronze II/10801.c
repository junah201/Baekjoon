//10801  카드 게임

#include <stdio.h>

int A[10];
int B[10];
int Acount=0;
int Bcount=0;

int main() {
    for(int i=0;i<10;i++) scanf("%d",&A[i]);
    for(int i=0;i<10;i++) scanf("%d",&B[i]);

    for(int i=0;i<10;i++) {
        if(A[i]>B[i]) {
            Acount+=1;
        }else if(A[i]<B[i]) {
            Bcount+=1;
        }
    }

    if(Acount>Bcount) printf("A");
    else if(Bcount>Acount) printf("B");
    else printf("D");

    return 0;
}