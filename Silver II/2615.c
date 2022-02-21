//2615  오목

#include <stdio.h>

int map[20][20];
int add[4][2] = {
    {1,0}, //0 : →
    {0,1}, //1 : ↓
    {1,1}, //2 : ↘
    {1,-1} //3 : ↗
};
int win;

int dfs(int x, int y, int stack, int way, int init_x,int init_y) {
    if(x==0 || x>19 || y==0 || y>19) return 0;
    if(map[y][x]==0) return 0;
    if(win != 0) return 0;
    if(stack==5) {
        if(map[y][x] == map[y+add[way][1]][x+add[way][0]]) return 0;
        if(map[init_y][init_x] == map[init_y-add[way][1]][init_x-add[way][0]]) return 0;
        printf("%d\n%d %d",map[y][x],init_y,init_x);
        win = map[y][x];
        return 0;
    }
    if(way==-1) {
        for(int i=0;i<4;i++) {
            if(map[y][x] == map[y+add[i][1]][x+add[i][0]]) 
                dfs(x+add[i][0],y+add[i][1],stack+1,i,init_x,init_y);
        }
    }
    else {
        if(map[y][x] == map[y+add[way][1]][x+add[way][0]]) 
            dfs(x+add[way][0],y+add[way][1],stack+1,way,init_x,init_y);
    }
    return 0;
}

int main() {
    for(int i=1;i<20;i++) {
        for(int j=1;j<20;j++) {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<20;i++) {
        for(int j=1;j<20;j++) {
            if(map[i][j]!=0) {
                dfs(j,i,1,-1,j,i);
            }
        }
    }
    if(win==0) printf("0");
    return 0;
}