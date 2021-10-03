//1065  한수

#include <stdio.h>

int count=0;
int num[4];
int N;

int get(int x){
    if(x<100) return 1;
    else if(x>=1000) return 0;
    else{
        int idx=0;
        while(x>0) {
            num[idx++]=x%10;
            x/=10;
        }
        if(num[0]-num[1]==num[1]-num[2]) return 1;
        else return 0;
    }
    return 0;
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        count+=get(i);
    }
    printf("%d",count);
}