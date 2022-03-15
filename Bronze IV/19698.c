// 19698 헛간 청약
// https://www.acmicpc.net/source/40499224

#include <stdio.h>

int N, W, H, L, room, num;

int main()
{
    scanf("%d %d %d %d", &N, &W, &H, &L);
    room = (W / L) * (H / L);
    if (room > N)
        printf("%d", N);
    else
        printf("%d", room);
    return 0;
}