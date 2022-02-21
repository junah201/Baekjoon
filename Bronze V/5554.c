//5554  심부름 가는 길

#include <stdio.h>
 
int I[4];
int main() {
    scanf("%d %d %d %d",&I[1],&I[2],&I[3],&I[4]);
    printf("%d %d",(I[1]+I[2]+I[3]+I[4])/60,(I[1]+I[2]+I[3]+I[4])%60);
    return 0;
}