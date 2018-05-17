#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-16
 *  @Time: 11:35
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 200005
#define maxn2 400005
int n, m, s, k;
int fa[maxn2];
int rk[maxn2];
int head[maxn2];
int cnt = 0;
int destory[maxn2];
int vis[maxn2];
int nums;
struct edge {
    int to;
    int next;
    int flag = 0;
} edges[maxn2];

void add(int from, int to) {
    cnt++;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}

void init(int n) {
    mset(head, -1);
    mset(destory, 0);
    mset(vis, 0);
    loop(i, 0, n) {
        fa[i] = i;
        rk[i] = 0;
    }
}

int find(int v) {
    return fa[v] == v ? fa[v] : fa[v] = find(fa[v]);
}

void union2(int u, int v) {//带高度的并查集
    int x = find(u);
    int y = find(v);
    if (x == y)return;
    nums--;//联通块数减少
    if (rk[x] > rk[y]) {
        fa[y] = x;
    } else {
        fa[x] = y;
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}

int P1197() {
    cin >> n >> m;

    init(n);
    int u, v;
    loop(i, 1, m) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    cin >> k;
    int ans[k + 1];
    int temp;
    nums = n - k;
    loop(i, 1, k) {
        cin >> temp;
        destory[i] = temp;//第几次摧毁哪一颗星球
        vis[temp] = i;//是否被摧毁,该星球第几次被摧毁
    }
    loop(i, 1, n) {
        if (!vis[i]) {
            //将所有没有被摧毁的连接起来
            for (int j = head[i]; j != -1; j = edges[j].next) {
                int to = edges[j].to;
                if (!vis[to]) {
                    union2(i, to);
                }
            }
        }
    }
    ans[k] = nums;
    loop2(d, k, 1) {
        nums++;//修复一个点
        for (int j = head[destory[d]]; j != -1; j = edges[j].next) {
            int to = edges[j].to;
            if (vis[to] >= d || !vis[to]) {
                union2(destory[d], to);
            }

        }
        ans[d - 1] = nums;
    }
    loop(i, 0, k) {
        cout << ans[i] << endl;
    }
    return 0;
}

 