#include <bits/stdc++.h>

typedef long long int lli;

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-06
 *  @Time: 17:58
 *  To change this template use File | Settings | File Templates.
 * 
 */

int P1090() {
    int n;
    scanf("%d", &n);
    multiset<lli> set1;
    lli temp = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lli", &temp);
        set1.insert(temp);
    }

    long long cnt = 0;
    for (int i = 1; i < n; i++) {
        auto t1 = set1.begin();
        lli t = *t1;
        set1.erase(t1);
        auto t2 = set1.begin();
        t += *t2;
        set1.erase(t2);
        cnt += t;
        set1.insert(t);
    }
    printf("%lli\n", cnt);
    return 0;
}