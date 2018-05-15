#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-15
 *  @Time: 10:09
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 200005
int n, m, s;
int fa[maxn];
int ans = 0;
struct edge {
    int u;
    int v;
    int w;
} edges[maxn];

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

void init() {
    loop(i, 1, n)fa[i] = i;
}

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

void union1(int u, int v) {
    fa[find(u)] = find(v);
}

void kruskal() {
    init();
    sort(edges, edges + m, cmp);
    int cnt = 0;
    loop3(i, 0, m) {
        int v = find(edges[i].v);
        int u = find(edges[i].u);
        if (v == u)continue;
        union1(u, v);
        ans += edges[i].w;
        cnt++;
        if (cnt == n - 1)break;
    }
}
 