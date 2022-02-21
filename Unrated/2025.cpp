#include <stdio.h>
#include <queue>

using namespace std;

int N;

int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};

struct block {
    int x;
    int y;
    int cnt;
} input;

int main() {
    scanf("%d", &N);
    scanf("%d %d", &input.x, &input.y);
}