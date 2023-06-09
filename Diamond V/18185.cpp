/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LONG_LONG_MAX

int N, ans;
vector<int> A;

void print_A()
{
    for (int i = 1; i <= N; i++)
        printf("%lld ", A[i]);
    printf("\n");
}

signed main()
{
    scanf("%lld", &N);
    A.resize(N + 1);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &A[i]);

    // 지울 수 있는 3을 모두 지우고
    while (true)
    {
        // print_A();
        int last_idx = 0;

        for (int i = 1; i <= N - 2; i++)
        {
            if (A[i] && A[i + 1] && A[i + 2])
            {
                last_idx = i;
                int tmp_sum = A[i] + A[i + 1] + A[i + 2];

                // 한칸 뒤의 값이 더 유리하면
                if (i + 3 <= N && A[i + 1] + A[i + 2] + A[i + 3] <= tmp_sum)
                    continue;

                // 3개 다 1이면 바로 break
                if (A[i] == 1 || A[i + 2] == 1)
                    break;
            }
        }

        if (last_idx == 0)
            break;

        A[last_idx]--;
        A[last_idx + 1]--;
        A[last_idx + 2]--;
        ans += 7;
    }

    // 지울 수 있는 2를 모두 지우고
    while (true)
    {
        // print_A();
        int last_idx = 0;

        for (int i = 1; i <= N - 1; i++)
        {
            if (A[i] && A[i + 1])
            {
                last_idx = i;
                int tmp_sum = A[i] + A[i + 1];

                // 한칸 뒤의 값이 더 유리하면
                if (i + 2 <= N && A[i + 1] + A[i + 2] <= tmp_sum)
                    continue;

                if (A[i] == 1 || A[i + 1] == 1)
                    break;
            }
        }

        if (last_idx == 0)
            break;

        A[last_idx]--;
        A[last_idx + 1]--;
        ans += 5;
    }

    // 나머지 1을 지우기

    for (int i = 1; i <= N; i++)
    {
        // print_A();
        ans += 3 * A[i];
        A[i] = 0;
    }

    printf("%lld", ans);

    return 0;
}