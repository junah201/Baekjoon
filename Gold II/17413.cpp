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

char A[100002];
int len;
stack<char> s;
bool is_tag_in = false;

signed main()
{
    fgets(A, sizeof(A), stdin);
    len = strlen(A);

    for (int i = 0; i < len; i++)
    {
        if (A[i] == ' ' && is_tag_in == false)
        {
            while (!s.empty())
            {
                printf("%c", s.top());
                s.pop();
            }
            printf(" ");
        }
        else if (A[i] == '<')
        {
            while (!s.empty())
            {
                printf("%c", s.top());
                s.pop();
            }
            is_tag_in = true;
            printf("%c", A[i]);
        }
        else if (A[i] == '>')
        {
            is_tag_in = false;
            printf("%c", A[i]);
        }
        else if (is_tag_in == true)
        {
            printf("%c", A[i]);
        }
        else
        {
            s.emplace(A[i]);
        }
    }

    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }

    return 0;
}