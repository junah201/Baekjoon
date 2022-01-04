//24039  2021은 무엇이 특별할까?

#include <stdio.h>

int is_prime[110];
int nums[110];
int n,idx;

int main() {
    scanf("%d",&n);
    for(int i=2;i<110;i++) {
        if(!is_prime[i]) {
            for(int j=2*i;j<110;j+=i) {
                is_prime[j] = 1;
            }
        }
    }
    for(int i=2;i<110;i++) {
        if(!is_prime[i]) nums[idx++]=i;
    }
    for(int i=0;i<110;i++) {
        if(nums[i]*nums[i+1]>n) {
            printf("%d",nums[i]*nums[i+1]);
            break;
        }
    }
    return 0;
}