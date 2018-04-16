#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-15
 *  @Time: 11:17
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 1000010
#define INF 2000000000
#define mod 100003
int n, m;
int dis[maxn];
queue<int> queue1;
bool vis[maxn];
int ans[maxn];
vector<int> vector1[maxn];

void SPFA() {
    for (int i = 0; i <= n; i++) {
        dis[i] = INF;
    }
    mset(vis, 0);
    dis[1] = 0;
    queue1.push(1);
    vis[1] = 1;
    ans[1] = 1;
    while (!queue1.empty()) {
        int now = queue1.front();
        queue1.pop();
        vis[now] = 0;
        for (int i = 0; i < vector1[now].size(); i++) {
            int v = vector1[now][i];
            int temp = dis[now] + 1;
            if (temp == dis[v]) {
                ans[v] = (ans[v] + ans[now]) % mod;
            } else if (temp < dis[v]) {
                ans[v] = ans[now];
                dis[v] = temp;
                if (!vis[v]) {
                    queue1.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

}

int P1144() {

    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        vector1[u].push_back(v);
        vector1[v].push_back(u);
    }
    mset(ans, 0);
    SPFA();
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;

}