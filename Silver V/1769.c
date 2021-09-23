//1769  3의 배수

#include <stdio.h>
#include <string.h>
int get(char a[], int count){
    int len = strlen(a);
    if(len==1) {
        printf("%d\n",count);
        if(((int)a[0])%3==0) printf("YES");
        else printf("NO");
        return 0;
    }
    int sum = 0;
    for(int i=0;i<len;i++) sum += a[i]-'0';
    sprintf(a, "%d", sum);   
    get(a,count+1);
    return 0;
}

int main() {
    char arr[1000001];
    scanf("%s",&arr);
    get(arr,0);
    return 0;
}