//5430  AC

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

deque <int> d;
int T,cmd_len,input_len,start;
char cmd[100001],temp[300];

int get() {
    //초기화
    while(!d.empty()) d.pop_back();
    memset(cmd, 0, 100001);
    memset(temp, 0, 300);
    scanf("%s",cmd);
    cmd_len = strlen(cmd);
    start = 1;
    scanf("%d",&input_len);
    scanf("%s",&temp);
    for(int i=1;i<input_len*2;i+=2) {
        d.push_back(temp[i]-'0');
    }
    for(int i=0;i<cmd_len;i++) {
        if(cmd[i]=='R') start = !start;
        else if(d.size()==0) {
            printf("error\n");
            return -1;
        }
        else if(start==1) {
            d.pop_front();
        } 
        else if(start==0) {
            d.pop_back();
        }
    }
    printf("[");
    if(start==1) {
        if(!d.empty()) {
            printf("%d",d.front());
            d.pop_front();
        }
        while(!d.empty()) {
            printf(",%d",d.front());
            d.pop_front();
        }
    }
    else {
        if(!d.empty()) {
            printf("%d",d.back());
            d.pop_back();
        }
        while(!d.empty()) {
            printf(",%d",d.back());
            d.pop_back();
        }
    }
    
    printf("]\n");
    return 0;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        get();
    }
    return 0;
}