#include <bits/stdc++.h>

#define INF 0xfffffff

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-04
 *  @Time: 09:02
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
int st[10][10];
int temp[10];
int dp[maxn][maxn];

void pre() {//预处理
    loop(i, 1, n) {
        loop(j, i, n) {
            int num = 0;
            loop(k, i, j) {
                num = num * 10 + temp[k];
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
    loop(i, 1, m) {
        loop(j, 1, n) {
            dp[i][j] = INF;
        }
    }
    loop(i, 1, n) {
        dp[0][i] = st[1][i];
    }
    loop(i, 1, m) {//几个加号
        loop(j, i, n) {//前j个数
            loop(k, i, j) {//最后一个加号的位置
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + st[k + 1][j]);
            }
        }
    }
    cout << dp[m][n];
    return 0;
}

 