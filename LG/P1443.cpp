#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-13
 *  @Time: 16:28
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 405
using namespace std;
int n, m, x, y;
int dis[maxn][maxn];
int mv[8][2] = {{1,  2},
                {-1, 2},
                {2,  1},
                {-2, 1},
                {1,  -2},
                {-1, -2},
                {-2, -1},
                {2,  -1}};

void bfs() {
    pair<int, int> start(x, y);
    queue<pair<int, int>> queue1;
    queue1.push(start);
    while (!queue1.empty()) {
        int temp_x = queue1.front().first;
        int temp_y = queue1.front().second;
        queue1.pop();
        for (int i = 0; i < 8; i++) {
            int new_x = temp_x + mv[i][0];
            int new_y = temp_y + mv[i][1];
            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= m) {
                if(dis[new_x][new_y]==-1){
                    //能到达
                    dis[new_x][new_y] = dis[temp_x][temp_y] + 1;
                    pair<int, int> temp(new_x, new_y);
                    queue1.push(temp);
                }

            }
        }
    }
}

int P1443() {
    in;
    mset(dis, -1);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    dis[x][y] = 0;
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}