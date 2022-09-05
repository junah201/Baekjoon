#include <bits/stdc++.h>
using namespace std;

char s[102];
int len;

int alpha[26];

int main()
{
    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len; i++)
        alpha[s[i] - 'a']++;

    for (int i = 0; i < 26; i++)
        printf("%d ", alpha[i]);

    return 0;
}
