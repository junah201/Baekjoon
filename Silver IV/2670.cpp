/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

int N;
double ans = -1e9, value;
double arr[10002];

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%lf", &arr[i]);

    ans = arr[0];
    value = arr[0];

    for (int i = 1; i < N; i++)
    {
        value = max(value * arr[i], arr[i]);
        ans = max(ans, value);
    }

    printf("%.3lf", ans);

    return 0;
}