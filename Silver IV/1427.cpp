//1427  소트인사이드

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char num[10];

int main() {
    scanf("%s",num);
    sort(num,num+strlen(num),[](char a,char b){
        return a>b;
    });
    printf("%s",num);
    return 0;
}