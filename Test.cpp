//#pragma GCC optimize(2)

#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
using namespace std;
#define in fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 1005
#define maxm 10005
int n, m, t;
int times[maxn];
struct people {
    int time;
    int from;
    int to;
} peoples[maxm];


int main() {
    in;
    scanf("%d%d%d", &n, &m, &t);
    loop(i, 1, n - 1) {
        scanf("%d", &times[i]);
    }
    loop(i, 1, m) {
        scanf("%d%d%d", &peoples[i].time, &peoples[i].from, &peoples[i].to);
    }

    return 0;
}