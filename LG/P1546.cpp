#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-15
 *  @Time: 10:40
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
#define maxn 10500
int n, m, s;
int fa[150];
int cnt = 0;
int ans = 0;
struct edge {
    int u;
    int v;
    int w;
} edges[maxn];

void init() {
    loop(i, 1, n)fa[i] = i;
}

int find(int v) {
    return fa[v] == v ? fa[v] : fa[v] = find(fa[v]);
}

void union1(int u, int v) {
    fa[find(u)] = find(v);
}

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

void kruskal() {
    sort(edges, edges + cnt, cmp);
    int ct = 0;
    loop3(i, 0, cnt) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (u == v) {
            continue;
        }
        ct++;
        union1(u, v);
        ans += edges[i].w;
        if (ct == n - 1) {
            break;
        }
    }
}

int P1546() {
    cin >> n;
    int temp;
    loop(i, 1, n) {
        loop(j, 1, n) {
            cin >> temp;
            if (j <= i) {
                continue;//只读取一半的图
            }
            edges[cnt].w = temp;
            edges[cnt].u = i;
            edges[cnt++].v = j;
        }
    }
    init();
    kruskal();
    cout << ans;
    return 0;
}
