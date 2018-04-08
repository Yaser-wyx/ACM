#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-27
 *  @Time: 11:30
 *  To change this template use File | Settings | File Templates.
 *  欧几里得算法
 *  公式：gcd(a,b) = gcd(b,a%b)
 */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);

}