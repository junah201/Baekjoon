//셀프 넘버

#include <stdio.h>

int get(int x) {
    int sum = x;
    while(x>0) {
        sum += x%10;
        x/=10;
    }
    return sum;
}

int check;

int main(){
    for(int i=1;i<=10000;i++) {
        check = 1;
        for(int j=1;j<i;j++) {
            if(i==get(j)){
                check = 0;
                break;
            }
        }
        if(check==1) printf("%d\n",i);
    }
    return 0;
}