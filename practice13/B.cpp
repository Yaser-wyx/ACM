#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-16
 *  @Time: 21:30
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 10000000
long long lucky[maxn];
int n;
int temp[10];
int x = 0;

void find1(int index) {
    if (index == n) {
        long num = 0;
        for (int i = 0; i < n; i++) {
            num = num * 10 + temp[i];
        }
        lucky[x++] = num;
        return;
    }
    for (int i = 4; i <= 7; i += 3) {
        temp[index] = i;
        find1(index + 1);
    }

}

int B() {
    for (int i = 1; i <= 10; i++) {
        n = i;
        find1(0);
    }
    int l, r;
    scanf("%d%d", &l, &r);
    auto index = lower_bound(lucky, lucky + x, l);
    long long int ans = 0;
    for (int i = l; i <= r; i++) {
        if (*index > r) {
            ans += (r - i + 1) * (*index);
            break;
        }
        ans += (*index - i + 1) * (*index);
        i = *index;
        index++;
    }
    printf("%lld\n", ans);
    return 0;
}