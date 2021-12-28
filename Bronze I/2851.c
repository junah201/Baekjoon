//2851  슈퍼 마리오

#include <stdio.h>

int Arr[10];
int idx = 0;
int Min = 0;
int sum = 0;

int abs(int a) {
    if(a<0) return -a;
    else return a;
}

int main() {
    for(int i=0;i<10;i++) {
        scanf("%d", &Arr[i]);
        sum+=Arr[i];
        if(abs(100-sum)<=abs(100-Min)) {
            Min = sum;
        }
    }
    printf("%d\n", Min);
    return 0;
}