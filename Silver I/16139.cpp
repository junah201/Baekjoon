/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

char S[200002];
int DP[200002][30];
int N, len;

int main()
{
    scanf("%s", S);
    len = strlen(S);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i != 0)
                DP[i][j] = DP[i - 1][j];
        }
        DP[i][S[i] - 'a']++;
    }

    scanf("%d", &N);
    while (N--)
    {
        char alpha;
        int a, b;

        scanf(" %c %d %d", &alpha, &a, &b);
        if (a == 0)
            printf("%d\n", DP[b][alpha - 'a']);
        else
            printf("%d\n", DP[b][alpha - 'a'] - DP[a - 1][alpha - 'a']);
    }

    return 0;
}