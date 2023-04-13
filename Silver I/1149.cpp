/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int N;
int DP[1002][3];
int color[3];

int main()
{
    scanf("%d", &N);
    scanf("%d %d %d", &DP[0][0], &DP[0][1], &DP[0][2]);
    for (int i = 1; i < N; i++)
    {
        scanf("%d %d %d", &color[0], &color[1], &color[2]);

        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + color[0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + color[1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + color[2];
    }

    printf("%d", min(DP[N - 1][0], min(DP[N - 1][1], DP[N - 1][2])));

    return 0;
}