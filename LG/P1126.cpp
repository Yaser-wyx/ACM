#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-13
 *  @Time: 20:27
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 55
using namespace std;
int n, m;
int x, y, ex, ey;
int puzzle[maxn][maxn];
int steps[maxn][maxn];
int mv[4][2] = {{-1, 0},
                {0,  1},
                {1,  0},
                {0,  -1}};//-1右转，-2左转
struct node {
    int x;
    int y;
    int step;
    int dir;//方向
    //北：0 东：1 南：2 西：3
    node(int x, int y, int step, int dir) : x(x), y(y), step(step), dir(dir) {}
};

void bfs(node start) {
    queue<node> queue1;
    queue1.push(start);
    while (!queue1.empty()) {
        node now = queue1.front();
        queue1.pop();
        if (now.x != ex || now.y != ey) {
            for (int i = 0; i < 4; i++) {//四个方向访问
                int step = now.step;//走到当前位置的步数
                if (now.dir != i) {
                    //方向不一样
                    step++;
                    if (abs(now.dir - i) == 2) {
                        step++;
                    }
                }
                //对当前方向进行步数的枚举
                for (int j = 1; j < 4; j++) {//步数
                    int temp_x = now.x + mv[i][0] * j;
                    int temp_y = now.y + mv[i][1] * j;
                    if (temp_x > n || temp_x < 1 || temp_y > m || temp_y < 1 || puzzle[temp_x][temp_y]) {//如果越界了或者有障碍物
                        break;
                    }
                    if (steps[temp_x][temp_y] > step + 1) {//从now到新的位置距离更近
                        steps[temp_x][temp_y] = step + 1;//更新值
                        node temp(temp_x, temp_y, step + 1, i);
                        queue1.push(temp);
                    }
                }
            }
        }
    }
}

int P1126() {
    mset(puzzle, 0);
    mset(steps, 1);//1在这里会被存在
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool a;
            cin >> a;
            if (a) {//将格子图转化为点图，因为机器人有体积，有障碍物的格子过不去
                puzzle[i][j] = 1;
                puzzle[i - 1][j] = 1;
                puzzle[i][j - 1] = 1;
                puzzle[i - 1][j - 1] = 1;
            }
        }
    }
    for (int i = 0; i <= m; i++) {//注意边界
        puzzle[0][i] = 1;
        puzzle[n][i] = 1;
    }
    for (int i = 0; i <= n; i++) {//注意边界
        puzzle[i][m] = 1;
        puzzle[i][0] = 1;
    }
    char direction;
    cin >> x >> y >> ex >> ey >> direction;
    int dir;
    switch (direction) {
        //北：0 东：1 南：2 西：3
        case 'S':
            dir = 2;
            break;
        case 'N':
            dir = 0;
            break;
        case 'E':
            dir = 1;
            break;
        default:
            dir = 3;
            break;
    }
    node start(x, y, 0, dir);
    steps[x][y] = 0;
    bfs(start);
    if (steps[ex][ey] == 16843009) {
        printf("-1\n");//无法到达
    } else
        printf("%d\n", steps[ex][ey]);
    return 0;
}