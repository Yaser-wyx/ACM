#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-15
 *  @Time: 22:12
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
#define maxn 200000
#define maxn2 1005
int n, m, s;

struct union_find {
    int fa[maxn];
    int rk[maxn];

    union_find(int n, int s) {
        for (int i = 1; i <= n; i++, s++) {
            fa[i] = s;
            rk[i] = 0;
        }
    }

    int find(int v) {
        return fa[v] == v ? fa[v] : fa[v] = find(fa[v]);
    }

    void union2(int v, int u) {//不带高度的并查集
        fa[find(v)] = find(u);
    }
};


int P2024() {
    cin >> n >> m;
    //A 吃 B，B,吃 C，C 吃 A。
    union_find animans(3 * n, 1);
    int q, v, u;
    int ans = 0;
    loop(i, 1, m) {
        cin >> q >> v >> u;
        if (u > n || v > n) {
            //当前的话中 X 或 Y 比 N 大，就是假话
            ans++;
            continue;
        }
        if (q == 1) {
            //同类
            if (animans.find(v + n) == animans.find(u) || animans.find(v + 2 * n) == animans.find(u)) {//v是u的猎物||u是v的天敌
                ans++;
            } else {
                animans.union2(v, u);
                animans.union2(v + n, u + n);
                animans.union2(v + 2 * n, u + 2 * n);
            }
        } else {
            //v吃u
            if (u == v) {
                ans++;
            } else {
                if (animans.find(v) == animans.find(u) || animans.find(v + 2 * n) == animans.find(u)) {
                    ans++;
                } else {
                    //v的同类是u的天敌，v的猎物是u的同类，v的天敌是u的猎物
                    animans.union2(v, u + 2 * n);
                    animans.union2(v + n, u);
                    animans.union2(v + 2 * n, u + n);
                }
            }
        }
    }
    cout << ans;
    return 0;
}

 