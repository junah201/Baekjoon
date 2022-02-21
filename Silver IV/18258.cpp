// 18258  큐 2
// https://www.acmicpc.net/source/39423083

#include <stdio.h>

int T, X;
// start : 뺄때 삭제할 위치 |  end : 새로 추가할 위치
int start = 0, end = 0;
int queue[2000002];
char cmd[10];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'p' && cmd[1] == 'u')
        {
            scanf("%d", &X);
            queue[end++] = X;
        }
        else if (cmd[0] == 'p' && cmd[1] == 'o')
        {
            if (start == end)
                printf("-1\n");
            else
            {
                printf("%d\n", queue[start]);
                start++;
            }
        }
        else if (cmd[0] == 's')
        {
            printf("%d\n", end - start);
        }
        else if (cmd[0] == 'e')
        {
            if (start == end)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (cmd[0] == 'f')
        {
            if (start == end)
                printf("-1\n");
            else
                printf("%d\n", queue[start]);
        }
        else if (cmd[0] == 'b')
        {
            if (start == end)
                printf("-1\n");
            else
                printf("%d\n", queue[end - 1]);
        }
    }
    return 0;
}