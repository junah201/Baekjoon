//17256  달달함이 넘쳐흘러

#include <stdio.h>

int ax,ay,az;
int cx,cy,cz;

int main() {
    scanf("%d %d %d",&ax,&ay,&az);
    scanf("%d %d %d",&cx,&cy,&cz);
    printf("%d %d %d",cx-az,cy/ay,cz-ax);
    return 0;
}