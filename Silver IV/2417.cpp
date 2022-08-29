#include <bits/stdc++.h>
using namespace std;

long long N, M;

long long bs()
{
    long long low = 0;
    long long high = sqrt(N);
    long long mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid > N)
            high = mid - 1;
        else if (mid * mid < N)
            low = mid + 1;
        else
            return low;
    }
    return low;
}

int main()
{
    scanf("%lld", &N);
    printf("%lld", bs());
    return 0;
}