#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int n, t = 1;
long ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= t)
        {
            ans += arr[i] - t;
            t++;
        }
    }
    printf("%lld", ans);
    return 0;
}