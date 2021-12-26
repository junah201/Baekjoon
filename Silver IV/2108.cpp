//2108  통계학

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
double sum=0,Min=4001,Max=-4001;
double Arr[500000];
int cnt[10000];
int min_Arr[10000];
int Arr_Max=0;
int Arr_idx=0;
int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%lf",&Arr[i]);
    sort(Arr,Arr+N);
    //산술평균
    for(int i=0;i<N;i++) sum+=Arr[i];
    printf("%.0lf\n",sum/(double)N);
    //중앙값
    printf("%.0lf\n",Arr[N/2]);
    /*
    if(N==1) printf("%.0lf\n",Arr[0]);
    else if(N%2==1) printf("%.lf\n",(Arr[N/2]+Arr[N/2+1])/2.0);
    else printf("%.0lf\n",Arr[N/2]);
    */
    //최빈값
    for(int i=0;i<N;i++) {
        cnt[(int)Arr[i]+4000]++;
    }
    for(int i=0;i<10000;i++) {
        if(cnt[i]>Arr_Max) Arr_Max=cnt[i];
    }
    for(int i=0;i<10000;i++) {
        if(cnt[i]==Arr_Max) {
            min_Arr[Arr_idx++]=i-4000;
        }
    }
    if(Arr_idx==1) printf("%d\n",min_Arr[0]);
    else printf("%d\n",min_Arr[1]);
    //범위
    for(int i=0;i<N;i++) {
        if(Arr[i]<Min) {
            Min=Arr[i];
        }
        if(Arr[i]>Max) {
            Max=Arr[i];
        }
    }
    printf("%.0lf",Max-Min);
    return 0;
}