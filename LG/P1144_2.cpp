#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-15
 *  @Time: 13:57
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
int head[maxn << 2];
int ans[maxn];
int cnt = 0;
struct edge {
    int to;
    int next;
} edges[maxn << 2];

void add(int a, int b) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].next = head[a];
    head[a] = cnt;
}

void bfs() {
    queue1.push(1);

    ans[1] = 1;
    for (int i = 0; i <= n; i++) {
        dis[i] = INF;
    }
    dis[1] = 0;
    while (!queue1.empty()) {
        int now = queue1.front();
        queue1.pop();
        for (int i = head[now]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int temp = dis[now] + 1;
            if (temp == dis[v]) {
                ans[v] = (ans[v] + ans[now]) % mod;
            } else if (temp < dis[v]) {
                dis[v] = temp;
                ans[v] = ans[now];
                queue1.push(v);
            }
        }
    }
}

int P1144() {
    scanf("%d%d", &n, &m);
    int u, v;
    mset(head, -1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    mset(ans, 0);
    bfs();
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;

}