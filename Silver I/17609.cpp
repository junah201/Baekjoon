//17609  회문

#include <stdio.h>
#include <string.h>

#define min(a,b)  (((a) < (b)) ? (a) : (b))

int N;
char input[100001];

int get(int idx1, int idx2, int check) {
    if(check==2) return 2;
    if(idx1>=idx2) {
        if(check==1) return 1;
        else if(check>1) return 2;
        else return 0;
        return 0;
    }
    if(input[idx1]==input[idx2]) return get(idx1+1,idx2-1,check);
    else if(input[idx1+1]==input[idx2]||input[idx1]==input[idx2-1]) return min(get(idx1+2,idx2-1,check+1),get(idx1+1,idx2-2,check+1));
    else return 2;
    return 0;
}   

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%s",&input);
        printf("%d\n",get(0,strlen(input)-1,0));
    }
    return 0;
}