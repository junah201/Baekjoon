#include <bits/stdc++.h>
using namespace std;

int dx[5] = {0, 0, 1, -1, 0};
int dy[5] = {1, -1, 0, 0, 0};

int ldx[13] = {0, 0, 1, -1, 0, 1, 1, -1, -1, 0, 0, 2, -2};
int ldy[13] = {1, -1, 0, 0, 0, 1, -1, 1, -1, 2, -2, 0, 0};

int inp[10][10];
int sum, ans;
int cnt[10][10];

int cul_cnt(int x, int y)
{
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
            continue;
        result += inp[ny][nx];
    }
    return result;
}

void change(int x, int y)
{
    int tmp1 = 0, tmp2 = 0;

    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
            continue;
        inp[ny][nx] = !inp[ny][nx], tmp1++, tmp2 += inp[ny][nx];
    }
    sum += tmp2;
    sum -= (tmp1 - tmp2);

    for (int i = 0; i < 13; i++)
    {
        int nx = x + ldx[i];
        int ny = y + ldy[i];

        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10)
            continue;

        cnt[ny][nx] = cul_cnt(nx, ny);
    }
}

void debug()
{
    printf("=========\n");
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
            printf("%d", inp[y][x]);
        printf("\n");
    }
}

pair<int, int> get_xy()
{
    // 왼쪽 위
    for (int i = 1, tmp_sum; i < 9; i++)
    {
        tmp_sum = 1;
        for (int x = 0, y = i; x < 10 && y >= 0; x++, y--)
        {
            if (!inp[y][x])
            {
                tmp_sum = 0;
                break;
            }
        }
        if (tmp_sum && inp[i + 1][0] && inp[0][i + 1])
            return {i, 0};
    }

    // 왼쪽 위
    for (int i = 1, tmp_sum; i < 9; i++)
    {
        tmp_sum = 1;
        for (int x = 9 - i, y = 0; x >= 0 && y < 10; x--, y++)
        {
            if (!inp[y][x])
            {
                tmp_sum = 0;
                break;
            }
        }
        if (tmp_sum && inp[i + 1][9] && inp[9][i + 1])
            return {i, 9};
    }

    // 오른쪽 아래
    for (int i = 1, tmp_sum; i < 9; i++)
    {
        tmp_sum = 1;
        for (int x = 9, y = 9 - i; x < 10 && y < 10; x--, y++)
        {
            if (!inp[y][x])
            {
                tmp_sum = 0;
                break;
            }
        }
        if (tmp_sum && inp[i + 1][0] && inp[9][i + 1])
            return {i, 0};
    }

    // 왼쪽 아래
    for (int i = 1, tmp_sum; i < 9; i++)
    {
        tmp_sum = 1;
        for (int x = 9 - i, y = 9; x >= 0 && y >= 0; x++, y--)
        {
            if (!inp[y][x])
            {
                tmp_sum = 0;
                break;
            }
        }
        if (tmp_sum && inp[i + 1][9] && inp[0][i + 1])
            return {i, 9};
    }

    if (inp[0][1] + inp[0][2] + inp[1][0] + inp[2][0] == 4)
        return {1, 0};
    if (inp[0][7] + inp[0][8] + inp[1][9] + inp[2][9] == 4)
        return {8, 0};
    if (inp[7][0] + inp[8][0] + inp[9][1] + inp[9][2] == 4)
        return {0, 8};
    if (inp[7][9] + inp[8][9] + inp[9][8] + inp[9][7] == 4)
        return {8, 9};

    int now = 0, fill = 0;
    pair<int, int> tmp = {-1, -1};

    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
            if (cnt[y][x] == 5)
                return {x, y};
            else if (cnt[y][x] == 4 && (x == 0 || x == 9 || y == 0 || y == 9))
                return {x, y};

    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
        {
            if (cnt[y][x] == 3 && inp[y][x])
                tmp = {x, y}, now = 3, fill = inp[y][x];
            if (cnt[y][x] == 3 && !inp[y][x])
                if (tmp.first == -1)
                    tmp = {x, y}, now = 3, fill = inp[y][x];
            if (cnt[y][x] == 4 && (now != 3 && inp[y][x] > fill))
                if (inp[y][x] >= fill)
                    tmp = {x, y}, now = 4, fill = inp[y][x];
        }
    return tmp;
}

int main()
{
    // 입력
    char tmp;
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            scanf(" %c", &tmp);
            if (tmp == 'O')
            {
                inp[y][x] = 1;
                sum++;
            }
            else
                inp[y][x] = 0;
        }
    }

    // cnt 계산
    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
            cnt[y][x] = cul_cnt(x, y);

    // 수행
    while (sum)
    {
        auto tmp = get_xy();
        if (tmp == {-1, -1})
        {
            printf("%d\n", sum);
            debug();
            break;
        }
        change(tmp.first, tmp.second);
        // printf("(%d, %d) : %d\n", tmp.first, tmp.second, sum);
        // debug();
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}