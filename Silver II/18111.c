// 18111 마인크래프트
// https://www.acmicpc.net/source/39606104

#include <stdio.h>

int N, M, B;
int ans1 = 987654321, ans2;
int map[502][502];
int check[275];

int dig(int num, int block)
{
    int time = 0;
    // 땅 파기
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (map[y][x] > num)
            {
                time += 2 * (map[y][x] - num);
                block += map[y][x] - num;
            }

    // 땅 매꾸기
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
        {
            if (map[y][x] < num)
            {
                time += num - map[y][x];
                block -= num - map[y][x];
            }
            if (block < 0)
                return -1;
        }

    return time;
}

int main()
{
    scanf("%d %d %d", &N, &M, &B);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            scanf("%d", &map[y][x]);

    for (int high = 0; high <= 256; high++)
    {
        int result = dig(high, B);
        // printf("%d %d %d %d\n", x, y, map[y][x], check[map[y][x]]);
        if (result == -1)
            continue;
        if (result < ans1 || (result == ans1 && high > ans2))
            ans1 = result, ans2 = high;
    }

    printf("%d %d", ans1, ans2);
    return 0;
}