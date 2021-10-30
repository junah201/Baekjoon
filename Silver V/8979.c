//8979  올림픽

#include <stdio.h>

int N,K,idx;
int count=0;

struct country
{
    int no;
    int gold;
    int silver;
    int bronze;
};

struct country ary[1000];
struct country temp;

int main() {
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d %d",&ary[i].no,&ary[i].gold,&ary[i].silver,&ary[i].bronze);
        if(ary[i].no==K) idx=i;
    }
    for(int i=0;i<N;i++) {
        if(ary[i].gold>ary[idx].gold) {
            count++;
        } else if(ary[i].gold<ary[idx].gold) {
            continue;
        } else {
            if(ary[i].silver>ary[idx].silver) {
                count++;
            } else if(ary[i].silver<ary[idx].silver) {
                continue;
            } else {
                if(ary[i].bronze>ary[idx].bronze) {
                    count++;
                }
            }
        }
    }
    printf("%d",count+1);
    return 0;
}

