#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-19
 *  @Time: 11:37
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 15

int HDU1035() {
    int a, b, c;
    char map1[maxn][maxn];

    while (~scanf("%d%d%d", &a, &b, &c)) {
        if (a + b + c == 0)break;
        memset(map1, '.', sizeof(map1));
        for (int i = 1; i <= a; i++) {
            getchar();
            for (int j = 1; j <= b; j++) {
                scanf("%c", &map1[i][j]);
            }
        }
        int x = 1, y = c;
        int last_x = 0, last_y = 0;
        int distance[maxn][maxn];
        memset(distance, 0, sizeof(distance));
        bool flag = false;//表示是否有循环节
        while (map1[x][y] != '.') {
            distance[x][y] = distance[last_x][last_y] + 1;
            last_x = x;
            last_y = y;
            switch (map1[x][y]) {
                case 'W':
                    y--;
                    break;
                case 'N':
                    x--;
                    break;
                case 'E':
                    y++;
                    break;
                case 'S':
                    x++;
                    break;
                default:
                    break;
            }
            if (distance[x][y]) {
                flag = true;
                break;
            }
        }

        if (flag) {
            //有循环节
            int ans1 = distance[x][y] - 1;
            int ans2 = distance[last_x][last_y] - distance[x][y] + 1;
            printf("%d step(s) before a loop of %d step(s)\n", ans1, ans2);
        } else {
            printf("%d step(s) to exit\n", distance[last_x][last_y]);
        }
    }
    return 0;
}