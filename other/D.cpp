#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 14:39
 *  To change this template use File | Settings | File Templates.
 * 
 */
#include <stdio.h>

int pw(int x, int y, int p) {
    if (!y) {
        return 1;
    }
    int res = pw(x*x, y >> 1, p);
    if (y & 1) {
        res = res * x % p;
    }
    return res;
}


int D() {
    int x, y, p;
    scanf("%d%d%d", &x, &y,&p);
    printf("%d\n", pw(x, y,p));
    return 0;
}
