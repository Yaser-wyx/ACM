#include <bits/stdc++.h>
#define INF 0xfffffff

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-23
 *  @Time: 17:23
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 1010
#define maxm 20
int n, m, t;
pair<double, double> nodes[maxm];
double dis[maxm][maxm];
bool vis[maxm];
double ans = INF;

inline double distance(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

void dfs(int nxt, int index, double now_dis) {
    if (index == n) {
        ans = min(now_dis, ans);
        return;
    }
    if (now_dis > ans) {
        return;
    }
    loop(i, 0, n) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i, index + 1, now_dis + dis[nxt][i]);
            vis[i] = 0;
        }
    }
}

int P1433() {
    mset(vis, 0);
    scanf("%d", &n);
    nodes[0].first = 0;
    nodes[0].second = 0;
    loop(i, 1, n) {
        scanf("%lf%lf", &nodes[i].first, &nodes[i].second);
    }
    loop(i, 0, n) {
        loop(j, 0, n) {
            dis[i][j] = distance(nodes[i], nodes[j]);
        }
    }
    vis[0] = 1;
    dfs(0, 0, 0);
    printf("%.2lf\n", ans);
    return 0;
}