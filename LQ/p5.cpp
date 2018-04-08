#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-26
 *  @Time: 12:21
 *  To change this template use File | Settings | File Templates.
 * 
 */
int p5() {
    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {
            for (int c = 1; c < 100; c++) {
                if (a * a + b * b + c * c == 1000) {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}