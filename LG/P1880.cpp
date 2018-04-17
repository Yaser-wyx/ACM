#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-17
 *  @Time: 16:51
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 300
int n, m;
int stones[maxn];
int pre[maxn];
int mn[maxn][maxn];
int mx[maxn][maxn];

int P1880() {
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++) {
        scanf("%d", &stones[i]);
        stones[i + n] = stones[i];//断环为链
    }
    for (register int i = 1; i <= (n << 1); i++) {
        pre[i] = pre[i - 1] + stones[i];//前缀和
    }
    register int r;
    for (register int len = 2; len <= n; len++) {
        for (register int l = 1; l <= (n << 1) - len + 1; l++) {
            r = l + len - 1;
            mn[l][r] = 99999;
            mx[l][r] = 0;
            for (register int k = l; k < r; k++) {//枚举节点
                mn[l][r] = min(mn[l][r], mn[l][k] + mn[k + 1][r] + pre[r] - pre[l - 1]);
                mx[l][r] = max(mx[l][r], mx[l][k] + mx[k + 1][r] + pre[r] - pre[l - 1]);
            }
        }
    }
    register int ans1 = 99999;
    register int ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 = min(ans1, mn[i][i + n - 1]);
        ans2 = max(ans2, mx[i][i + n - 1]);
    }
    printf("%d\n%d", ans1, ans2);
    return 0;
}
