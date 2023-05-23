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
stack<pair<int, int>> s;

signed main()
{
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        int now;
        scanf("%lld", &now);

        while (!s.empty() && s.top().first > now)
        {
            auto [prev_value, prev_idx] = s.top();
        }

        s.emplace(now, i);
    }
    return 0;
}

/*
생각해보기

한변의 길이의 리스트를 A[i]라고 할때

A[i] 다음에 있는 A[i+1]의 길이가 A[i]의 3배 이상이면 A[i]는 보이지 않는다


*/