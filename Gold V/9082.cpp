#include <bits/stdc++.h>
using namespace std;

int T, N, is_end;
vector<int> inp_count;
vector<char> inp_mine;

bool is_mine(int idx)
{
    return (inp_mine[idx] == '*' || inp_mine[idx] == '&');
}

int get_mine_count(int idx)
{
    if (N == 1)
        return is_mine(idx);
    if (idx == 0)
        return is_mine(idx) + is_mine(idx + 1);
    if (idx == N - 1)
        return is_mine(idx - 1) + is_mine(idx);
    return is_mine(idx - 1) + is_mine(idx) + is_mine(idx + 1);
}

void dfs(int idx)
{
    if (idx > 7)
        return;

    if (is_end)
        return;

    printf("[%d] %d %d\n", idx, N, idx == N);
    for (auto i : inp_mine)
    {
        printf("%c", i);
    }
    printf("\n");

    if (idx == N)
    {
        printf("endend\n");
        is_end = true;
        return;
    }

    // 아래 칸이 지뢰 칸이면 스킵
    if (inp_mine[idx] == '*')
    {
        printf("s\n");
        dfs(idx + 1);
        return;
    }

    // 예외값 : idx == 0
    if (idx == 0)
    {
        printf("01\n");
        dfs(idx + 1);
        if (inp_count[idx] != 0)
        {
            printf("02\n");
            inp_mine[idx] = '&';
            dfs(idx + 1);
        }
        return;
    }

    printf("== %d %d %d ==\n\n", get_mine_count(idx - 1), inp_count[idx - 1], get_mine_count(idx - 1) == inp_count[idx - 1] - 1);

    // 전칸 때문에 무조건 이 칸이 차야하는 상황
    if (get_mine_count(idx - 1) == inp_count[idx - 1] - 1)
    {
        printf("only\n");
        inp_mine[idx] = '&';
        dfs(idx + 1);
        return;
    }

    // 전칸 때문에 이 칸이 무조건 비어야하는 상황
    if (get_mine_count(idx - 1) == inp_count[idx - 1])
    {
        printf("only e\n");
        inp_mine[idx] = '&';
        dfs(idx + 1);
        return;
    }

    // tmp : 전칸이 차 있는지
    int tmp = 0;
    if (is_mine(idx - 1))
        tmp += 1;

    // 그냥 보내고
    dfs(idx + 1);

    if (tmp < inp_count[idx])
    {
        printf("t\n");

        // 지뢰로 바꿔서 보내고
        inp_mine[idx] = '&';
        dfs(idx + 1);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);

        inp_count.erase(inp_count.begin(), inp_count.end());
        inp_mine.erase(inp_mine.begin(), inp_mine.end());
        is_end = false;

        for (int i = 0, tmp; i < N; i++)
        {
            scanf("%1d", &tmp);
            inp_count.emplace_back(tmp);
        }
        for (int i = 0; i < N; i++)
        {
            char tmp;
            scanf(" %1c", &tmp);
            inp_mine.emplace_back(tmp);
        }

        dfs(0);

        int ans = 0;
        for (auto i : inp_mine)
        {
            if (i == '*' || i == '&')
                ans++;
        }
        printf("%d\n", ans);
        return 0;
    }
}

/*
11122
####*
#&#&*
*/