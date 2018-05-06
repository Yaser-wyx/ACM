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
int dis[maxn][maxn];//一个联通分量使用一个数值进行标记
int ans[100005];//保存每一次bfs后的答案
int cnt = 0;

void bfs(int x, int y, int index) {
    pair<int, int> start(x, y);
    queue<pair<int, int>> queue1;
    queue1.push(start);
    while (!queue1.empty()) {
        pair<int, int> now = queue1.front();
        ans[index]++;
        queue1.pop();
        for (int i = 0; i < 4; i++) {//访问
            int new_x = now.first + mv[i][0];
            int new_y = now.second + mv[i][1];
            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= n) {//判断合法性
                if (!dis[new_x][new_y]) {//如果没有访问过
                    if (puzzle[new_x][new_y] != puzzle[now.first][now.second]) {//只能移动到不同的格子里
                        dis[new_x][new_y] = index;//打标记
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
            cin >> puzzle[i][j];//读入
        }
    }
    int x, y;
    mset(dis, 0);
    mset(ans, 0);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        int res;
        if (dis[x][y]) {//如果该位置已经遍历过了
            res = ans[dis[x][y]];//直接输出答案
        } else {
            dis[x][y] = i;//打上标记
            bfs(x, y, i);
            res = ans[i];
        }
        printf("%d\n", res);
    }
    return 0;

}