/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N, ans = -INT_MAX;
char str[20];

int cul(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    return 0;
}

void dfs(int idx, int value)
{
    if (idx >= N)
    {
        ans = max(ans, value);
        return;
    }

    char op = (idx >= 1) ? str[idx - 1] : '+';
    int tmp = cul(value, str[idx] - '0', op);

    dfs(idx + 2, tmp);

    if (idx < N - 2)
    {
        int tmp = cul(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
        int tmp2 = cul(value, tmp, op);

        dfs(idx + 4, tmp2);
    }
}

int main()
{
    scanf("%d", &N);
    scanf(" %s", str);

    dfs(0, 0);

    printf("%d", ans);

    return 0;
}