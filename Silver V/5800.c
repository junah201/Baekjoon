#include <stdio.h>

int t,n,max,min;
int map[50];

int main() {
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
        max=0;
        min=100;
        for(int j=0;j<n;j++) {  
            scanf("%d",&map[j]);
            if(max<map[j]) max=map[j];
            else if(min>map[j]) min=map[j];
        }
        //버블 정렬
        for(int j=0;j<n-1;j++) {
            for(int k=0;k<n-1-j;k++) {
                if(map[k]>map[k+1]) {
                    int temp=map[k];
                    map[k]=map[k+1];
                    map[k+1]=temp;
                }
            }
        }
        printf("Class %d\n",i);
        printf("Max %d, Min %d, Largest gat %d\n",max,min,max-min);
    }
    return 0;
}