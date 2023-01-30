/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) (v).begin(), (v).end()

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int A, B, K, total;
set<int> not_visited;
int visited[200002];

int bfs()
{
    // 0 : 1
    queue<tuple<int, int, int>> q;
    q.emplace(A, B, 1);
    not_visited.erase(A);

    while (!q.empty())
    {
        auto [zero, one, idx] = q.front();
        q.pop();

        // printf("%d\n", not_visited.size());
        // dprintf("(%d %d) %d\n", zero, one, idx);

        vector<int> to_erase;

        for (const auto &i : not_visited)
        {
            int new_zero = i;
            // new_zero - zero - K = -2 * i

            // d : one을 몇개 뒤집었는지
            int d = -1 * (new_zero - zero - K);
            // d == 2 * i

            if (d % 2 == 1)
                continue;

            d = d / 2;
            // d == i

            // 만약 이동 불가능하면
            if (d < max(0, K - one) || d > min(K, zero))
                continue;

            int new_one = one + d - (K - d);

            // 종료 조건
            if (new_zero == 0)
                return idx;

            to_erase.emplace_back(new_zero);
            q.emplace(new_zero, total - new_zero, idx + 1);
        }

        // 지워주기
        for (auto i : to_erase)
        {
            not_visited.erase(i);
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
    // A가 K로 나누어지면 묷이 정답
    if (A % K == 0)
    {
        printf("%d", A / K);
        return 0;
    }
    // not_visited 에 값 넣기
    for (int i = 0; i <= A + B; i++)
    {
        not_visited.insert(i);
    }

    total = A + B;

    printf("%d", bfs());
    return 0;
}

/*
0이 A개
1이 B개

뒤집은 횟수 N

N보다 작은 홀수 A개와 N보다 작은 짝수 B개의 합이 K * N이 되면 가능
각 N에 대해서 O(1) 안에 가능한지 판별한다고 할 때



*/