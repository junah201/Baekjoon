// 17298 오큰수
// https://www.acmicpc.net/source/39603842

#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s, ans;
int N, map[1000002];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &map[i]);
    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= map[i])
            s.pop();
        if (s.empty())
            ans.push(-1);
        else
            ans.push(s.top());
        s.push(map[i]);
    }
    while (!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
    return 0;
}