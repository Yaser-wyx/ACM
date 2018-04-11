#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 100010
typedef unsigned long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-23
 *  @Time: 15:02
 *  To change this template use File | Settings | File Templates.
 * 
 */
char s1[maxn], s2[maxn];
lli pw[maxn], h1[maxn], h2[maxn];
size_t len1;
size_t len2;

lli gethash(lli h[], int l, int r) {
    return h[r] - h[l] * pw[r - l];
}

bool solve(int len) {//判断长度为len是否有解
    int n = 0;
    lli ans[maxn];
    for (int i = 0; i <= len1 - len; i++) {
        ans[n++] = gethash(h1, i, i + len);
    }
    sort(ans, ans + n);
    for (int i = 0; i <= len2 - len; i++) {
        lli h = gethash(h2, i, i + len);
        if (binary_search(ans, ans + n, h)) {
            return true;
        }
    }
    return false;
}

int main() {

    while (~scanf("%s%s", s1, s2)) {
        len1 = strlen(s1);
        len2 = strlen(s2);
        int l = 0;
        int r = max(len1, len2);
        pw[0] = 1;
        for (int i = 1; i <= r; i++) {
            pw[i] = pw[i - 1] * 131;//预处理幂次
        }
        h1[0] = 0;
        for (int i = 0; i < len1; i++) {
            //预处理s1的前缀hash
            h1[i + 1] = h1[i] * 131 + s1[i];
        }
        h2[0] = 0;
        for (int i = 0; i < len2; i++) {
            //预处理s2的前缀hash
            h2[i + 1] = h2[i] * 131 + s2[i];
        }

        //二分法
        while (l != r) {
            int mid = (l + r) >> 1;
            if (solve(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        printf("%d\n", l);

    }
    return 0;
}