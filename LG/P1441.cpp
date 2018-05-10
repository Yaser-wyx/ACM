#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-08
 *  @Time: 16:39
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
#define maxn 30
int n, m;
int weights[maxn];//砝码重量
bool vis[maxn];//砝码是否被丢弃
int ans = 0;

void dp() {
    int temp[maxn];//存放可用的砝码
    int index = 0;
    mset(temp, 0);
    loop3(i, 0, n) {
        if (!vis[i]) {
            temp[index++] = weights[i];
        }
    }
    int nn = 2005;//最大的砝码和
    bool dp[nn];
    mset(dp, 0);
    dp[0] = 1;//砝码值为0也是一种情况
    loop3(i, 0, index) {//01背包，即是否选择该砝码
        loop2(v, nn, temp[i]) {
            dp[v] = dp[v] || dp[v - temp[i]];
        }
    }
    int cnt = 0;
    loop3(i, 1, nn) {//统计可以到达的不同砝码值
        if (dp[i]) {
            cnt++;
        }
    }
    ans = max(cnt, ans);
}

void dfs(int index, int next) {
    if (index == m) {//随机去掉m个砝码后
        dp();
        return;
    }
    loop3(i, next, n) {
        if (!vis[i]) {
            vis[i] = 1;//标记
            dfs(index + 1, i + 1);
            vis[i] = 0;//清除标记
        }
    }

}

int P1441() {
    cin >> n >> m;
    loop3(i, 0, n) {
        cin >> weights[i];
    }
    mset(vis, 0);
    sort(weights, weights + n);//玄学优化
    dfs(0, 0);
    cout << ans;
    return 0;
}