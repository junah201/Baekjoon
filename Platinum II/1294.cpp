#include <bits/stdc++.h>
using namespace std;

int N;
priority_queue<string, vector<string>, greater<string>> pq;
string s;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        pq.push(s);
    }
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        printf("%c", cur[0]);
        cur.erase(0, 1);

        if (!cur.empty())
            pq.push(cur);
    }
    return 0;
}