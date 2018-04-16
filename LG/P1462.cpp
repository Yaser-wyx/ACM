#include <bits/stdc++.h>

typedef long long int lli;
using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-14
 *  @Time: 11:21
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 50010
#define INF 1000000100
int n, m, b, cnt = 0;
lli f[maxn >> 2];
int head[maxn << 1];
int blood[maxn >> 2];
bool vis[maxn >> 2];
queue<int> queue1;
struct edge {
    int to;
    int next;
    int w;
} edges[maxn << 1];

void add(lli a, lli b, lli w) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].w = w;
    edges[cnt].next = head[a];
    head[a] = cnt;
}

bool relax(int u, int index) {//松弛操作
    int temp = blood[u] + edges[index].w;
    int v = edges[index].to;
    if (temp < blood[v]) {
        blood[v] = temp;
        return true;
    }
    return false;
}

bool spfa(lli x) {
    mset(vis, 0);
    for (int i = 0; i <= n; i++) {
        blood[i] = INF;
    }
    queue1.push(1);
    blood[1] = 0;
    vis[1] = 1;
    while (!queue1.empty()) {
        int now = queue1.front();
        queue1.pop();
        vis[now] = 0;//出栈，标记清除
        for (int i = head[now]; i != -1; i = edges[i].next) {//遍历该点周围的节点,i为邻边
            int v = edges[i].to;
            if (relax(now, i) && !vis[v] && f[v] <= x) {//如果可以进行松弛操作，且当前节点的花费小于x
                //入栈
                queue1.push(v);
                vis[v] = 1;
            }
        }
    }
    if (blood[n] >= b) {//如果走完后耗血量大于自身的血量，则无法到达
        return 0;
    }
    return 1;
}

int P1462() {
    mset(head, -1);
    lli l, r;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        r = max(r, f[i]);
    }
    lli ai, bi, ci;
    for (int i = 0; i < m; i++) {

        cin >> ai >> bi >> ci;
        if (ai == bi) {
            continue;
        }
        add(ai, bi, ci);
        add(bi, ai, ci);
    }
    if (!spfa(INF)) {//先判断能否走到终点
        printf("AFK\n");
        return 0;
    }
    //二分枚举
    l = max(f[1], f[n]);
    while (l <= r) {
        lli mid = (l + r) >> 1;
        if (spfa(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%lli\n", l);
    return 0;
}