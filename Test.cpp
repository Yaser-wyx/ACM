//#pragma GCC optimize(2)

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
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define loop5(a, b, c, d) for(int a=b;a<=c;a++)if(d)break;
#define maxn 2005
#define maxm 20
int n, m, t;
char words[maxn][80];
int dp[maxn];

int main() {
    in;
    scanf("%d", &n);
    getchar();
    loop(i, 1, n) {
        scanf("%s", words[i]);
    }

    return 0;
}