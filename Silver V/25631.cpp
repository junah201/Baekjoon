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

int N;
vector<int> A;
vector<char> check;
int check_cnt, ans;

signed main()
{
    scanf("%lld", &N);
    A.resize(N);
    check.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    sort(A.begin(), A.end(), greater<int>());
    int last_value = -1;

    while (check_cnt != N)
    {
        last_value = -1;
        for (int i = 0; i < N; i++)
        {
            if (check[i])
                continue;

            if (last_value == -1)
            {
                check[i] = true;
                last_value = A[i];
                check_cnt += 1;
                ans++;
            }
            else if (A[i] < last_value)
            {
                check[i] = true;
                last_value = A[i];
                check_cnt += 1;
            }
        }
    }

    printf("%lld", ans);

    return 0;
}
