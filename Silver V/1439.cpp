/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

char S[1000001];
int len;
int ans[2];

signed main()
{
    scanf("%s", S);
    len = strlen(S);

    ans[S[0] - '0'] += 1;
    for (int i = 1; i < len; i++)
    {
        if (S[i] != S[i - 1])
            ans[S[i] - '0']++;
    }
    printf("%lld", min(ans[0], ans[1]));

    return 0;
}