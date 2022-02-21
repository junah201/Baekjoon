//2798  블랙잭

#include <stdio.h>

int N,M; 
int input[100];
int check[100] = {0,};
int result[3];
int max=0;

int get(int idx,int start) {
    if(idx==3) {
        if(result[0]+result[1]+result[2]>max && result[0]+result[1]+result[2]<=M) {
            max = result[0]+result[1]+result[2];
        }
        //printf("%d %d %d\n",result[0],result[1],result[2]);
        return 0;
    }
    for(int i=start;i<N;i++) {
        if(check[i]==0) {
            check[i]=1;
            result[idx]=input[i];
            get(idx+1,i+1);
            check[i]=0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",&input[i]);
    get(0,0);
    printf("%d",max);
    return 0;
}