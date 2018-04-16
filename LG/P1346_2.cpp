#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-14
 *  @Time: 17:12
 *  To change this template use File | Settings | File Templates.
 *  解法二：SPFA
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 10000
#define INF 2000000000
int n, a, b;
struct edge {
    int to;
    int w;
    int next;
} edges[maxn];
int head[maxn];
int cnt = 0;
bool vis[maxn];
priority_queue<int> queue1;
int dis[maxn];

bool relax(int u, int index) {
    int temp = dis[u] + edges[index].w;
    int to = edges[index].to;
    if (temp < dis[to]) {
        dis[to] = temp;
        return 1;
    }
    return 0;
}

bool SPFA() {
    for (int i = 0; i <= n; i++) {
        dis[i] = INF;
    }
    mset(vis, 0);
    queue1.push(a);
    dis[a] = 0;
    vis[a] = 1;
    while (!queue1.empty()) {
        int now = queue1.top();
        queue1.pop();
        vis[now] = 0;
        for (int i = head[now]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            if (relax(now, i) && !vis[v]) {
                vis[v] = 1;
                queue1.push(v);
            }
        }
    }

    return dis[b] != INF;
}

void add(int a, int b, int w) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].w = w;
    edges[cnt].next = head[a];
    head[a] = cnt;
}

int P1346() {

    scanf("%d%d%d", &n, &a, &b);
    int k, to;
    mset(head, -1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &to);

            add(i, to, j > 0 ? 1 : 0);
        }
    }
    if (SPFA()) {
        printf("%d\n", dis[b]);
    } else {
        printf("-1\n");
    }
    return 0;

}