#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-12
 *  @Time: 09:55
 *  To change this template use File | Settings | File Templates.
 * 
 */#define mset(t) memset(t,0,sizeof(t))
#define maxn 200010
int n;
int nums[maxn];
int step[maxn];
int degree[maxn];//入度
int flag[maxn];

int P2661() {
    mset(step);
    mset(degree);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        degree[nums[i]]++;
    }
    int ans = n;
    for (int index = 1; index <= n; index++) {
        int next = nums[index];
        if (degree[index] && step[index] == 0) {
            flag[index] = index;
            int temp = index;
            while (step[next] == 0) {
                flag[next] = index;
                step[next] = step[temp] + 1;
                temp = next;
                next = nums[temp];
            }
            int st = step[temp] + 1 - step[next];
            if (flag[temp] == flag[next] && flag[next] == index) {
                ans = min(ans, st);
            }

        }
    }

    printf("%d\n", ans);
    return 0;
}