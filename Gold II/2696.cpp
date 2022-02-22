// 2696  중앙값 구하기
// https://www.acmicpc.net/source/39478649

#include <stdio.h>
#include <queue>
using namespace std;

int T, M;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        priority_queue<int, vector<int>, greater<int>> high;
        priority_queue<int, vector<int>> low;
        int mid;
        scanf("%d", &M);
        printf("%d\n", M / 2 + 1);
        for (int i = 1, temp; i <= M; i++)
        {
            scanf("%d", &temp);

            if (i == 1)
                mid = temp;

            else if (temp < mid)
                low.push(temp);
            else
                high.push(temp);

            if (i % 2 == 1)
            {
                while (low.size() != high.size())
                {
                    if (low.size() > high.size())
                    {
                        high.push(mid);
                        mid = low.top();
                        low.pop();
                    }
                    else
                    {
                        low.push(mid);
                        mid = high.top();
                        high.pop();
                    }
                }
                if (i != 1 && i / 2 % 10 == 0)
                    printf("\n");
                printf("%d ", mid);
            }
        }
        printf("\n");
    }
}