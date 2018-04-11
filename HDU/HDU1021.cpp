#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-27
 *  @Time: 16:39
 *  To change this template use File | Settings | File Templates.
 * 
 */
namespace hdu1021 {
#define maxn 1000010
    int fib[maxn];
    void Fibonacci() {
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < maxn; i++) {
            fib[i] = (fib[i - 1] + fib[i - 2]) % 3;
        }
    }
}
using namespace hdu1021;

int HDU1021() {

    int n;
    while (~scanf("%d", &n)) {
        if (n%4==2) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}