#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-22
 *  @Time: 17:55
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define maxn 250
#define maxm 250
int n, m, t;
bool prime[maxn];
vector<int> primes;

int P2563() {
    int dp[maxn];
    mset(prime, true);

    loop(i, 2, maxn) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = i << 1; j <= maxn; j += i) {
                prime[j] = 0;
            }
        }
    }

    while (~scanf("%d", &n)) {
        mset(dp, 0);
        dp[0] = 1;
        loop(i, 0, (primes.size() - 1)) {
            loop(j, primes[i], n) {
                dp[j] = max(dp[j], dp[j - primes[i]] + dp[j]);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}