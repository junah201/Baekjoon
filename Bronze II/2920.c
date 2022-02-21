//2920  음계

#include <stdio.h>

int input[8];
int result = 0;

int main() {
    for(int i=0;i<8;i++){
        scanf("%d",&input[i]);
        result*=10;
        result+=input[i];
    }
    if(result==12345678) printf("ascending");
    else if(result==87654321) printf("descending");
    else printf("mixed");
    return 0;
}