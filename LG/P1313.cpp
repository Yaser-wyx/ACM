#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-10
 *  @Time: 22:15
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
#define Mod 10007
int a, b, k, n, m;
int cnt[1000005];
int x[maxn];

lli qp(lli a, lli k) {
    lli ans = 1, base = a;
    while (k) {
        {
            if (k & 1) {
                ans = (ans % Mod * base % Mod) % Mod;
            }
            base = (base % Mod * base % Mod) % Mod;
            k >>= 1;
        }
    }
    return ans % Mod;
}

lli feima(lli a, lli b) {
    lli ans = (a % Mod * qp(b, Mod - 2) % Mod) % Mod;
}


inline lli fac(int x) {//阶乘计算
    lli ans = 1;
    if (x == 0) {
        return ans;
    }
    loop(i, 2, x) {
        ans = (ans * i) % Mod;
    }
    return ans % Mod;
}

lli caculate(int m) {//组合数计算
    //系数计算
    //C(n,m)=n!/[m!(n-m)!]
    lli a = fac(k);
    lli b = fac(m) * fac(k - m);
    return feima(a, b);
}

int P1313() {

    cin >> a >> b >> k >> n >> m;
    lli ans = (caculate(m) % Mod) * qp(a, n) % Mod * qp(b, m) % Mod;
    cout << ans % Mod;
    return 0;
}