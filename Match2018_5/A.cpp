#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-26
 *  @Time: 21:57
 *  To change this template use File | Settings | File Templates.
 * 
 */

namespace match2018 {
#define maxn 100010
    int n;
    int nums[maxn];
    long long ans;

    void sort(int l, int mid, int r) {
        int len = r - l + 1;
        int temp[len];
        for (int i = 0; i < len; i++) {
            temp[i] = nums[l + i];//复制数组
        }
        int i = 0;
        int j = mid - l + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid - l) {
                nums[k] = temp[j++];
            } else if (j > r - l) {
                nums[k] = temp[i++];
            } else if (temp[i] > temp[j]) {
                ans += (mid - (i + l) + 1);//逆序数
                nums[k] = temp[j++];
            } else {
                nums[k] = temp[i++];
            }
        }

    }

    void merge(int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        merge(l, mid);
        merge(mid + 1, r);
        sort(l, mid, r);

    }
}

using namespace match2018;

int A() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    ans = 0;
    merge(0, n - 1);
    printf("%lli\n", ans);

    return 0;
}