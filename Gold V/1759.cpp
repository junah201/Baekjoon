// 1759  암호 만들기

#include <stdio.h>
#include <algorithm>

using namespace std;

int L, C;
char str[20];
int check[20];
char result[20];

bool is_gather(char x)
{
    if (x == 'a' || x == 'e')
        return true;
    else if (x == 'i' || x == 'o')
        return true;
    else if (x == 'u')
        return true;
    return false;
}

bool in_gather(char x[])
{
    for (int i = 0; i < L; i++)
    {
        if (is_gather(x[i]))
            return true;
    }
    return false;
}

bool is_consonant(char x)
{
    if (x == 'a' || x == 'e')
        return false;
    else if (x == 'i' || x == 'o')
        return false;
    else if (x == 'u')
        return false;
    return true;
}

int count_consonant(char x[])
{
    int cnt = 0;
    for (int i = 0; i < L; i++)
    {
        if (is_consonant(x[i]))
            cnt++;
    }
    return cnt;
}

void f(int idx, int start)
{
    if (idx == L)
    {
        if (in_gather(result) && count_consonant(result) >= 2)
        {
            for (int i = 0; i < L; i++)
                printf("%c", result[i]);
            printf("\n");
        }
        return;
    }
    for (int i = start; i < C; i++)
    {
        if (!check[i])
        {
            check[i] = 1;
            result[idx] = str[i];
            f(idx + 1, i + 1);
            check[i] = 0;
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++)
        scanf(" %c", &str[i]);
    sort(str, str + C, [](char a, char b)
         { return a < b; });
    f(0, 0);
    return 0;
}