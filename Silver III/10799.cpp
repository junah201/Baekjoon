// 10799 쇠막대기
// https://www.acmicpc.net/source/39603456

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

stack<int> s;
char string[100002];
int len, ans;

int main()
{
    scanf("%s", string);
    len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        if (string[i] == '(')
            s.push(1);
        else
        {
            s.pop();
            if (string[i - 1] == '(')
                ans += s.size();
            else
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}