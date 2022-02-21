//18766  카드 바꿔치기

#include <stdio.h>
#include <algorithm>

using namespace std;

int T,N,A[201],B[201];
char temp1;
int temp2;

struct card {
    int no;
    char color;
}deck1[201],deck2[201];

// struct card deck1[201];
// struct card deck2[201];

int check() {
    for(int i=0;i<N;i++) {
        if(deck1[i].color != deck2[i].color || deck1[i].no != deck2[i].no) return 0;
    }
    return 1;
}

int main() {
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        scanf("%d",&N);
        for(int j=0;j<N;j++) {
            scanf(" %c%d",&deck1[j].color,&deck1[j].no);
        }
        for(int j=0;j<N;j++) {
            scanf(" %c%d",&deck2[j].color,&deck2[j].no);
        }
        sort(deck1,deck1+N,[](card a,card b){
            if(a.color==b.color) return a.no<b.no;
            else return a.color<b.color;
        });
        sort(deck2,deck2+N,[](card a,card b){
            if(a.color==b.color) return a.no<b.no;
            else return a.color<b.color;
        });
        if(check()) printf("NOT CHEATER\n");
        else printf("CHEATER\n");
    }
    return 0;
}