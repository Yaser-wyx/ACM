#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

#define maxn 20
using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-23
 *  @Time: 10:51
 *  To change this template use File | Settings | File Templates.
 * 
 */

int puzzle[maxn][maxn];
int mov[4][2] = {{1, -1},
                 {1, 0},
                 {1, 1},
                 {0, 1}};
int step[maxn][maxn];
bool vis[4][maxn][maxn];

int dfs(int x, int y, int k, int z) {

    int new_x = x + mov[k][0];
    int new_y = y + mov[k][1];
    int ans = step[x][y];
    if (new_x >= 0 && new_y >= 0 && new_x < 19 && new_y < 19) {
        if (!vis[k][new_x][new_y]) {
            vis[k][new_x][new_y] = true;
            if (puzzle[new_x][new_y] == z) {
                step[new_x][new_y] = step[x][y] + 1;
                ans = dfs(new_x, new_y, k, z);
            }
        }
    }
    return ans;
}

bool flag;

void Floodfill() {
    flag = false;
    memset(step, 0, sizeof(step));
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (puzzle[i][j] != 0) {
                for (int k = 0; k < 4; k++) {
                    step[i][j] = 1;
                    int ans = dfs(i, j, k, puzzle[i][j]);
                    if (ans == 5) {
                        int x = i + 1;
                        int y = j + 1;
                        if (k == 0) {
                            x += 4;
                            y -= 4;
                        }
                        printf("%d\n%d %d\n", puzzle[i][j], x, y);
                        flag = true;
                        return;
                    }
                }
            }
        }
    }
}

int POJ1970() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(puzzle, 0, sizeof(puzzle));
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                scanf("%d", &puzzle[i][j]);
            }
        }
        Floodfill();
        if (!flag) {
            printf("0\n");
        }
    }

    return 0;
}