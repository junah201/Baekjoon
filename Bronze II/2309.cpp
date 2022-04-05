// 2309  일곱 난쟁이

#include <stdio.h>
#include <algorithm>

using namespace std;

int input[9];
int sum;
int check = 1;
int main()
{
    for (int i = 0; i < 9; i++)
        scanf("%d", &input[i]);
    sort(input, input + 9);
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (j != i)
            {
                for (int k = 9; k >= 0; k--)
                {
                    if (k != i && k != j)
                    {
                        sum = 0;
                        for (int m = 0; m < 9; m++)
                        {
                            if (m != i && m != j && m != k)
                                sum += input[m];
                        }
                        if (sum == 100)
                        {
                            for (int m = 0; m < 9; m++)
                            {
                                if (m != i && m != j && m != k)
                                {
                                    printf("%d\n", input[m]);
                                }
                            }
                            check = 0;
                            goto EXIT;
                        }
                    }
                }
            }
        }
    }
EXIT:
    return 0;
}