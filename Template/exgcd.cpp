#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-08
 *  @Time: 20:54
 *  To change this template use File | Settings | File Templates.
 *  扩展欧几里得
 */
lli exgcd(lli a, lli b, lli &x, lli &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        lli r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }

}