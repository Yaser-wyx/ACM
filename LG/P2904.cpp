#include <bits/stdc++.h>

#define INF 0xfffffff
using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-26
 *  @Time: 09:33
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 2550
#define maxm 10005
int n, m, t;
int pre[maxn];//i头奶牛过河的时间
int dp[maxn];//前i头牛过河所需要的最小时间

int P2904() {
    scanf("%d%d", &n, &m);
    pre[0] = m * 2;//没有奶牛的时间
    loop(i, 1, n) {
        scanf("%d", &t);
        pre[i] = pre[i - 1] + t;
    }

    loop(i, 0, n) {
        dp[i] = INF;
    }
    dp[0] = 0;
    loop(i, 1, n) {
        loop(j, i, n) {
            dp[j] = min(dp[j], dp[j - i] + pre[i]);
        }
    }
    printf("%d\n", dp[n] - m);//最后一趟不需要返回
    return 0;
}
