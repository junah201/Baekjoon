//10817  세 수

#include <stdio.h>

int arr[3],tmp;

int main() {
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	for(int i=0; i<3; i++)
		for(int j=0; j<2; j++)
			if(arr[j] >= arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
	printf("%d\n", arr[1]);
	return 0;
}