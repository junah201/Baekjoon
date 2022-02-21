//5576  콘테스트

#include <stdio.h>

int arr[10];

int main() {
    for(int k=0;k<2;k++) {
        for(int i = 0; i < 10; i++) {
            scanf("%d", &arr[i]);
        }
        //버블 정렬
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                if(arr[j] < arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        printf("%d ",arr[0]+arr[1]+arr[2]);
    }
    return 0;
}