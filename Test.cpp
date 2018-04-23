#pragma GCC optimize(2)

#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "E:\\WorkSpace\\ACM\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define maxn 1010
#define maxm 150
int n, m, t;
int puzzle[maxm][maxm];
int dp[maxm][maxm];
int mv[4][2] = {{1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}};

int dfs(int x, int y) {
    if(dp[x][y]){
        return dp[x][y];
    }
    loop(i,0,3){
        int new_x = x+mv[i][0];
        int new_y = y+mv[i][1];
        if(new_x>=0&&new_y>=0&&new_x<=n&&new_y<=m&&puzzle[new_x][new_y]<puzzle[x][y]){
            dp[x][y] = max(dfs(new_x,new_y)+1,dp[x][y]);
        }
    }
    return dp[x][y];
}

int main() {
    in;
    scanf("%d%d", &n, &m);
    loop(i, 1, n) {
        loop(j, 1, m) {
            scanf("%d", &puzzle[i][j]);
        }
    }
    mset(dp,0);
    int ans=0;
    loop(i,1,n){
        loop(j,1,m){
            dp[i][j] = dfs(i,j);
            ans = max(ans,dp[i][j]);
        }
    }
   printf("%d\n",ans);
    return 0;
}