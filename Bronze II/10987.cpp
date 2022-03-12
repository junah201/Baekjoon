// 10987  모음의 개수
// https://www.acmicpc.net/source/40287575

#include <bits/stdc++.h>
using namespace std;

char str[102];
int len, cnt;

int main()
{
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}