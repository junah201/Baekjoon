/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF INT_MAX

int N, tmp;
priority_queue<int, vector<int>, greater<>> min_values;

int get(int a, int b)
{
    int tmp = b;
    int cnt = 1;
    while(tmp /10 != 0) {
        tmp /= 10;
        cnt++;
    }

    return a * (int)pow(10, cnt) + b;
}

signed main()
{
    scanf("%lld", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &tmp);
        min_values.emplace(tmp);
    }

    int tmp_max = min(N, (int)4);
    vector<int> A;

    for (int i = 0; i < tmp_max; i++)
    {
        A[i] = min_values.top();
        min_values.pop();
    }

    vector<int> B;

    for (int i = 0; i < tmp_max; i++)
    {
        for (int j = 0; j < tmp_max; j++)
        {
            if (i == j)
                continue;

            B.emplace_back(get(A[i], A[j]));
        }
    }

    sort(B.begin(), B.end());

    printf("%lld", B[2]);

    return 0;
}