#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 13:37
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define loop5(a, b, c, d) for(int a=b;a<=c;a++)if(d)break;
#define maxn 2005
#define maxm 20
int n, m, k;
char words[maxn][80];
int dp[maxn];

bool judge(char c[], char c2[]) {
    int len = strlen(c);
    loop3(i, 0, len) {
        if (c[i] != c2[i]) {
            return 0;
        }
    }
    return 1;
}

int P1481() {
    scanf("%d", &n);
    loop(i, 1, n) {
        cin >> words[i];
    }
    mset(dp, 0);
    int ans = 0;
    loop(i, 1, n) {
        loop3(j, 1, i) {
            if (judge(words[j], words[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans + 1);
    return 0;
}