#include <bits/stdc++.h>
using namespace std;
// typedef tuple<int, int, int, int> tp;

// tp fwr[100002];

int month_len[13] = {
    0,
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31};

struct month
{
    int m, d;
};

struct fwr
{
    struct month s, e;
};

int monthTOInt(struct month k)
{
    int num = 100 * k.m;
    num = 100 * num + k.d;

    return num;
}

int N;
vector<fwr> v;

int main()
{
    scanf("%d", &N);
    for (int i = 0, a, b, c, d; i < N; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        v.push_back({a, b, c, d});
    }

    sort(v.begin(), v.end(), [](struct fwr a, struct fwr b)
         {
            int num_a = 100 * a.e.m;
            num_a = 100 * num_a + a.e.d;
            num_a = 100 * num_a + a.s.m;
            num_a = 100 * num_a + a.s.d;
        
            int num_b = 100 * b.e.m;
            num_b = 100 * num_b + b.e.d;
            num_b = 100 * num_b + b.s.m;
            num_b = 100 * num_b + b.s.d;

            return monthTOInt(a.s) * 10000 + monthTOInt(a.e) < monthTOInt(b.s) * 10000 + monthTOInt(b.e); });
    /*
        for (auto i : v)
        {
            printf("(%02d %02d), (%02d %02d)\n", i.s.m, i.s.d, i.e.m, i.e.d);
        }
    */
    int cnt = 0;
    struct month r = {3, 1};
    for (int i = 0; i < v.size(); i++)
    {
        struct month k = {-1, -1};
        int tmp = i;

        for (int j = i; j < v.size(); j++)
        {
            if (monthTOInt(v[j].s) <= monthTOInt(r)) // && monthTOInt(v[j].e) >= monthTOInt(r))
            {
                if (monthTOInt(k) < monthTOInt(v[j].e))
                {
                    k = v[j].e;
                    tmp = j;
                }
            }
            // else if (monthTOInt(v[j].s) <= monthTOInt(r) && monthTOInt(v[j].e) < monthTOInt(r))
            //     continue;
            else
                break;
        }
        if (k.m == -1 && k.d == -1)
        {
            printf("0");
            return 0;
        }
        r = k;
        cnt++;
        i = tmp;
        if (r.m > 11)
        {
            break;
        }
    }
    if (r.m <= 11)
    {
        printf("0");
        return 0;
    }
    printf("%d", cnt);
    return 0;
}