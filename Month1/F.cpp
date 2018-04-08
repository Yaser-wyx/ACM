#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-18
 *  @Time: 10:36
 *  To change this template use File | Settings | File Templates.
 * 
 */

int F() {
    int x, y, z, n;
    while (~scanf("%d%d%d%d", &x, &y, &z, &n)) {

        char a[y + 1][x + 1], b[y + 1][z + 1], c[z + 1][x + 1];
        memset(a, '.', sizeof(a));
        memset(b, '.', sizeof(b));
        memset(c, '.', sizeof(c));
        int x1, y1, z1;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &x1, &y1, &z1);
            a[y - y1 + 1][x1] = 'x';
            b[y - y1 + 1][z1] = 'x';
            c[z1][x1] = 'x';
        }
        char ans[y + z + 1][x + z + 1];
        memset(ans, ' ', sizeof(ans));
        int index_x = 0;
        int index_y = 0;
        for (int i = 1; i <= y; i++) {
            for (int j = 1; j <= x; j++) {
                ans[index_x][index_y++] = a[i][j];
            }
            index_x++;
            index_y = 0;
        }
        index_x = 0;
        index_y = x + 1;
        for (int i = 1; i <= y; i++) {
            for (int j = 1; j <= z; j++) {
                ans[index_x][index_y++] = b[i][j];
            }
            index_x++;
            index_y = x + 1;
        }
        index_x = y + 1;
        index_y = 0;
        for (int i = 1; i <= z; i++) {
            for (int j = 1; j <= x; j++) {
                ans[index_x][index_y++] = c[i][j];
            }
            index_x++;
            index_y = 0;
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x + z + 1; j++) {
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (int i = y + 1; i < y + z + 1; i++) {
            for (int j = 0; j < x; j++) {
                printf("%c", ans[i][j]);
            }

            printf("\n");

        }
    }

    return 0;
}