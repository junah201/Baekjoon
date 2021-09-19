//1546  평균

#include <stdio.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

int N;
float sum = 0;
int input[1000];
int max=0;

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf(" %d",&input[i]);
        max = max(max,input[i]);
    }
    for(int i=0;i<N;i++) {
        sum += 1.0*input[i]/max*100;
    }
    printf("%.2f",1.0*sum/N);
    return 0;
}