#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-26
 *  @Time: 10:55
 *  To change this template use File | Settings | File Templates.
 * 
 */
int p3() {

    for (int i = 1; i <= 200; i++) {
        int sum = 0;
        for (int j = i; j <= 200; j++) {
            sum += j;
            if (sum == 236) {
                printf("%d", i);
                return 0;
            }
        }
    }
    return 0;
}