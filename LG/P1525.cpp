#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-17
 *  @Time: 16:29
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define mid (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 50005
#define maxn2 100005
lli n, p, m, k;
int fa[maxn];
int ans;

struct edge {
    int u;
    int v;
    int w;

    bool operator<(const edge &rhs) const {
        return w > rhs.w;
    }
} edges[maxn2];

void init(int n) {
    loop(i, 1, n)fa[i] = i;
}

int find(int v) {
    return fa[v] == v ? fa[v] : fa[v] = find(fa[v]);
}

void un(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x != y) {
        fa[x] = y;
    }
}

int P1525() {
    cin >> n >> m;
    init(n << 1 | 1);
    loop(i, 1, m) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges + 1, edges + m + 1);
    loop(i, 1, m) {
        int u = edges[i].u;
        int v = edges[i].v;
        int fv = find(v);
        int fu = find(u);
        if (fu == fv) {
            cout << edges[i].w;
            return 0;
        }
        un(v, u + n);
        un(u, v + n);
    }
    cout << 0;
    return 0;
}

