#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-12
 *  @Time: 14:56
 *  To change this template use File | Settings | File Templates.
 * 
 */#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 200010
using namespace std;
int n, m;
int head[maxn];
int cnt = 0;
int color[maxn];
bool vis[maxn];
int pre[2];
struct edge {
    int next;
    int to;
} edges[maxn];

void add(int a, int b) {
    cnt++;
    edges[cnt].to = b;
    edges[cnt].next = head[a];
    head[a] = cnt;//更新以a为起点 的边的位置
}

bool dfs(int node, int flag) {
    if (vis[node]) {//是否访问过
        if (color[node] != flag) {//与之前颜色不一致
            return 0;
        } else {//颜色一致
            return 1;
        }
    }
    vis[node] = 1;//设置为已访问
    pre[(color[node] = flag) == 1 ? 1 : 0]++;//颜色计数器
    bool tf = 1;//标记是否可行
    for (int i = head[node]; i != -1 && tf; i = edges[i].next) {//链式前向星的遍历
        tf = tf && dfs(edges[i].to, 0 - flag);
    }

    return tf;
}

int P1330() {
    mset(head, -1);
    scanf("%d%d", &n, &m);
    int a, b;
    while (m--) {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);//无向图
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {//对每一个节点进行遍历访问
        if (vis[i]) {
            continue;//已经访问过了
        }
        mset(pre, 0);
        if (!dfs(i, 1)) {//不是二分图
            printf("Impossible\n");
            return 0;
        }
        ans += min(pre[0], pre[1]);//选取较小的染色方案

    }
    printf("%d\n", ans);
    return 0;
}