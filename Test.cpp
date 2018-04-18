#pragma GCC optimize(2)

#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 60
int n, m;
int f[maxn << 1][maxn][maxn];
int matrix[maxn][maxn];

inline int max4(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}

int main() {
    in;
    mset(f, 0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int step = 2; step <= n + m - 1; step++) {//步数
        for (int i = 1; i <= n && i <= step; i++) {
            for (int j = 1; j <= n && j <= step; j++) {
               /* if (i ==1&& j == 1) {
                    continue;
                }*/
                f[step][i][j] = max4(f[step - 1][i][j], f[step - 1][i - 1][j - 1], f[step][i - 1][j],
                                     f[step][i][j - 1]) + matrix[i][step - i + 1] + matrix[j][step - j + 1];
                if (i == j) {
                    f[step][i][j] -= matrix[i][step - i + 1];
                }
            }
        }
    }
    printf("%d\n", f[n + m - 1][n][n]);
    return 0;
}
