// 11279 최대 힙
// https://www.acmicpc.net/source/39478916

#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int T, N;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        if (!N)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
            pq.push(N);
    }
    return 0;
}