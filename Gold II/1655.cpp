// 1655 가운데를 말해요
// https://www.acmicpc.net/source/39606620

#include <stdio.h>
#include <queue>
using namespace std;

int N, mid;
priority_queue<int, vector<int>, greater<int>> high;
priority_queue<int, vector<int>> low;

int main()
{
    scanf("%d", &N);
    for (int i = 0, temp; i < N; i++)
    {
        scanf("%d", &temp);
        if (i == 0)
            mid = temp;
        else if (temp > mid)
            high.push(temp);
        else
            low.push(temp);

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
        printf("%d\n", mid);
    }
    return 0;
}