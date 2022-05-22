#include <bits/stdc++.h>
using namespace std;

int N;
struct person
{
    int idx;
    int height;
    int weight;
    int rank;
} p[52];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &p[i].weight, &p[i].height);
        p[i].idx = i;
        p[i].rank = 1;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (p[j].weight > p[i].weight && p[j].height > p[i].height)
                p[i].rank++;
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d ", p[i].rank);
}