// 11286 절대값 힙
// https://www.acmicpc.net/source/39478779

#include <stdio.h>
#include <queue>
#define abs(x) (((x) < 0) ? -(x) : (x))

using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        if (abs(a) > abs(b))
            return 1;
        else if (abs(a) < abs(b))
            return 0;
        else
            return a > b;
    };
};

priority_queue<int, vector<int>, cmp> pq;
int N, X;

int main()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        if (X == 0)
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
            pq.push(X);
    }
    return 0;
}