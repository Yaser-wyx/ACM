#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 10006
int n, m;

int main() {
    in;
    int cost[30];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }
    int dp[maxn];
    mset(dp, -1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= cost[i]; j--) {
            if (dp[j - cost[i]] > 0) {
                if (dp[j] < 0) {
                    dp[j] = dp[j - cost[i]];
                } else {
                    dp[j] = dp[j - cost[i]] + dp[j];
                }
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}