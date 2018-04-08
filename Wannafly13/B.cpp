#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-08
 *  @Time: 08:43
 *  To change this template use File | Settings | File Templates.
 * 
 */
typedef long long int lli;
#define mod 998244353
#define in freopen("F:\\ACM\\data.in","r",stdin);
int a, b;
lli qp(int a, int k) {
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

int main() {
    in;
    int n, m;
    scanf("%d%d", &n, &m);
    a = m;
    b = n * n;
    a = b - a;
    lli ans = qp(b, mod - 2);
    ans = (ans % mod * a % mod) % mod;
    printf("%lli\n", ans);
    return 0;
}