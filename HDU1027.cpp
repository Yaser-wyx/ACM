#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-05
 *  @Time: 14:26
 *  To change this template use File | Settings | File Templates.
 *
 */
#define maxn 1100
int x, m;

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320}; //康托展开的逆运算,{1...n}的全排列，中的第k个数为s[]
int nums[maxn];

//逆康托展开
void decantor(int s, int e, int k) {//从s开始到e结束，求第K个全排列
    k--;
    int size = e - s + 1;
    int nums[size];//存放可选的数字
    int vis[size] = {0};//哪些数字已经选过了
    for (int i = 0; i + s <= e; i++) {//将能选的数字存入
        nums[i] = s + i;
    }
    int temp, j;
    for (int i = 0; i < size; i++) {
        temp = k / fac[size - i - 1];
        for (j = 0; j < size; j++) {
            if (!vis[j]) {//查找当前位的数字
                if (temp == 0) {
                    break;
                }
                temp--;
            }
        }
        vis[j] = 1;//更新已选中的数字
        k %= fac[size - i - 1];
        nums[s + i - 1] = nums[j];//将选的数字放入答案中
    }
}

int HDU1027() {
    while (~scanf("%d%d", &x, &m)) {
        memset(nums, 0, sizeof(nums));
        int s = 1, e = x;
        if (x > 8) {
            for (int i = 0; i < x - 8; i++) {
                nums[i] = i + 1;
                s++;
            }
        }

        decantor(s, e, m);
        for (int i = 0; i < x; i++) {
            printf("%d", nums[i]);
            if (i != x - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }
    return 0;
}

