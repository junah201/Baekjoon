#include <bits/stdc++.h>
using namespace std;

int N, E, ans;

struct node
{
    int start;
    int end;
    int dis;
};

vector<int> p;
vector<node> graph;

int fin(int a)
{
    if (p[a] == a)
        return a;
    return p[a] = fin(p[a]);
}

void uni(int a, int b)
{
    p[fin(a)] = fin(b);
}

int main()
{
    scanf("%d %d", &N, &E);
    p.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
        p[i] = i;
    for (int i = 0, start, end, dis; i < E; i++)
    {
        scanf("%d %d %d", &start, &end, &dis);
        graph.push_back({start, end, dis});
    }
    sort(graph.begin(), graph.end(), [](struct node a, struct node b)
         { return a.dis < b.dis; });
    for (auto i : graph)
    {
        int start = i.start, end = i.end, dis = i.dis;
        if (fin(start) == fin(end))
            continue;
        ans += dis;
        uni(start, end);
    }

    printf("%d", ans);
    return 0;
}
