/* Code By [ junah ]
GitHub : [ junah201 ] */

#include <bits/stdc++.h>
using namespace std;

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    printf(__format);
#endif
}

int T, N, is_end, ans;
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
    // TODO : remove
    if (is_end)
        return;

    dprintf("\n[%d]\n", idx);
    for (auto i : inp_count)
    {
        dprintf("%d", i);
    }
    dprintf("\n");
    for (auto i : inp_mine)
    {
        dprintf("%c", i);
    }
    dprintf("\n");

    if (idx == N)
    {
        if (get_mine_count(idx - 1) != inp_count[idx - 1])
        {
            dprintf("[%d] 끝까지 왔지만 불가능\n", idx);
            return;
        }
        ans = 0;
        for (auto i : inp_mine)
        {
            if (i == '*' || i == '&')
                ans++;
        }
        dprintf("[%d] 끝 !!\n", idx);
        is_end = true;
        return;
    }

    // 아래 칸이 지뢰 칸이면 스킵
    if (inp_mine[idx] == '*')
    {
        dprintf("[%d] 아래칸이 이미 지뢰라서 스킵\n", idx);
        dfs(idx + 1);
        return;
    }

    // 예외값 : idx == 0
    if (idx == 0)
    {
        if (inp_count[idx] == 2)
        {
            dprintf("[%d] 예외값 2 채우고\n", idx);
            inp_mine[idx] = '*';
            inp_mine[idx + 1] = '*';
            dfs(idx + 1);
            return;
        }

        dprintf("[%d] 예외값 0 비우고\n", idx);
        dfs(idx + 1);
        if (inp_count[idx] != 0)
        {
            dprintf("[%d] 예외값 0 채우고\n", idx);
            inp_mine[idx] = '&';
            dfs(idx + 1);
            inp_mine[idx] = '#';
        }
        return;
    }

    // 전칸 때문에 무조건 이 칸이 차야하는 상황
    if (get_mine_count(idx - 1) == inp_count[idx - 1] - 1)
    {
        dprintf("[%d] 전칸때문에 무조건 차야함\n", idx);
        inp_mine[idx] = '&';
        dfs(idx + 1);
        inp_mine[idx] = '#';
        return;
    }

    // 전칸 때문에 이 칸이 무조건 비어야하는 상황
    if (get_mine_count(idx - 1) == inp_count[idx - 1])
    {
        dprintf("[%d] 전칸 때문에 무조건 비어야함\n", idx);
        dfs(idx + 1);
        return;
    }

    // tmp : 전칸이 차 있는지
    int tmp = 0;
    if (is_mine(idx - 1))
        tmp += 1;

    // 그냥 보내고
    dprintf("[%d] 그냥 보내고\n", idx);
    dfs(idx + 1);

    if (tmp < inp_count[idx])
    {
        dprintf("[%d] 채워서 보내고\n", idx);
        // 지뢰로 바꿔서 보내고
        inp_mine[idx] = '&';
        dfs(idx + 1);
        inp_mine[idx] = '#';
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
        printf("%d\n", ans);
    }
    return 0;
}

/*
11122
####*
#&#&*
11222

23321
#####
&&&&#

11122
####*
&##&*
*/