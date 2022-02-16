#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
char map[1002][11];

int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf(" %s",map+i);
    sort(map, map+N, [](char a[11], char b[11]){
        if(a[0]>b[0]) return 0;
        return 1;
    });
    for(int i=0;i<N;i++) scanf("%s\n",map+i);
    return 0;
}