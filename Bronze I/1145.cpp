//1145  적어도 대부분의 배수

#include <stdio.h>
#include <algorithm>

using namespace std;

int A[5];
int check[5];
int result[3];
int Min,Lcm=1000000;

int gcd(int a, int b) {
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int lcm(int a, int b) {
    return a*b/gcd(max(a,b),min(a,b));
}

int get(int idx) {
    if(idx==3) {
        Lcm = lcm(lcm(result[0],result[1]),result[2]);
        printf("%d %d %d : %d\n",result[0],result[1],result[2],Lcm);
        if(Lcm < Min) {
            Min = Lcm;
            printf("Min : %d\n",Min);
        }
        return 0;
    }
    for(int i=0;i<5;i++) {
        if(check[i]==0) {
            result[idx] = A[i];
            check[i] = 1;
            get(idx++);
            check[i] = 0;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d %d %d %d",&A[0],&A[1],&A[2],&A[3],&A[4]);
    get(0);
    printf("%d",Min);
    return 0;
}