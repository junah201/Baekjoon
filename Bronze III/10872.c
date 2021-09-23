//10872  팩토리얼

#include <stdio.h>

int N;

int get(int idx,int result){
    if(idx-1==N) return result;
    return get(idx+1,result*idx);
}

int main() {
    scanf("%d",&N);
    printf("%d",get(1,1));
}