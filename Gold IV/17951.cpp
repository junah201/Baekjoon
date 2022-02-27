// 17951 흩날리는 시험지 속에서 내 평점이 느껴진거야
// https://www.acmicpc.net/source/39595420

#include <stdio.h>

int N, K;
int map[100002];

int bs()
{
    int ans = -1;
    int low = 0, high = 20 * N, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            sum += map[i];
            if (sum >= mid)
            {
                sum = 0;
                cnt++;
            }
        }

        if (cnt >= K)
        {
            if (mid > ans)
                ans = mid;
            if (low == mid)
                low = mid + 1;
            else
                low = mid;
        }
        else if (cnt < K)
            high = mid - 1;
    }
    return ans;
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", &map[i]);
    printf("%d", bs());
    return 0;
}