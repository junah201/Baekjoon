/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, len, tmp, ans;
char S[52];
stack<int> num;

int main()
{
    scanf("%s", S);
    len = strlen(S);

    bool is_num = true;
    bool is_minus = false;
    for (int i = 0; i < len; i++)
    {

        if (S[i] == '+' || S[i] == '-')
        {
            if (is_minus)
                num.emplace(-tmp);
            else
                num.emplace(tmp);
            if (S[i] == '-')
                is_minus = true;
            tmp = 0;
        }
        else
            tmp = tmp * 10 + S[i] - '0';
    }
    if (is_minus)
        num.emplace(-tmp);
    else
        num.emplace(tmp);

    while (!num.empty())
    {
        ans += num.top();
        num.pop();
    }

    printf("%d", ans);

    return 0;
}