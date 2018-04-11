#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t) memset(t,0,sizeof(t))
#define maxn 22
using namespace std;
int n;
int vis[maxn];
int ans = 0;

/*

void dfs(int x, int len) {
    ans = max(ans, len);
    for (int i = 0; i < n; i++) {
        if (chart[x][i]) {
            //不为0
            if (vis[i] < 2) {
                vis[i]++;
                dfs(i, len + (strlen(s[i]) - chart[x][i]));
                vis[i]--;
            }
        }
    }
}
*/

int main() {
    in;
    int chart[maxn][maxn];
    char *s[maxn];

    mset(chart);
    mset(vis);
    int start = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        s[i] = new char[1000];
        scanf("%s", s[i]);
    }
    char c;

    cin >> c;
    for (int i = 0; i < n; i++) {
        if (s[i][0] == c) {
            start = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {//前
        for (int j = 0; j < n; j++) {//后
            if (i == j) {
                continue;
            }
            char *temp = &s[i][strlen(s[i]) - 1];
            int cnt = 0;
            for (int index = 0; index < strlen(s[j]); index++) {
                if (*temp == s[j][index]) {
                    cnt++;
                    temp--;
                }
            }
            if (cnt == strlen(s[i]) || cnt == strlen(s[j])) {
                cnt = 0;
            }
            chart[i][j] = cnt;
        }
    }
    vis[start]++;
//    dfs(start, strlen(s[start]));
    printf("%d\n", ans);
    return 0;
}