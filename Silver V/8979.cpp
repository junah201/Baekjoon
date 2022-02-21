//8979  올림픽

#include <stdio.h>
#include <algorithm>

using namespace std;

int N,K;

struct country
{
    int no;
    int rank;
    int gold;
    int silver;
    int bronze;
};

struct country a[1000];

int main() {
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++) {
        scanf("%d %d %d %d",&a[i].no,&a[i].gold,&a[i].silver,&a[i].bronze);
    }
    sort(a,a+N,[](country a, country b){
        if(a.gold!=b.gold) return a.gold>b.gold; 
        else if(a.silver!=b.silver) return a.silver>b.silver;
        else if(a.bronze!=b.bronze) return a.bronze>b.bronze;
        return false;
    });
    a[0].rank = 1;
    for(int i=1;i<N;i++) {
        if(a[i].gold==a[i-1].gold && a[i].silver==a[i-1].silver && a[i].bronze==a[i-1].bronze) {
            a[i].rank = a[i-1].rank;
        }
        else {
            a[i].rank = i+1;
        }
        if(a[i].no==K) {
            printf("%d",a[i].rank);
            return 0;
        }
    }
    for(int i=0;i<N;i++) {
        if(a[i].no==K) {
            printf("%d",a[i].rank);
            break;
        }
    }
    return 0;
}

