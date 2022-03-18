#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> v;
vector<char> c;

queue<pair<int, int>> result;
bool check;

bool is_complete()
{
    int tmp;
    for (int i = 1; i <= 4 * N; i++)
        if (v[i] != 'X')
        {
            tmp = i;
            break;
        }
    for (int i = 0; i < N; i++)
        if (v[i + tmp] != 'A')
            return false;
    for (int i = 0; i < N; i++)
        if (v[i + N + tmp] != 'B')
            return false;
    return true;
}

void f(int from, int to, int cnt)
{
    if (cnt == N)
    {
        if (is_complete())
            check = true;
        return;
    }

    result.emplace(from, to);
    // 완성 되었는지 확인

    v[to] = v[from];
    v[to + 1] = v[from + 1];
    v[from] = 'X';
    v[from + 1] = 'X';

    // 격자 출력
    for (int i = 1; i <= 4 * N; i++)
    {
        if (v[i] == 'X')
            printf("■");
        else
            printf("%c", v[i]);
    }
    printf("\n");

    int result = 987654321;

    if (result == 987654321)
        return;

    f(result, from, cnt + 1);
}

int main()
{
    scanf("%d", &N);
    v.resize(4 * N + 1 + 1, 'X');
    c.resize(4 * N + 1 + 1, 0);
    for (int i = 1; i <= 2 * N; i++)
    {
        v[i + 2 * N] = 'A' + i % 2;
    }
    for ()
        return 0;
}