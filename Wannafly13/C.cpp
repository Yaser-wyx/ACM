#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-07
 *  @Time: 11:07
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mod 998244353
typedef long long int lli;

int n;

lli cal() {
    lli cnt = 1;
    for (int i = 2; i <= n; i++) {
        cnt *= i % mod;
    }
    return cnt;
}

int C() {
    scanf("%d", &n);
    lli temp = cal();

    lli ans = temp % mod * temp % mod * 2;
    printf("%lli\n", ans);
    return 0;
}