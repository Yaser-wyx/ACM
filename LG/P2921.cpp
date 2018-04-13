#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-13
 *  @Time: 11:07
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 100010
using namespace std;
int n, m;
int dfn[maxn];
int low[maxn];
int stack1[maxn];
int dfn_index = 0;
int top = 0;
bool in_stack[maxn];
int scc = 0;//强连通分量标记
int flag[maxn];//连通分量标记
int sz[maxn];
int cnt = 0;
int head[maxn];
int ans = 0;
int dp[maxn];
int nxt[maxn];
struct edge {//链式前向星存图
    int to;
    int next;
} edges[maxn];

void add(int a, int b) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].next = head[a];
    head[a] = cnt;
}

void tarjan(int u) {//使用tarjan缩环为点
    dfn[u] = low[u] = ++dfn_index;
    in_stack[u] = 1;
    stack1[top++] = u;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(dfn[v], low[u]);
        }
    }

    if (dfn[u] == low[u]) {
        scc++;
        int v;
        do {
            v = stack1[--top];
            in_stack[v] = 0;
            flag[v] = scc;
            sz[scc]++;
        } while (v != u);
    }
}

int dfs(int index) {
    if (!index || dp[index]) {
        return dp[index];
    }
    return dp[index] = dfs(nxt[index]) + sz[index];
}

int P2921() {
    mset(head, -1);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        add(i, temp);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        int next = edges[head[i]].to;
        if (flag[i] != flag[next]) {//不在同一个连通分量中
            nxt[flag[i]] = flag[next];//使用连通分量重构图
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = dfs(flag[i]);
        printf("%d\n", ans);
    }
    return 0;
}
 
 