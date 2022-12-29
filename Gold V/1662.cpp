#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

stack<int> a;
char str[100];
int num[100] = {
    0,
};
int len;
int sum;

int main()
{
    scanf("%s", &str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == ')')
            num[i] = 0;
        else
            num[i] = 1;
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            a.push(i);
        }
        else if (str[i] == ')')
        {
            sum = 0;

            for (int j = a.top() + 1; j < i; j++)
            {
                sum += num[j];
                num[j] = 0;
            }
            sum *= str[a.top() - 1] - '0';
            num[a.top() - 1] = sum;
            a.pop();
        }
    }
    sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += num[i];
    }
    printf("%d", sum);
    return 0;
}