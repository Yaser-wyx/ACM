#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-24
 *  @Time: 17:26
 *  To change this template use File | Settings | File Templates.
 * 
 */
//todo 树形DP 还未做完

int x, m;
bool edges[110][110];//边的信息
struct room {
    int bugs;
    int brains;
} rooms[110];

struct node {
    int nums;//剩余可以消灭的bugs
    int brains;//已经获取到的brains数量
} tree[110];


int hdu1011() {
    while (~scanf("%d %d", &x, &m)) {
        if (x + m == -2)break;
        tree[0] = {m * 20, 0};//初始化
        for (int i = 1; i <= x; i++) {
            scanf("%d %d", &rooms[i].bugs, &rooms[i].brains);
        }
        memset(edges, false, sizeof(edges));
        for (int i = 0; i < x - 1; i++) {
            int from, to;
            scanf("%d%d", &from, &to);
            edges[from][to] = true;
        }
        int max = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= x; j++) {
                if (edges[i][j]) {
                    //i可以到j


                }

            }

        }
    }
    return 0;
}