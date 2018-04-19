#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-18
 *  @Time: 20:57
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 55
int t, n;
struct food {
    lli a;
    lli b;
    lli c;
} foods[maxn];

bool cmp(food a, food b) {
    return a.c * b.b < a.b * b.c;
}

int P1417() {
    lli dp[100010];
    mset(dp, 0);
    scanf("%d%d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lli", &foods[i].a);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lli", &foods[i].b);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lli", &foods[i].c);
    }
    sort(foods, foods + n, cmp);
    lli ans = 0;
    for (int i = 0; i < n; i++) {
        for (int v = t; v >= foods[i].c; v--) {
            dp[v] = max(dp[v], dp[v - foods[i].c] + foods[i].a - v * foods[i].b);
            ans = max(ans, dp[v]);
        }
    }
    printf("%lli\n", ans);
    return 0;
}
