//18429  근손실

#include <stdio.h>

int N,K;
int input_Arr[50];
int check_Arr[50] = {0,};
int count = 0;

int get(int day, int energy){
    if(energy<500) {
        return 0;
    }
    if(day==N){
        count +=1;
        return 0;
    }
    for(int i = 0;i<N;i++){
        if(check_Arr[i]==0){
            check_Arr[i] = 1;
            get(day+1,energy-K+input_Arr[i]);
            check_Arr[i] = 0;
        }
    }
    return 0;
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d",&input_Arr[i]);
    get(0,500);
    printf("%d",count);
    return 0;
}