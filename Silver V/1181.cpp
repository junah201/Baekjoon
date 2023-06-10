/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int N;
    scanf("%lld", &N);
    char A[20001][51];
    for (int i = 0; i < N; i++)
        scanf("%s", A[i]);

    sort(A, A + N, [](const char *a, const char *b)
         {
    if (strlen(a) == strlen(b))
        return strcmp(a, b) < 0;
    else
        return strlen(a) <strlen(b); });

    for (int i = 0; i < N; i++)
    {
        if (strcmp(A[i], A[i + 1]) == 0)
            printf("%s\n", A[i]);
    }

    return 0;
}