//2292  벌집

#include <stdio.h>

int N,count;

int main() {
    scanf("%d",&N);
    if(N==1) {
        printf("1");
        return 0;
    }
    count=1;
    int i=7;
    while(1) {
        if(N-i>0) {
            N-=i;
            i+=6;
            count+=1;
        }else{
            break;
        }
    }
    printf("%d",count+1);
    return 0;
}

//2~7 : 2
//8~19 : 3
