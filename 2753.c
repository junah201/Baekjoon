//2753	윤년

#include <stdio.h>

int year;

int main() {
    scanf("%d",&year);
    if ((year%4==0 && year%100!=0) || year%400==0)
        printf("1");
    else
        printf("0"); 
    
    return 0;
}