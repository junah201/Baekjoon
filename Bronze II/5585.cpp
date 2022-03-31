// 5585 거스름돈

#include <bits/stdc++.h>
using namespace std;

int N, ans;
deque<int> coin = {500, 100, 50, 10, 5, 1};

int main()
{
    scanf("%d", &N);
    N = 1000 - N;
    while (N)
    {
        ans += N / coin.front();
        N %= coin.front();
        coin.pop_front();
    }
    printf("%d", ans);
    return 0;
}