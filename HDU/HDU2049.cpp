#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-16
 *  @Time: 11:29
 *  To change this template use File | Settings | File Templates.
 * 
 */

typedef long long int lli;
#define maxn 22
int n;
lli nums[maxn];

void form() {
    nums[1] = 0;
    nums[2] = 1;

    lli N = 2;
    for (int i = 3; i < maxn; i++) {
        N *= i;
        nums[i] = (i - 1) * (nums[i - 1] + nums[i - 2]);
    }
}

lli caculate(int n, int m) {
    //组合公式：C(n m)=A(n m)/m!=n!/[m!*(n-m)!]
    if (n == m || m == 0) {
        return 1;
    }
    lli ans = 1;
    lli temp_m = 1;
    lli temp_mn = 1;
    int nm = n - m;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        if (i == m) {
            temp_m = ans;
        }
        if (i == nm) {
            temp_mn = ans;

        }
    }
    ans = ans / (temp_m * temp_mn);
    return ans;
}

int HDU2049() {
    scanf("%d", &n);
    form();
    while (n--) {
        int n, m;
        scanf("%d%d", &n, &m);
        lli res = caculate(n, n - m);
        res *= nums[m];
        printf("%lld\n", res);
    }
    return 0;
}