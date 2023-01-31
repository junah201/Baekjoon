/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int A, B, K, total;

int p[200009];

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void marge(int a, int b)
{
    int tmp_a = fin(a);
    int tmp_b = fin(b);

    a = min(tmp_a, tmp_b);
    b = max(tmp_a, tmp_b);

    if (a == b)
        return;

    p[a] = b;
}

ll bfs()
{
    queue<tuple<int, int, ll>> q;
    q.emplace(A, B, 1);

    while (!q.empty())
    {
        auto [zero, one, idx] = q.front();
        q.pop();

        int tmp_start = zero + K - 2 * max(0, K - one);
        int tmp_end = zero + K - 2 * min(K, zero);

        int start = min(tmp_start, tmp_end);
        int end = max(tmp_start, tmp_end);
        start = max(0, start);

        if (end > total)
        {
            if (end % 2 == total % 2)
                end = total;
            else
                end = total - 1;
        }

        // printf("%d   ~    %d\n", start, end);

        for (int new_zero = start; new_zero <= end; new_zero += 2)
        {
            if (new_zero == 0)
                return idx;

            new_zero = fin(new_zero);

            if (new_zero > end)
                break;

            int new_one = total - new_zero;

            if (new_zero == 0)
                return idx;

            q.emplace(new_zero, new_one, idx + 1);
            marge(new_zero, end + 2);
        }
    }

    return -1;
}

int main()
{
    scanf("%d %d %d", &A, &B, &K);
    // A가 홀수이고, K가 짝수이면 무조건 불가능
    if (A % 2 == 1 && K == 0)
    {
        printf("-1");
        return 0;
    }
    // A가 0이면 무조건 가능
    if (A == 0)
    {
        printf("0");
        return 0;
    }
    // K가 0이면 무조건 불가능
    if (K == 0)
    {
        printf("-1");
        return 0;
    }
    // A가 K로 나누어떨어지면 묷이 정답
    if (A % K == 0)
    {
        printf("%d", A / K);
        return 0;
    }
    // 전체 개수보다 K가 크면 무조건 불가능
    if (A + B <= K)
    {
        printf("-1");
        return 0;
    }

    for (int i = 0; i <= A + B + 9; i++)
        p[i] = i;

    total = A + B;

    printf("%lld", bfs());
    return 0;
}