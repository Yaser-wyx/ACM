#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-17
 *  @Time: 17:03
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
#define maxn 4000
#define maxn2 100005
lli n, p, m, k, v, u;
int fa[maxn];

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

int P1892() {
    cin >> n >> m;
    init(n << 1 | 1);
    char cmd;
    loop(i, 1, m) {
        cin >> cmd >> u >> v;
        if (cmd == 'E') {
            un(u, v + n);
            un(v, u + n);
        } else {
            un(u, v);
        }
    }
    int ans = 0;
    bool vis[maxn];
    mset(vis, 0);
    loop(i, 1, n) {
        if (!vis[i]) {
            vis[i] = 1;
            ans++;
            loop(j, i + 1, n) {
                int fv = find(i);
                int fu = find(j);
                if (fv == fu) {
                    vis[j] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

