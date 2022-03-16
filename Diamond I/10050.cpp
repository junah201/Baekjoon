#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> v;

bool is_complete()
{
    int tmp;
    for (int i = 1; i <= 4 * N; i++)
    {
        if (v[i] != 'X')
        {
            tmp = i;
            break;
        }
    }
    for (int i = 0; i < N; i++)
        if (v[i + tmp] != 'A')
            return false;
    for (int i = 0; i < N; i++)
        if (v[i + N + tmp] != 'B')
            return false;
    return true;
}

void f(int from, int to, bool way)
{
    // 완성 되었는지 확인
    if (is_complete())
        return;

    printf("%d to %d\n", from - 2 * N, to - 2 * N);
    v[to] = v[from];
    v[to + 1] = v[from + 1];
    v[from] = 'X';
    v[from + 1] = 'X';

    for (int i = 1; i <= 4 * N; i++)
    {
        if (v[i] == 'X')
            printf("■");
        else
            printf("%c", v[i]);
    }
    printf("\n");

    char front = v[from - 1];
    char back = v[from + 2];

    int result = 987654321;
    // 앞에서 부터
    if (!way)
    {
        for (int i = 1; i < 4 * N; i++)
        {
            if (i == from || i == from + 1 || i == from + 2)
                continue;
            if ((v[i] == front || front == 'X') && (v[i + 1] == back || back == 'X') && v[i] != v[i - 1])
            {
                result = i;
            }
        }
    }
    // 뒤에서 부터
    else
    {
        for (int i = 4 * N - 1; i >= 1; i--)
        {
            if (i == from || i == from + 1 || i == from + 2)
                continue;
            if ((v[i] == front || front == 'X') && (v[i + 1] == back || back == 'X') && v[i] != v[i - 1])
            {
                result = i;
            }
        }
    }
    // printf("[%c] [%c]\n", v[result], v[result - 1]);

    /*
        if (result == 987654321)
            printf("9999\n");
    */
    if (result == 987654321)
    {
        if (!way)
        {
            for (int i = 1; i < 4 * N; i++)
            {
                if (i == from || i == from + 1 || i == from + 2)
                    continue;
                if ((v[i] == front || front == 'X') && (v[i + 1] == back || back == 'X'))
                {
                    result = i;
                }
            }
        }
        // 뒤에서 부터
        else
        {
            for (int i = 4 * N - 1; i >= 1; i--)
            {
                if (i == from || i == from + 1 || i == from + 2)
                    continue;
                if ((v[i] == front || front == 'X') && (v[i + 1] == back || back == 'X'))
                {
                    result = i;
                }
            }
        }
    }

    if (result == 987654321)
    {
        if (!way)
        {
            for (int i = 1; i < 4 * N; i++)
            {
                if (i == from || i == from + 1 || i == from + 2)
                    continue;
                if ((v[i + 1] == back || back == 'X'))
                {
                    result = i;
                }
            }
        }
        // 뒤에서 부터
        else
        {
            for (int i = 4 * N - 1; i >= 1; i--)
            {
                if (i == from || i == from + 1 || i == from + 2)
                    continue;
                if ((v[i + 1] == back || back == 'X'))
                {
                    result = i;
                }
            }
        }
    }

    if (result == 987654321)
        return;
    f(result, from, !way);
}

int main()
{
    scanf("%d", &N);
    v.resize(4 * N + 1 + 1, 'X');
    for (int i = 1; i <= 2 * N; i++)
    {
        v[i + 2 * N] = 'A' + i % 2;
    }
    f(4 * N - 2, 2 * N - 1, true);
    return 0;
}