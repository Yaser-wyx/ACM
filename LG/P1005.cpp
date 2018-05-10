#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef __int128 big;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-09
 *  @Time: 21:29
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
#define maxn 88
int n, m;
int matrix[maxn];
big pre[maxn];
big ans = 0;

void dp() {
    big dp[maxn][maxn];
    loop(i, 1, m) {
        loop2(j, m, i) {
            dp[i][j] = max(dp[i - 1][j] + pre[m - j + i - 1] * matrix[i - 1],
                           dp[i][j + 1] + pre[m - j + i - 1] * matrix[j + 1]);
        }
    }
    big temp = 0;
    loop(i, 1, m) {
        temp = max(temp, dp[i][i] + pre[m] * matrix[i]);
    }
    ans += temp;
}

inline void putint(big arg) {
    if (!arg) {
        puts("0");
        return;
    }
    static char str[50], *now;
    now = str;
    while (arg) {
        *now++ = arg % 10 + '0',
                arg /= 10;
    }
    now--;
    while (now >= str)
        putchar(*now--);
    putchar('\n');
}

int P1005() {
    cin >> n >> m;
    pre[0] = 1;
    loop(i, 1, m) {
        pre[i] = pre[i - 1] * 2;
    }
    loop(i, 1, n) {
        loop(j, 1, m) {
            cin >> matrix[j];
        }
        dp();
    }
    putint(ans);

    return 0;
}