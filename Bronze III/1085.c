//1085  정사각형에서 탈출

#include <stdio.h>
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int x,y,w,h;

int main() {
    scanf("%d %d %d %d",&x,&y,&w,&h);
	printf("%d",min(min(x,y),min(w-x,h-y)));
    return 0;
}