#include <bits/stdc++.h>
using namespace std;

long long N, M, 합계, 요청최대값;
vector<long long> 예산요청;

long long 예산합계(long long 기준값)
{
    long long 결과값 = 0;
    for (auto i : 예산요청)
    {
        결과값 += min(i, 기준값);
    }
    return 결과값;
}

long long bs()
{
    long long low = 1;
    long long high = 요청최대값;
    long long mid;
    long long 합계;
    while (low < high)
    {
        mid = (low + high) / 2;
        합계 = 예산합계(mid);

        if (합계 > M)
            high = mid - 1;
        else if (합계 == M)
            return mid;
        else
            low = mid + 1;
    }
    if (예산합계(low) > M)
        return low - 1;
    return low;
}

int main()
{
    scanf("%lld", &N);
    for (long long i = 0, tmp; i < N; i++)
    {
        scanf("%lld", &tmp);
        합계 += tmp;
        예산요청.push_back(tmp);
        요청최대값 = max(요청최대값, tmp);
    }
    scanf("%lld", &M);
    if (합계 <= M)
    {
        printf("%lld", 요청최대값);
        return 0;
    }

    printf("%lld", bs());
    return 0;
}