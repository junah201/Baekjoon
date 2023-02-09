/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

int N, ans;
vector<int> A, DP;

int main()
{
    scanf("%d", &N);

    for (int i = 0, tmp; i < N; i++)
    {
        scanf("%d", &tmp);
        A.emplace_back(tmp);
    }
    sort(A.begin(), A.end());

    DP.emplace_back(A[0]);
    ans += DP[0];
    for (int i = 1; i < N; i++)
    {
        DP.emplace_back(DP[i - 1] + A[i]);
        ans += DP[i];
    }

    printf("%d", ans);

    return 0;
}