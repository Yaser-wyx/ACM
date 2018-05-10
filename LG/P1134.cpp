#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-10
 *  @Time: 21:51
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
#define maxn 10005
#define Mod 1000000007
int n, c;
int cnt[1000005];

int P1134() {
    cin >> n;
    lli ans = 1;
    loop(i, 1, n) {
        ans *= i;
        while (ans % 10 == 0) {
            ans /= 10;
        }
        ans %= 100000000;
    }
    while (ans % 10 == 0) {
        ans /= 10;
    }
    cout << ans % 10;
    return 0;
}