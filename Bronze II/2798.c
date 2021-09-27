//2798  블랙잭

#include <stdio.h>

int N,M; 
int input_Arr[100];
int check_Arr[100] = {0,};
int print_Arr[3];
int max=0;

int get(int idx) {
    if(idx==3) {
        if(print_Arr[0]+print_Arr[1]+print_Arr[2]>max && print_Arr[0]+print_Arr[1]+print_Arr[2]<=M) {
            max=print_Arr[0]+print_Arr[1]+print_Arr[2];
        }
        return 0;
    }
    for(int i=0;i<N;i++) {
        if(check_Arr[i]==0) {
            check_Arr[i]=1;
            print_Arr[idx]=input_Arr[i];
            get(idx+1);
            check_Arr[i]=0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&input_Arr[i]);
    get(0);
    printf("%d",max);
    return 0;
}