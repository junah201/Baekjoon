// 1475 방 번호
// https://www.acmicpc.net/source/40674370

#include <bits/stdc++.h>
using namespace std;

char input[10];
int len, cnt;
int number[10];

void add()
{
    for (int i = 0; i <= 9; i++)
        number[i]++;

    number[6]++;
    number[9]++;
    cnt++;
}

int main()
{
    scanf("%s", input);
    len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        if (input[i] == '6' || input[i] == '9')
        {
            if (number[input[i] - '0'] <= 0)
                add();

            number[6]--;
            number[9]--;
        }
        else
        {
            if (number[input[i] - '0'] <= 0)
                add();
            number[input[i] - '0']--;
        }
    }
    printf("%d", cnt);
    return 0;
}

rlawnsdk7$