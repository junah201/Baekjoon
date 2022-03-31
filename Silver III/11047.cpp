// 11047 동전 0

#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
deque<int> coin;

int main()
{
    scanf("%d %d", &N, &K);
    coin.resize(N);
    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        coin.push_front(tmp);
    }

    while (K)
    {
        ans += K / coin.front();
        K %= coin.front();
        coin.pop_front();
    }
    printf("%d", ans);
    return 0;
}