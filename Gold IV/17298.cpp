#include <stdio.h>

int N, map[1000002];

int oks(int idx)
{
    for (int i = idx + 1; i < N; i++)
    {
        if (map[i] > map[idx])
            return map[i];
    }
    return -1;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &map[i]);
    for (int i = 0; i < N; i++)
        printf("%d ", oks(i));
    return 0;
}