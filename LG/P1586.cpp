#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 11:48
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define loop5(a, b, c, d) for(int a=b;a<=c;a++)if(d)break;
#define maxn 33000
#define maxm 20
int n, m, t;
int dp[maxn][5];

int P1586() {
    mset(dp, 0);
    dp[0][0] = 1;//初始化
    for (int i = 1; i * i <= 32768; i++) {//第i个物品，其费用为i*i
        for (int j = i * i; j <= 32768; j++) {//背包容量
            for (int k = 1; k < 5; k++) {//所使用的数的个数
                dp[j][k] += dp[j - i * i][k - 1];
            }
        }
    }
    scanf("%d", &t);
    loop(i, 1, t) {
        scanf("%d", &n);
        printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]);
    }

    return 0;
}