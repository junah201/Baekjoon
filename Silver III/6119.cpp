#include <stdio.h>
#include <deque>
using namespace std;

int N;
int cow = 1;

deque<int> dq;

int main()
{
    scanf("%d", &N);
    char cmd1, cmd2;
    for (int i = 0, value; i < N; i++)
    {
        scanf(" %c %c", &cmd1, &cmd2);
        if (cmd1 == 'A' && cmd2 == 'L')
        {
            dq.push_front(cow++);
        }
        else if (cmd1 == 'A' && cmd2 == 'R')
        {
            dq.push_back(cow++);
        }
        else if (cmd1 == 'D' && cmd2 == 'L')
        {
            scanf("%d", &value);
            for (int j = 0; j < value; j++)
                dq.pop_front();
        }
        else if (cmd1 == 'D' && cmd2 == 'R')
        {
            scanf("%d", &value);
            for (int j = 0; j < value; j++)
                dq.pop_back();
        }
    }

    while (!dq.empty())
    {
        printf("%d\n", dq.front());
        dq.pop_front();
    }

    return 0;
}