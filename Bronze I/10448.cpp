/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

int N;
vector<int> tri;

void solve(int num)
{
    for (int i = 0; i < tri.size(); i++)
    {
        for (int j = 0; j < tri.size(); j++)
        {
            for (int k = 0; k < tri.size(); k++)
            {
                if (tri[i] + tri[j] + tri[k] == num)
                {
                    printf("1\n");
                    return;
                }
            }
        }
    }
    printf("0\n");
}

signed main()
{
    scanf("%lld", &N);
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);

    int max_value = *max_element(all(A));
    int prev = 0;
    for (int i = 1; prev <= max_value; i++)
    {
        tri.emplace_back(prev + i);
        prev = prev + i;
    }

    for (int i : A)
    {
        solve(i);
    }

    return 0;
}
