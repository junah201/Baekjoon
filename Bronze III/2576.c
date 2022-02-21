#include <stdio.h>

int input, sum, min = 987654321;

int main() {
    for(int i=0;i<7;i++) {
        scanf("%d", &input);
        if(input % 2 == 1) {
            sum += input;
            if(min > input) min = input;
        }
    }
    if(sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
    return 0;
}