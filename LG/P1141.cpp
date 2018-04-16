#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-13
 *  @Time: 21:45
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 1005
int n, m;
char puzzle[maxn][maxn];
int mv[4][2] = {{1,  0},
                {0,  1},
                {-1, 0},
                {0,  -1}};
int dis[maxn][maxn];
int ans[100005];
int cnt = 0;

void bfs(int x, int y, int index) {
    pair<int, int> start(x, y);
    queue<pair<int, int>> queue1;
    queue1.push(start);
    while (!queue1.empty()) {
        pair<int, int> now = queue1.front();
        ans[index]++;
        queue1.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = now.first + mv[i][0];
            int new_y = now.second + mv[i][1];
            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= n) {
                if (!dis[new_x][new_y]) {
                    if (puzzle[new_x][new_y] != puzzle[now.first][now.second]) {
                        dis[new_x][new_y] = index;
                        pair<int, int> temp(new_x, new_y);
                        queue1.push(temp);
                    }
                }
            }
        }
    }

}

int P1141() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> puzzle[i][j];
        }
    }
    int x, y;
    mset(dis, 0);
    mset(ans, 0);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        int res;
        if (dis[x][y]) {
            res = ans[dis[x][y]];
        } else {
            dis[x][y] = i;
            bfs(x, y, i);
            res = ans[i];
        }
        printf("%d\n", res);
    }
    return 0;

}