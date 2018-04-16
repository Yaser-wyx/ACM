#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 32100
int n, m;

int main() {
    pair<int, int> primary[100];//主件
    vector<pair<int, int>> adjunct[100];//附件
    int dp[maxn];
    in;
    scanf("%d%d", &n, &m);
    int v, p, q;
    for (int i = 1; i < 100; i++) {
        pair<int, int> temp(0, 0);
        adjunct[i].push_back(temp);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &v, &p, &q);
        if (q == 0) {
            primary[i].first = v;
            primary[i].second = p;
        } else {
            pair<int, int> pair1(v, p);
            adjunct[q].push_back(pair1);
        }
    }
    int cost[5000];
    int value[5000];
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < adjunct[i].size(); j++) {

        }
    }
    printf("%d\n", dp[n]);
    return 0;
}