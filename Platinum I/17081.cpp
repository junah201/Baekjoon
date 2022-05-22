#include <bits/stdc++.h>
using namespace std;

int i;
int N, M, K, L;
int cmdlen;
char cmd[5002];

struct tplayer
{
    int start_x, start_y;
    int x, y, hp, atk, def, tool_atk, tool_def, level, exp;
    int jewelry_cnt;
    int jewelry[8] = {
        0,
    };
} player;

struct tinfo
{
    char input;
    char type;
    char name[12];
    int W, A, H, E;
    int hp;
    int atk, def;
    char skill[5];
} info[102][102];

int jewelry_to_int(char first, char second)
{
    if (first == 'H' && second == 'R')
        return 1;
    if (first == 'R' && second == 'E')
        return 2;
    if (first == 'C' && second == 'O')
        return 3;
    if (first == 'E' && second == 'X')
        return 4;
    if (first == 'D' && second == 'X')
        return 5;
    if (first == 'H' && second == 'U')
        return 6;
    if (first == 'C' && second == 'U')
        return 7;

    return 0;
}

void end(int turn, int state, int x, int y)
{
    for (int ty = 1; ty <= N; ty++)
    {
        for (int tx = 1; tx <= M; tx++)
        {
            if (tx == player.x && ty == player.y && state != 2)
                printf("@");
            else
                printf("%c", info[ty][tx].input);
        }
        printf("\n");
    }
    printf("Passed Turns : %d\n", turn);
    printf("LV : %d\n", player.level);
    printf("HP : %d/%d\n", max(0, player.hp), 15 + player.level * 5);
    printf("ATT : %d+%d\n", player.atk, player.tool_atk);
    printf("DEF : %d+%d\n", player.def, player.tool_def);
    printf("EXP : %d/%d\n", player.exp, player.level * 5);
    // 승리
    if (state == 1)
        printf("YOU WIN!");
    // 패배
    else if (state == 2)
    {
        if (info[y][x].input == '^')
            printf("YOU HAVE BEEN KILLED BY SPIKE TRAP..");
        else
            printf("YOU HAVE BEEN KILLED BY %s..", info[y][x].name);
    }
    // 미결정
    else if (state == 0)
        printf("Press any key to continue.");
    exit(0);
}

void print_map()
{
    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= M; x++)
        {
            if (x == player.x && y == player.y)
                printf("@");
            else
                printf("%c", info[y][x].input);
        }
        printf("\n");
    }
}

