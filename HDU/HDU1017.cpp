#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-26
 *  @Time: 22:31
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU1017() {
    int n, m;
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int Case = 1;
        while (~scanf("%d %d", &n, &m)) {
            if (n + m == 0) {
                break;
            }
            int pairs = 0;
            for (int a = 1; a < n; a++) {
                for (int b = a + 1; b < n; b++) {
                    if ((a * a + b * b + m) % (a * b) == 0) {
                        pairs++;
                    }
                }
            }
            printf("Case %d: %d\n", Case, pairs);
            Case++;
        }
        if (i != N - 1) {
            printf("\n");
        }
    }

    return 0;
}