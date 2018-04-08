#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-10
 *  @Time: 21:23
 *  To change this template use File | Settings | File Templates.
 * 
 */

using namespace std;

typedef long long lli;
#define maxn 100010
#define mod 998244353

lli fac[maxn];//阶乘
lli inv[maxn];//逆元

lli qpow(lli x, lli n) {//快速幂运算
    x %= mod;
    lli res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

void init() {//初始化阶乘与逆元
    memset(fac, 0, sizeof(fac));
    memset(inv, 0, sizeof(inv));
    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = qpow(fac[i], mod - 2) % mod;//费马小定理
    }
}

lli c(lli n, lli m) {//组合数计算
    if (n < 0 || m < 0) return 0;
    if (m > n) return 0;
    return ((fac[n] * inv[m]) % mod * inv[n - m]) % mod;
}

int main() {
    int T;
    scanf("%d", &T);
    init();
    while (T--) {
        lli a, b, n, m;
        scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
        lli ans = 1ll * c(n - 1, m - 1) * qpow(a, n - m) % mod * qpow(b, m - 1) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}