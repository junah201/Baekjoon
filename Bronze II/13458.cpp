/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, A[1000002], B, C;
ll ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    for (int i = 0; i < N; i++)
    {
        ans += 1;
        A[i] -= B;

        while (A[i] > 0)
        {
            if (A[i] < C)
            {
                ans += 1;
                break;
            }

            if (A[i] % C != 0)
            {
                ans += 1;
            }

            ans += A[i] / C;
            break;
        }
    }

    printf("%lld", ans);

    return 0;
}