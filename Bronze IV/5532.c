//5532  방학숙제

#include <stdio.h>

int L, A, B, C, D ;

int main(){

	scanf("%d\n%d\n%d\n%d\n%d", &L, &A, &B, &C, &D);

	int Korean = 0;
	int Math = 0;

	if(A%C==0) Korean += A/C;
	else if(A%C!=0) Korean += (A/C)+1;

	if(B%D==0) Math += B/D;
	else if(B%D!=0) Math += (B/D)+1;

	if(Korean >= Math) printf("%d", L-Korean);
	else if(Math >= Korean) printf("%d", L-Math);

    return 0;
}