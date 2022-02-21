#include <stdio.h>
#include <stack>

using namespace std;

int n,temp,sum=0;
stack <int> s;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&temp);
        if(temp==0) s.pop();
        else s.push(temp);
    }
    while(!s.empty()) {
        sum+=s.top();
        s.pop();
    }
    printf("%d",sum);
    return 0;
}