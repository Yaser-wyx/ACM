#include <bits/stdc++.h>
#define mset(t) memset(t,0,sizeof(t))

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-09
 *  @Time: 14:08
 *  To change this template use File | Settings | File Templates.
 * 
 */
 int P1059(){
    int n;
    scanf("%d", &n);
    bool mark[1001];
    mset(mark);
    int num;
    int nums[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (!mark[num]) {
            nums[index++] = num;
            mark[num] = 1;
        }
    }
    sort(nums, nums + index);
    printf("%d\n", index);
    for (int i = 0; i < index; i++) {
        printf("%d", nums[i]);
        if (i != index) {
            printf(" ");
        }
    }
    return 0;
 }
 
 