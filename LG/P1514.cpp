#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-09
 *  @Time: 09:20
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define INF 0xfffffff

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 505
int n, m;
int matrix[maxn][maxn];
int vis[maxn][maxn];
int cnt = 0;
int leave;
int mv[4][2] = {{1,  0},
                {0,  1},
                {-1, 0},
                {0,  -1}};

struct node {
    int left = INF;
    int right = -1;

    bool operator<(const node &rhs) const {
        if (left < rhs.left)
            return true;
        if (rhs.left < left)
            return false;
        return right < rhs.right;
    }
} nodes[maxn];

int l[maxn][maxn];
int r[maxn][maxn];

void dfs(int x, int y, int flag) {//DFS求解每一个蓄水池可以满足哪一段区间的城市
    vis[x][y] = 1;
    loop3(i, 0, 4) {
        int new_x = x + mv[i][0];
        int new_y = y + mv[i][1];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
            if (matrix[new_x][new_y] >= matrix[x][y]) {
                continue;
            }
            if (!vis[new_x][new_y]) {
                //没有标记过
                //地势低
                dfs(new_x, new_y, flag);

            }
            l[x][y] = min(l[x][y], l[new_x][new_y]);//更新数据
            r[x][y] = max(r[x][y], r[new_x][new_y]);

        }
    }
}

int P1514() {
    cin >> n >> m;
    mset(matrix, 0);
    loop3(i, 0, n) {
        loop3(j, 0, m) {
            cin >> matrix[i][j];
        }
    }
    mset(l, 1);
    mset(r, 0);
    loop(i, 0, m) {
        l[n - 1][i] = r[n - 1][i] = i;
    }
    mset(vis, 0);
    loop3(i, 0, m) {
        dfs(0, i, i);
        if (l[0][i] > r[0][i]) {
            continue;
        }
        nodes[i].left = l[0][i];
        nodes[i].right = r[0][i];
    }
    int cnt = 0;
    loop3(i, 0, m) {//判断是否所有城市都有水
        if (!vis[n - 1][i]) {
            cnt++;
        }
    }
    if (cnt) {
        cout << 0 << endl << cnt << endl;
        return 0;
    }
    sort(nodes, nodes + m);//区间覆盖，贪心策略
    int now = 0;
    loop3(i, 0, m) {
        if (nodes[i].left == 0) {//选择起点
            now = i;
        } else {
            break;
        }
    }
    int next = 0;
    cnt = 1;
    for (;;) {
        for (int j = now + 1; j < m; j++) {
            if (nodes[j].left - 1 <= nodes[now].right) {
                next = j;
            } else {
                break;
            }
        }
        now = next;
        cnt++;
        if (nodes[now].right == m - 1) {
            break;
        }
    }
    cout << 1 << endl << cnt << endl;
    return 0;
}