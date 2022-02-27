#include <stdio.h>
#define abs(_x) ((_x) > 0 ? (_x) : -(_x))

int N;
long long map[100002];

long long bs()
{
    long long low = 1;
    long long high = map[N - 1];
    long long mid;
    long long mid_sum, low_sum, high_sum;
    while (low <= high)
    {
        mid = (low + high) / 2;
        mid_sum = 0;
        low_sum = 0;
        high_sum = 0;
        for (int i = 1; i < N; i++)
            mid_sum += abs(map[i] - mid * i);
        for (int i = 1; i < N; i++)
            low_sum += abs(map[i] - (mid - 1) * i);
        for (int i = 1; i < N; i++)
            high_sum += abs(map[i] - (mid + 1) * i);

        if (mid_sum < low_sum && mid_sum < high_sum)
            return mid_sum;
        else if (low_sum < high_sum)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return mid_sum;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &map[i]);
    printf("%lld", bs());
    return 0;
}