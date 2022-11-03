/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, M, ans = INT_MAX;
char inp[52][52];

int check(int x, int y)
{
    int result1 = 64;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (inp[i][j] == 'B')
                    result1--;
            }
            else
            {
                if (inp[i][j] == 'W')
                    result1--;
            }
        }
    }
    int result2 = 64;
    for (int i = x; i < x + 8; i++)
    {
        for (int j = y; j < y + 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (inp[i][j] == 'W')
                    result2--;
            }
            else
            {
                if (inp[i][j] == 'B')
                    result2--;
            }
        }
    }
    return min(result1, result2);
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%s", inp[i]);

    for (int start_y = 0; start_y <= N - 8; start_y++)
    {
        for (int start_x = 0; start_x <= M - 8; start_x++)
        {
            ans = min(ans, check(start_y, start_x));
        }
    }
    printf("%d", ans);
    return 0;
}