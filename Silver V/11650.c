//11650  좌표 정렬하기

#include <stdio.h>

int N,temp1,temp2;
int input1[100000];
int input2[100000];

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &input1[i],&input2[i]);
    }
    for(int i=0;i<N;i++) {
        for(int j=i;j<N;j++) {
            if(input1[i]>input1[j] || (input1[i]==input1[j] && input2[i]>input2[j])) {
                temp1=input1[i];
                temp2=input2[i];
                input1[i]=input1[j];
                input2[i]=input2[j];
                input1[j]=temp1;
                input2[j]=temp2;
            }
        }
    }
    for(int i=0;i<N;i++) {
        printf("%d %d\n", input1[i],input2[i]);
    }
    return 0;
}