int main()
{
    // 맵 입력
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; y++)
        for (int x = 1; x <= M; x++)
        {
            scanf(" %c", &info[y][x].input);
            if (info[y][x].input == '@')
            {
                player.start_x = x;
                player.start_y = y;
                player.x = x;
                player.y = y;
                player.hp = 20;
                player.atk = 2;
                player.def = 2;
                player.tool_atk = 0;
                player.tool_def = 0;
                player.level = 1;
                player.exp = 0;
            }
            else if (info[y][x].input == '&' || info[y][x].input == 'M')
                K++;
            else if (info[y][x].input == 'B')
                L++;
        }

    // cmd 입력
    scanf("%s", cmd);
    // 적 정보 입력
    for (int i = 0, tx, ty; i < K; i++)
    {
        scanf("%d %d", &ty, &tx);
        info[ty][tx].type = 'M';
        scanf(" %s", info[ty][tx].name);
        scanf("%d %d %d %d", &info[ty][tx].W, &info[ty][tx].A, &info[ty][tx].H, &info[ty][tx].E);
        info[ty][tx].hp = info[ty][tx].H;
    }
    // 상자 정보 입력
    for (int i = 0, tx, ty; i < L; i++)
    {
        scanf("%d %d", &ty, &tx);
        char type;
        scanf(" %c", &type);
        if (type == 'W')
        {
            info[ty][tx].type = 'W';
            scanf("%d", &info[ty][tx].atk);
        }
        else if (type == 'A')
        {
            info[ty][tx].type = 'A';
            scanf("%d", &info[ty][tx].def);
        }
        else if (type == 'O')
        {
            info[ty][tx].type = 'O';
            scanf(" %s", info[ty][tx].skill);
        }
    }

    // 플레이어 지우기
    info[player.start_y][player.start_x].input = '.';

    // 실행
    cmdlen = strlen(cmd);
    for (int dx, dy; i < cmdlen; i++)
    {
#ifndef ONLINE_JUDGE
        if (i != 0)
            printf("cmd : %c\n", cmd[i - 1]);
        printf("Passed Turns : %d\n", i);
        printf("LV : %d\n", player.level);
        printf("HP : %d/%d\n", player.hp, 15 + player.level * 5);
        printf("ATT : %d+%d\n", player.atk, player.tool_atk);
        printf("DEF : %d+%d\n", player.def, player.tool_def);
        printf("EXP : %d/%d\n", player.exp, player.level * 5);
        printf("JUL CNT : %d\n", player.jewelry_cnt);
        printf("xy : (%d, %d)\n", player.x, player.y);
        print_map();
#endif
        //  이동
        if (cmd[i] == 'R')
        {
            dx = player.x + 1;
            dy = player.y;
        }
        else if (cmd[i] == 'L')
        {
            dx = player.x - 1;
            dy = player.y;
        }
        else if (cmd[i] == 'U')
        {
            dx = player.x;
            dy = player.y - 1;
        }
        else if (cmd[i] == 'D')
        {
            dx = player.x;
            dy = player.y + 1;
        }

        // 명령 실행
        // 빈칸
        if (info[dy][dx].input == '.')
        {
            player.x = dx;
            player.y = dy;
        }
        // 벽
        else if (info[dy][dx].input == '#' || dx == 0 || dy == 0 || dx == M + 1 || dy == N + 1)
        {
            // 현재 칸이 가시 함정이면 추가 데미지
            if (info[player.y][player.x].input == '^')
            {
                // 장신구 - DX
                if (player.jewelry[5])
                    player.hp -= 1;
                else
                    player.hp -= 5;
                // 사망시
                if (player.hp <= 0)
                {
                    if (player.jewelry[2])
                    {
                        player.hp = 15 + player.level * 5;
                        player.x = player.start_x;
                        player.y = player.start_y;
                        player.jewelry[2] = 0;
                        player.jewelry_cnt--;
                    }
                    else
                        end(i + 1, 2, player.x, player.y);
                }
            }
        }
        // 가시 함정
        if (info[dy][dx].input == '^')
        {
            player.x = dx;
            player.y = dy;
            // 장신구 - DX
            if (player.jewelry[5])
                player.hp -= 1;
            else
                player.hp -= 5;
            // 사망시
            if (player.hp <= 0)
            {
                if (player.jewelry[2])
                {
                    player.hp = 15 + player.level * 5;
                    player.x = player.start_x;
                    player.y = player.start_y;
                    player.jewelry[2] = 0;
                    player.jewelry_cnt--;
                }
                else
                    end(i + 1, 2, dx, dy);
            }
        }
        // 몬스터
        else if (info[dy][dx].input == '&' || info[dy][dx].input == 'M')
        {
            player.x = dx;
            player.y = dy;
            // 장신구 - DX
            if (player.jewelry[6] && info[dy][dx].input == 'M')
                player.hp = 15 + player.level * 5;
            for (int j = 0;; j++)
            {
#ifndef ONLINE_JUDGE
                printf("\n");
                printf("==player==\n");
                printf("HP : %d/%d\n", player.hp, 15 + player.level * 5);
                printf("ATT : %d+%d\n", player.atk, player.tool_atk);
                printf("DEF : %d+%d\n", player.def, player.tool_def);
                printf("==monster==\n");
                printf("HP : %d/%d\n", info[dy][dx].hp, info[dy][dx].H);
                printf("ATT : %d\n", info[dy][dx].W);
                printf("DEF : %d\n", info[dy][dx].A);
                printf("\n");
#endif

#ifndef ONLINE_JUDGE
                if (j == 0 && player.jewelry[3] && player.jewelry[5])
                    printf("player : %d\n", max(1, 3 * (player.atk + player.tool_atk) - info[dy][dx].A));
                else if (j == 0 && player.jewelry[3])
                    printf("player : %d\n", max(1, 2 * (player.atk + player.tool_atk) - info[dy][dx].A));
                else
                    printf("player : %d\n", max(1, (player.atk + player.tool_atk) - info[dy][dx].A));
                printf("==%d %d  ==\n", 2 * (player.atk + player.tool_atk) - info[dy][dx].A, info[dy][dx].A);
#endif
                // 플레이어 선공 - 장신구
                if (j == 0 && player.jewelry[3] && player.jewelry[5])
                    info[dy][dx]
                        .hp -= max(1, 3 * (player.atk + player.tool_atk) - info[dy][dx].A);
                else if (j == 0 && player.jewelry[3])
                    info[dy][dx].hp -= max(1, 2 * (player.atk + player.tool_atk) - info[dy][dx].A);
                else
                    info[dy][dx].hp -= max(1, (player.atk + player.tool_atk) - info[dy][dx].A);

                // 몬스터가 죽었으면
                if (info[dy][dx].hp <= 0)
                {

#ifndef ONLINE_JUDGE
                    printf("\n== EXP ==\n");
                    if (player.jewelry[4])
                        printf("%d + %d = %d\n\n", player.exp, info[dy][dx].E * 12 / 10, player.exp + info[dy][dx].E * 12 / 10);
                    else
                        printf("%d + %d = %d\n\n", player.exp, info[dy][dx].E, player.exp + info[dy][dx].E);
#endif
                    // 경험치 획득 - 장신구
                    if (player.jewelry[4])
                        player.exp += info[dy][dx].E * 12 / 10;
                    else
                        player.exp += info[dy][dx].E;

                    // 장신구 HP 회복
                    if (player.jewelry[1])
                        player.hp = min(player.hp + 3, 15 + player.level * 5);

                    // 레벨업
                    if (player.exp >= player.level * 5)
                    {
                        player.exp = 0;
                        player.level++;
                        player.atk += 2;
                        player.def += 2;
                        player.hp = 15 + player.level * 5;
                    }

                    // 죽은 몬스터가 보스 이면
                    if (info[dy][dx].input == 'M')
                        end(i + 1, 1, dx, dy);
                    // 몬스터 제거
                    info[dy][dx].input = '.';
                    break;
                }

                // 몬스터 후공
#ifndef ONLINE_JUDGE
                if (j == 0 && player.jewelry[6])
                    printf("Monster : 0\n");
                else
                    printf("Monster : %d\n", max(1, (info[dy][dx].W) - (player.def + player.tool_def)));
#endif
                if (j == 0 && player.jewelry[6])
                    continue;
                player.hp -= max(1, (info[dy][dx].W) - (player.def + player.tool_def));

                // 플레이어가 죽었으면
                if (player.hp <= 0)
                {
                    // 장신구 RE 부활
                    if (player.jewelry[2])
                    {
                        player.hp = 15 + player.level * 5;
                        player.x = player.start_x;
                        player.y = player.start_y;
                        player.jewelry[2] = 0;
                        player.jewelry_cnt--;
                        info[dy][dx].hp = info[dy][dx].H;
                        break;
                    }
                    else
                        end(i + 1, 2, dx, dy);
                }
            }
        }
        // 상자 - 장신구
        else if (info[dy][dx].input == 'B')
        {
            player.x = dx;
            player.y = dy;
            info[dy][dx].input = '.';

#ifndef ONLINE_JUDGE
            // 무기
            if (info[dy][dx].type == 'W')
                printf("==tool atk : %d\n", info[dy][dx].atk);
            // 방어구
            else if (info[dy][dx].type == 'A')
                printf("==tool def : %d\n", info[dy][dx].def);
#endif

            // 무기
            if (info[dy][dx].type == 'W')
                player.tool_atk = info[dy][dx].atk;
            // 방어구
            else if (info[dy][dx].type == 'A')
                player.tool_def = info[dy][dx].def;
            // 장신구
            else if (info[dy][dx].type == 'O')
            {
                if (player.jewelry_cnt == 4)
                    continue;

#ifndef ONLINE_JUDGE
                printf("== add jewelry : %s\n", info[dy][dx].skill);
#endif

                int jewelry_id = jewelry_to_int(info[dy][dx].skill[0], info[dy][dx].skill[1]);

                if (player.jewelry[jewelry_id])
                    continue;
                player.jewelry[jewelry_id] = 1;
                player.jewelry_cnt++;
            }
        }
    }
    end(i, 0, 0, 0);
}