//#pragma GCC optimize(2)

#include <bits/stdc++.h>

inline int read() {
    int x = 0, y = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-')y = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * y;
}

typedef long long int lli;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
#define all(x) begin(x),end(x)
using namespace std;
#define in  std::ios::sync_with_stdio(false);fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 2005
#define maxm 20005
lli l, m, k, n, r, q;

int main() {
    in;

    return 0;
}
