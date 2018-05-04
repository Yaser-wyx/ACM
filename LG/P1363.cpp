#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-03
 *  @Time: 11:09
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 1505
int n, m;
char puzzle[maxn][maxn];

struct point {
    int x;
    int y;
};

int mv[5][4][2] = {{{-1, 0}, {0, -1}, {1, 0}, {0, 1}},
                   {{-1, 0}, {0, -1}, {0, 0}, {0, 1}},
                   {{-1, 0}, {0, -1}, {1, 0}, {0, 0}},
                   {{0,  0}, {0, -1}, {1, 0}, {0, 1}},
                   {{-1, 0}, {0, 0},  {1, 0}, {0, 1}}};
int dir[maxn][maxn];//保存方向信息
int flag = 0;
point pp[maxn][maxn];//保存该点第一次访问时的坐标

inline int mod(int x, int md) {//取模运算
    return ((x % md) + md) % md;
}

/*上1
 *左2
 *下3
 *右4*/
void dfs(point p) {
    int mv_x, mv_y;
    int nx = mod(p.x, n);
    int my = mod(p.y, m);
    loop3(i, 0, 4) {
        mv_x = mv[dir[nx][my]][i][0];
        mv_y = mv[dir[nx][my]][i][1];
        if (mv_x == mv_y) {//0,0
            continue;
        }
        int new_x = p.x + mv_x;//新的坐标
        int new_y = p.y + mv_y;
        int xx = mod(new_x, n);//映射
        int yy = mod(new_y, m);
        if (puzzle[xx][yy] != '#') {
            if (!dir[xx][yy]) {//是否访问过
                dir[xx][yy] = i + 1;
                point point1;
                point1.x = new_x;
                point1.y = new_y;
                pp[xx][yy].x = new_x;
                pp[xx][yy].y = new_y;
                dfs(point1);
                if (flag == 2) {
                    return;
                }
            } else {
                //如果访问过，判断两次访问时的坐标是否一样，一样代表在环中
                if (pp[xx][yy].y == new_y && pp[xx][yy].x == new_x) {
                    flag = 1;
                } else if (pp[xx][yy].y != new_y || pp[xx][yy].x != new_x) {
                    flag = 2;
                }
                return;
            }
        }
    }
}

int P1363() {
    while (cin >> n >> m) {
        point start;
        flag = 0;
        mset(dir, 0);
        mset(puzzle, 0);
        loop3(i, 0, n) {
            loop3(j, 0, m) {
                cin >> puzzle[i][j];
                if (puzzle[i][j] == 'S') {
                    start.x = i;
                    start.y = j;
                }
            }
        }
        dfs(start);

        if (flag == 2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
