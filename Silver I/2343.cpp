/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N, M, max_value = -INF;
vector<int> videos;

int get_cnt(int num)
{
    int cnt = 0;
    int now = 0;

    for (int i = 0; i < N; i++)
    {
        if (now + videos[i] <= num)
        {
            now += videos[i];
        }
        else
        {
            cnt++;
            now = videos[i];
        }
    }

    if (now)
        cnt++;

    return cnt;
}

int bs()
{
    int low = max_value;
    int high = INF - low - 100;
    int mid, ans = INF, cnt;

    while (low <= high)
    {
        mid = (low + high) / 2;

        cnt = get_cnt(mid);

        if (cnt <= M)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else if (cnt > M)
        {
            low = mid + 1;
        }
    }

    return ans;
}

signed main()
{
    scanf("%lld %lld", &N, &M);
    videos.resize(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &videos[i]);
        max_value = max(videos[i], max_value);
    }

    printf("%lld", bs());

    return 0;
}