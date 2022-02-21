#include <stdio.h>
#include <algorithm>

using namespace std;

int t,n,Max,Min,Gap;
int map[50];

int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        for(int j=0;j<n;j++) {
            scanf("%d",&map[j]);
        }
        Max=0;
        Min=100;
        Gap=0;
        sort(map,map+n);
        for(int j=0;j<n;j++) {
            if(map[j+1]-map[j]>Gap&&j!=n-1) {
                Gap=map[j+1]-map[j];
            }   
            if(map[j]-map[j+1]>Gap&&j!=n-1) {
                Gap=map[j]-map[j+1];
            }
            if(map[j]>Max) {
                Max=map[j];
            }
            if(map[j]<Min) {
                Min=map[j];
            }
        }
        printf("Class %d\n",i);
        printf("Max %d, Min %d, Largest gap %d\n",Max,Min,Gap);
    }
    return 0;
}