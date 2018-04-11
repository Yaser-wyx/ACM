#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-27
 *  @Time: 15:41
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define PI 3.141592654
#define e 2.71828182

int HDU1018() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        double w;
        w = 1.0 / 2.0 * (log10(2 * PI * num)) + num * log10(num / e) + 1;
        printf("%d\n", (int) w);
    }

    return 0;
}