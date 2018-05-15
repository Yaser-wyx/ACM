#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-14
 *  @Time: 17:38
 *  To change this template use File | Settings | File Templates.
 *  并查集
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 10005
int n, m, s;
int fa[maxn];
int rk[maxn];

void init(int n) {
    loop(i, 0, n) {
        fa[i] = i;
        rk[i] = 0;
    }
}

int find(int v) {
    return fa[v] == v ? fa[v] : fa[v] = find(fa[v]);
}

void union1(int v, int u) {//不带高度的并查集
    fa[find(v)] = find(u);
}

void union2(int u, int v) {//带高度的并查集
    int x = find(u);
    int y = find(v);
    if (x == y)return;

    if (rk[x] > rk[y]) {
        fa[y] = x;
    } else {
        fa[x] = y;
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}