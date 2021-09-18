//9498	시험 성적

#include <stdio.h>

int Grade;

int main() {
    scanf("%d",&Grade);
    if(Grade>=90) 
        printf("A");
    else if(Grade>=80)
        printf("B");
    else if(Grade>=70)
        printf("C");
    else if(Grade>=60)
        printf("D");
    else
        printf("F");
    
    return 0;
}