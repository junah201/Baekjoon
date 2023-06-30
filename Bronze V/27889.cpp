/* Code By [ junah ]
GitHub : [ junah201 ] */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define int long long int
#define INF LONG_LONG_MAX

char c;

signed main()
{
    scanf("%1c", &c);

    if (c == 'N')
        printf("North London Collegiate School");
    else if (c == 'B')
        printf("Branksome Hall Asia");
    else if (c == 'K')
        printf("Korea International School");
    else if (c == 'S')
        printf("St. Johnsbury Academy");

    return 0;
}