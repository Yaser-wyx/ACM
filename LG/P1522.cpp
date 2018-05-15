#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-15
 *  @Time: 09:26
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
#define maxn 200
int n, m, s;
double dis[maxn][maxn];
struct node {
    int x;
    int y;
} nodes[maxn];

inline double distance(int v, int u) {
    return sqrt((nodes[v].x - nodes[u].x) * (nodes[v].x - nodes[u].x) +
                (nodes[v].y - nodes[u].y) * (nodes[v].y - nodes[u].y));

}

int P1522() {
    double f[maxn];

    cin >> n;
    loop(i, 1, n) {
        cin >> nodes[i].x >> nodes[i].y;
    }
    char connect;
    loop(i, 1, n) {
        loop(j, 1, n) {
            cin >> connect;
            if (i == j) {
                dis[i][j] = 0;
            } else
                dis[i][j] = INF;
            if (connect == '1') {
                dis[i][j] = distance(i, j);
            }
        }
    }

    loop(k, 1, n) {
        loop(i, 1, n) {
            loop(j, 1, n) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    double temp = 0;
    double ans = 0;
    double maxx = INF;
    mset(f, 0);
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (dis[i][j] != INF) {
                f[i] = max(f[i], dis[i][j]);
                temp = max(temp, f[i]);
            }
        }
    }
    loop(i, 1, n) {
        loop(j, 1, n) {
            if (dis[i][j] == INF) {
                maxx = min(maxx, f[i] + f[j] + distance(i, j));
            }
        }
    }
    ans = max(maxx, temp);
    printf("%.6f", ans);
    return 0;
}

 