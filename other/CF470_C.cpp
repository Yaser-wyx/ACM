#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-15
 *  @Time: 12:05
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100010
int n;
long long int v[maxn], k[maxn];


int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lli", &v[i]);//体积
    }
    for (int i = 0; i < n; i++) {
        scanf("%lli", &k[i]);//温度
    }
    multiset<long long> multiset1;
    long long rm = 0;
    long long int now;

    for (int i = 0; i < n; i++) {
        now = 0;
        multiset1.insert(v[i] + rm);

        while (!multiset1.empty() && *begin(multiset1) - rm - k[i] <= 0) {
            now += (*begin(multiset1) - rm);
            multiset1.erase(begin(multiset1));
        }
        now += multiset1.size() * k[i];
        rm += k[i];
        printf("%lld ", now);

    }
    return 0;
}