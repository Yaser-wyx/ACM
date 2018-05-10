#include <bits/stdc++.h>

typedef long long int lli;
#define mod 777777
using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-08
 *  @Time: 08:44
 *  To change this template use File | Settings | File Templates.
 *  求逆元模板
 */

/**逆元模板一
 * a^(p-1)≡1(mod p)
 * (a/b)%p = (a/b)%p*1= (a/b)%p*b^(p-1) =  a*b^(-1)*b^(p-1)%p=a*b^(p-2)%p
 * 费马小定理 用于除法取模运算 只可以用于mod为质数的情况
 *
 * @return
 */
lli qp(lli a, lli k) {
    lli ans = 1, base = a;
    while (k) {
        {
            if (k & 1) {
                ans = (ans % mod * base % mod) % mod;
            }
            base = (base % mod * base % mod) % mod;
            k >>= 1;
        }
    }
    return ans % mod;
}

lli feima(lli a, lli b) {
    lli ans = (a % mod * qp(b, mod - 2) % mod) % mod;
}


