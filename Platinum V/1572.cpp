#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, mid, sum;
priority_queue<int, vector<int>, greater<int>> high;
priority_queue<int, vector<int>> low;

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1, temp; i <= N; i++)
    {
        scanf("%d", &temp);

        if (i == 1)
            mid = temp;

        else if (temp < mid)
            low.push(temp);
        else
            high.push(temp);

        if (1)
        {
            while (high.size() - low.size() > 1)
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
            if (i >= K)
                sum += mid;
        }
        else
        {
        }
        printf("%d : %d %lu %lu\n", i, mid, low.size(), high.size());
    }
    printf("%d", sum);
    return 0;
}