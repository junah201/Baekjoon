//19592 장난감 경주

#include <stdio.h>
#include <algorithm>

int T,N,X,Y,V[1000],Min;



int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d %d %d",&N,&X,&Y);
        for(int j=0;j<N;j++) {
            scanf("%d",&V[j])
            if(X / V[j] < Min) {
                Min = X / V[j];
            }
        }
    }
}