#include <bits/stdc++.h>
#define maxn 10010

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 17:03
 *  To change this template use File | Settings | File Templates.
 * 
 */
int n;
long pre[maxn];

int I() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%li", &pre[i]);
    }
    sort(pre, pre + n);
    long dis[maxn];
    for (int i = 1; i < n; i++) {
        dis[i] = pre[i] - pre[i - 1];
    }

    sort(dis + 1, dis + n);
    long ans = 1;
    bool flag = true;
    long i;
    for (i = dis[1]; i >= 2; i--) {
        if (dis[1] % i == 0) {
            int cnt = 0;
            flag = true;
            for (int j = 1; j < n; j++) {
                if (dis[j] % i != 0) {
                    cnt++;
                }
                if (cnt >= 2) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
    }

    if (flag) {
        ans = max(ans, i);
    }
    for (i = dis[2]; i >= 2; i--) {
        if (dis[2] % i == 0) {
            int cnt = 0;
            flag = true;
            for (int j = 1; j < n; j++) {
                if (dis[j] % i != 0) {
                    cnt++;
                }
                if (cnt >= 2) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
    }

    if (flag) {
        ans = max(ans, i);
    }
    int res = 0;
    if (ans == 1) {
        for (int j = 1; j < n - 1; j++) {
            if (dis[j] % ans == 0) {
                res += (dis[j] / ans) - 1;
            }
        }
    } else {
        for (int j = 1; j < n; j++) {
            if (dis[j] % ans == 0) {
                res += (dis[j] / ans) - 1;
            }
        }
    }
    printf("%d\n", res);

    return 0;
}
