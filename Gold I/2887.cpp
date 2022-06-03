#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

vector<pair<int, pair<int, int>>> info;
int p[100001];

int fin(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fin(p[x]);
}

void uni(int a, int b)
{
    a = fin(a);
    b = fin(b);

    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main()
{

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        p[i] = i;

    for (int i = 0, x, y, z; i < N; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N - 1; i++)
    {
        info.push_back({X[i + 1].first - X[i].first, {X[i].second, X[i + 1].second}});
        info.push_back({Y[i + 1].first - Y[i].first, {Y[i].second, Y[i + 1].second}});
        info.push_back({Z[i + 1].first - Z[i].first, {Z[i].second, Z[i + 1].second}});
    }

    sort(info.begin(), info.end());

    int cnt = 0;
    int total = 0;

    for (int i = 0; i < info.size(); i++)
    {
        int a = info[i].second.first;
        int b = info[i].second.second;
        int val = info[i].first;

        if (fin(a) != fin(b))
        {
            uni(a, b);
            total += val;
        }
    }

    printf("%d", total);

    return 0;
}