/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M;
vector<int> people;

int get_cnt(int num)
{
    int res = N;
    for (int i : people)
    {
        res += num / i;
        if (res > M + N)
            return res;
    }
    return res;
}

int bs()
{
    int low = 0;
    int high = 60000000001LL;
    int mid, ans = INF, cnt;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cnt = get_cnt(mid);

        if (cnt >= M)
        {
            high = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

signed main()
{
    scanf("%lld %lld", &M, &N);

    if (M <= N)
    {
        printf("%lld", M);
        return 0;
    }

    people.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &people[i]);
    }

    int res = bs();

    int cnt = N;
    for (int i = 0; i < N; i++)
    {
        cnt += ((res - 1) / people[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (res % people[i] == 0)
            cnt++;
        if (cnt == M)
        {
            printf("%lld", i + 1);
            return 0;
        }
    }
    printf("%lld", -1LL);

    return 0;
}
