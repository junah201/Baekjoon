/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int str1_len, str2_len, ans;
char str1[1002], str2[1002];

vector<vector<int>> alpha(30);
vector<pair<int, int>> A;

signed main()
{
    scanf("%s", str1);
    scanf("%s", str2);

    str1_len = strlen(str1);
    str2_len = strlen(str2);

    vector<vector<int>> DP(str1_len + 2, vector<int>(str2_len + 2, 0));

    for (int i = 1; i <= str1_len; i++)
    {
        for (int j = 1; j <= str2_len; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
        }
    }

    for (int i = 0; i <= str1_len; i++)
    {
        for (int j = 0; j <= str2_len; j++)
        {
            dprintf("%lld ", DP[i][j]);
        }
        dprintf("\n");
    }

    printf("%lld", DP[str1_len][str2_len]);

    return 0;
}