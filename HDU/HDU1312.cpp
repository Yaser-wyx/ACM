#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-22
 *  @Time: 10:33
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 22
int w, h;
char puzzle[maxn][maxn];

struct node {
    int x;
    int y;

    void set(int a, int b) {
        x = a, y = b;
    }

    node() {}

    node(int a, int b) { set(a, b); }
};

node top;

int ans;
int mv[4][2] = {{1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}};

void bfs() {
    ans = 1;//起点也是一个
    queue<node> queue1;
    queue1.push(top);
    while (!queue1.empty()) {
        node temp = queue1.front();
        queue1.pop();
        int x = temp.x;
        int y = temp.y;
        for (int i = 0; i < 4; i++) {
            int new_x = x + mv[i][0];
            int new_y = y + mv[i][1];
            if (new_x >= 0 && new_y >= 0 && new_x < h && new_y < w) {
                if (puzzle[new_x][new_y] == '.') {
                    puzzle[new_x][new_y] = '#';
                    node nn(new_x, new_y);
                    queue1.push(nn);
                    ans++;
                }
            }

        }
    }
}

int HDU1312() {
    while (~scanf("%d%d", &w, &h)) {
        if (w + h == 0) {
            break;
        }
        memset(puzzle, '#', sizeof(puzzle));
        for (int i = 0; i < h; i++) {//读取数据
            getchar();
            for (int j = 0; j < w; j++) {
                scanf("%c", &puzzle[i][j]);
                if (puzzle[i][j] == '@') {
                    top.set(i, j);
                }
            }
        }
        bfs();
        printf("%d\n", ans);

    }

    return 0;
}