#include <bits/stdc++.h>
using namespace std;
/*
def cmp(a : str, b : str):
    if a == "0":
        return 1
    if b == "0":
        return -1

    is_a = True
    is_b = True

    idx_a = 0
    idx_b = 0

    len_a = len(a)
    len_b = len(b)

    while idx_a != len_a + len_b:
        if idx_a == len_a:
            is_a = 0
        if idx_b == len_b:
            is_b = 0

        if is_a:
            temp_a = a[idx_a]
        else:
            temp_a = b[idx_a - len_a]
        idx_a += 1

        if is_b:
            temp_b = b[idx_b]
        else:
            temp_b = a[idx_b - len_b]
        idx_b += 1

        if temp_a > temp_b:
            return -1
        elif temp_a < temp_b:
            return 1

    return 0
*/
struct cmp
{
    bool operator()(string a, string b)
    {
        if (a == "0")
            return 1;
        if (b == "0")
            return 0;

        bool is_a = true;
        bool is_b = true;

        char ta, tb;

        int idx_a = 0;
        int idx_b = 0;

        int len_a = a.length();
        int len_b = b.length();

        while (idx_a != len_a + len_b)
        {
            if (idx_a == len_a)
                is_a = false;
            if (idx_b == len_b)
                is_b = false;

            if (is_a)
                ta = a[idx_a];
            else
                ta = b[idx_a - len_a];
            idx_a++;

            if (is_b)
                tb = b[idx_b];
            else
                tb = a[idx_b - len_b];
            idx_b++;

            if (ta > tb)
                return 1;
            else if (ta < tb)
                return 0;
        }
        return 0;
    }
};

int N;
priority_queue<string, vector<string>, cmp> pq;
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