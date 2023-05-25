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

char A[102];
stack<char> s;

signed main()
{
    scanf("%s", A);

    int len = strlen(A);

    for (int i = 0; i < len; i++)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            printf("%c", A[i]);
            continue;
        }

        if (A[i] == '(')
        {
            s.emplace('(');
        }
        else if (A[i] == '*' || A[i] == '/')
        {
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                printf("%c", s.top());
                s.pop();
            }
            s.emplace(A[i]);
        }
        else if (A[i] == '+' || A[i] == '-')
        {
            while (!s.empty() && s.top() != '(')
            {
                printf("%c", s.top());
                s.pop();
            }
            s.emplace(A[i]);
        }
        else if (A[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                printf("%c", s.top());
                s.pop();
            }
            s.pop();
        }
    }

    while (!s.empty() && s.top() != '(')
    {
        printf("%c", s.top());
        s.pop();
    }

    return 0;
}