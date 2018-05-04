#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-04
 *  @Time: 10:46
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
#define maxn 100
#define maxm 20005
lli l, m, k, n, r, q;
lli st[maxn][maxn];
char temp[maxn];
lli dp[maxn][maxn];

void pre() {
    loop(i, 1, n) {
        loop(j, i, n) {
            lli num = 0;
            loop(kk, i, j) {
                num = num * 10 + (temp[kk] - '1' + 1);
            }
            st[i][j] = num;
        }
    }
}

int main() {
    cin >> n >> m;
    loop(i, 1, n) {
        cin >> temp[i];
    }
    pre();
    mset(dp, 0);
    loop(i, 1, n) {
        dp[0][i] = st[1][i];
    }
    loop(i, 1, m) {
        loop(j, i, n) {
            loop(kk, i, j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][kk] * st[kk + 1][j]);
            }
        }
    }
    cout << dp[m][n];
    return 0;
}

 