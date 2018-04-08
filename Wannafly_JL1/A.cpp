#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-02
 *  @Time: 19:53
 *  To change this template use File | Settings | File Templates.
 * 
 */

int main() {
    int T;
    double p, q;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf", &p, &q);
        double temp = p / q;
        double x = floor(temp);
        if (temp == x) {
            x--;
            printf("%.0lf\n", x);
        } else {
            printf("%.0f\n", x);
        }

    }

    return 0;
}