#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-30
 *  @Time: 12:40
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
#define maxn 50005
#define maxm 20005
lli l, m, k, n, minn, maxx, r, q;
int ans[maxn];

int P1338() {
    mset(ans, 0);
    cin >> n >> m;
    int st = 0;
    int ed = n - 1;
    loop(i, 1, n) {
        lli temp = (n - i - 1) * (n - i) / 2;
        if (m <= temp) {
            ans[st++] = i;
        } else {
            ans[ed--] = i;
            m -= (ed - st + 1);
        }
    }
    loop3(i, 0, n) {
        cout << ans[i]<<" ";
    }
    return 0;
}