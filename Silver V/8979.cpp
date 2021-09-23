//8979  올림픽

#include <stdio.h>
#include <algorithm>

using namespace std;

long long int input[1000];
long long int sort_data[1000];
long long int N,K,a,b,c,d;
long long int scan,idx,temp;

bool compare(int i, int j){
    return j<i;
}

int main() {
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        input[a] = 10000*10000*b+10000*b+c;
        if(a==K) scan = input[a];
        input[a] = input[a]*10 + a;
    }

    sort(input,input+N,compare);
    idx=0;
    for(int i=0;i<N;i++) {
        if(input[i]/10!=input[i+1]/10) sort_data[idx++] = input[i];
    }

    for(int i=0;i<idx;i++) {
        if(input[i]/10==scan) printf("%d",i+1);
    }

    return 0;
}