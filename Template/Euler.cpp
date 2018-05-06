#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-06
 *  @Time: 11:44
 *  To change this template use File | Settings | File Templates.
 *  欧拉函数    求小于n的正整数中与n互质的数的数目
 */
lli n;
int euler[400001];

void Euler(int Max) {
    Max = n - 1;
    euler[1] = 1;
    for (int i = 2; i <= Max; i++)
        euler[i] = i;
    for (int i = 2; i <= Max; i++)
        if (euler[i] == i)
            for (int j = i; j <= Max; j += i)
                euler[j] = euler[j] / i * (i - 1);
}