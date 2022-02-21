#include <stdio.h>
// 2467  용액
// https://www.acmicpc.net/source/39267393

#include <algorithm>

int N;
long long map[100000];

long long abs(long long a){
    if(a<0) return -a;
    return a;
}

void tp() {
    int low = 0,high = N-1;
    long long min=abs(map[low]+map[high]);
    long long ans1=map[low],ans2=map[high];
    while(low<high) {
        if(abs(map[low]+map[high])<min) {
            min = abs(map[low]+map[high]);
            ans1 = map[low];
            ans2 = map[high];
        }
        if(map[low]+map[high]>0) high--;
        else low++;
    }
    printf("%lld %lld",ans1,ans2);
}

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%lld",&map[i]);
    std::sort(map,map+N);
    tp();
    return 0;
}