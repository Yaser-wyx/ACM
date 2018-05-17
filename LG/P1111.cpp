#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-15
 *  @Time: 16:18
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
#define maxn 100005
#define maxn2 1005
int n, m, s;
int fa[maxn];

void init(int n) {
    loop(i, 1, n)fa[i] = i;
}

int find(int v) {
    return fa[v] == v ? fa[v] : fa[v] = find(fa[v]);
}

int union1(int u, int v) {
    fa[find(u)] = find(v);
}

struct node {
    int u;
    int v;
    int time;

    bool operator<(const node &rhs) const {
        return time < rhs.time;
    }
} nodes[maxn];

int P1111() {
    cin >> n >> m;
    loop3(i, 0, m) {
        cin >> nodes[i].u >> nodes[i].v >> nodes[i].time;
    }
    sort(nodes, nodes + m);
    init(n);
    int ans = 0;
    loop(i, 0, m) {
        int u = find(nodes[i].u);
        int v = find(nodes[i].v);
        if (u == v) {
            continue;
        }
        union1(u, v);
        ans = max(ans, nodes[i].time);
    }
    int u = find(1);
    loop(i, 2, n) {
        int v = find(i);
        if (u != v) {
            ans = -1;
            break;
        }
    }
    cout << ans;
    return 0;
}
