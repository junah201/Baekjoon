/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dprintf(const char *__format, ...)
{
#ifndef ONLINE_JUDGE
    va_list args;
    va_start(args, __format);
    vprintf(__format, args);
    va_end(args);
#endif
}

int N;

queue<pair<int, int>> student;
queue<int> food;
priority_queue<int, vector<int>, greater<int>> A, B, C;

signed main()
{
    scanf("%lld", &N);

    while (N--)
    {
        int oper, a, b;
        scanf("%lld", &oper);

        if (oper == 1)
        {
            scanf("%lld %lld", &a, &b);
            student.emplace(a, b);
        }
        else if (oper == 2)
        {
            scanf("%lld", &b);
            food.emplace(b);
        }

        while (!student.empty() && !food.empty())
        {
            auto [id, favo] = student.front();
            student.pop();

            int now_food = food.front();
            food.pop();

            if (now_food == favo)
                A.emplace(id);
            else
                B.emplace(id);
        }
    }

    if (A.empty())
        printf("None\n");
    else
    {
        while (!A.empty())
        {
            printf("%lld ", A.top());
            A.pop();
        }
        printf("\n");
    }

    if (B.empty())
        printf("None\n");
    else
    {
        while (!B.empty())
        {
            printf("%lld ", B.top());
            B.pop();
        }
        printf("\n");
    }

    if (student.empty())
        printf("None\n");
    else
    {
        while (!student.empty())
        {
            C.emplace(student.front().first);
            student.pop();
        }
        while (!C.empty())
        {
            printf("%lld ", C.top());
            C.pop();
        }
        printf("\n");
    }

    return 0;
}