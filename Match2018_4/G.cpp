/*
#include <bits/stdc++.h>

*/
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-01
 *  @Time: 11:24
 *  To change this template use File | Settings | File Templates.
 * 
 *//*

#define maxn 110
using namespace std;

int n, m;
char puzzle[maxn][maxn];
struct edge {
    int dis1;//曼哈顿距离
    int dis2 = -1;//绕过墙走的距离,-1代表v与w之间一定要翻墙
    bool wall = true;//是否有墙
} graph[5][5];

struct node {
    node(int x, int y) : x(x), y(y) {}

    node() {}

    //坐标
    int x, y;
    //携带该部件移动所需要的时间
    int cost = 0;
} nodes[5];//分别代表0起点，1炮管，2车轮，3炮弹，4终点

void bfs() {
    //计算炮管，车轮，炮弹分别到其它各点的距离

    int move[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};//移动数组
    bool vis[n + 1][m + 1];//节点是否访问过
    int dis[n + 1][m + 1];//各起始点到各点的距离
    for (int i = 1; i < 4; i++) {
        queue<node> queue1;
        queue1.push(nodes[i]);//将第i个作为起点
        int sx = nodes[i].x;
        int sy = nodes[i].y;
        memset(vis, false, sizeof(vis));//初始化
        memset(dis, 0, sizeof(dis));
        vis[sx][sy] = true;
        while (!queue1.empty()) {//bfs
            node temp = queue1.front();
            queue1.pop();
            int x = temp.x;
            int y = temp.y;
            for (int j = 0; j < 4; j++) {
                int new_x = x + move[j][0];
                int new_y = y + move[j][1];
                if (puzzle[new_x][new_y] != '#') {
                    if (!vis[new_x][new_y]) {
                        //未访问过
                        vis[new_x][new_y] = true;
                        dis[new_x][new_y] = dis[x][y] + 1;
                        queue1.push(node(new_x, new_y));
                    }
                }
            }
        }

        //读取dis数据，将从第i个节点到各个点的距离存起来
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                continue;
            }
            int temp_x = nodes[j].x;
            int temp_y = nodes[j].y;
            int len = dis[temp_x][temp_y];
            if (len != 0) {//从nodes[i]到nodes[j]的距离
                //可以到达
                graph[i][j].dis2 = len;
                graph[i][j].wall = (graph[i][j].dis1 != graph[i][j].dis2);//如果二者距离一样则代表没有墙
            }
            graph[j][i].dis2 = graph[i][j].dis2;
            graph[j][i].wall = graph[i][j].wall;
        }
    }
}

int caculate() {
    int ans = 9999999;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (i == j)continue;
            for (int k = 1; k < 4; k++) {
                if (k == i || k == j || graph[k][4].dis2 == -1)continue;
                int temp = graph[0][i].dis1 + graph[i][j].dis1 * (nodes[i].cost + 1) +
                           graph[j][k].dis1 * (nodes[j].cost + nodes[i].cost + 1);
                if (graph[k][4].wall) {
                    //有墙
                    temp += graph[k][4].dis2 * (nodes[j].cost + nodes[i].cost + nodes[k].cost + 1);
                } else {
                    //没墙
                    temp += graph[k][4].dis1 * (nodes[j].cost + nodes[i].cost + nodes[k].cost + 1);
                }
                ans = min(ans, temp);
            }
        }
    }
    return ans;

}

int G() {
    scanf("%d%d", &n, &m);
    getchar();
    memset(puzzle, '#', sizeof(puzzle));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%c", &puzzle[i][j]);
        }
        getchar();
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
    }
    scanf("%d%d%d", &nodes[1].cost, &nodes[2].cost, &nodes[3].cost);
    //计算各点的曼哈顿距离
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int dis = abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y);//曼哈顿距离
            graph[i][j].dis1 = dis;
            graph[j][i].dis1 = dis;
        }
    }
    bfs();
    int steps = caculate();
    printf("%d\n", steps);
    return 0;
}
*/
