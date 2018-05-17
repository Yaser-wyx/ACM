#include <bits/stdc++.h>

int read() {
    int rv = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        rv = (rv << 1) + (rv << 3) + c - '0';
        c = getchar();
    }
    return rv * fh;
}

using namespace std;
typedef long long int lli;
typedef __int128 big;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
#define mod 692591
#define all(x) x.begin(),x.end()
#define in  std::ios::sync_with_stdio(false);fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define md (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
#define loop(a, b, c) for(register int a=b;a<=c;a++)
#define loop2(a, b, c) for(register int a=b;a>=c;a--)
#define loop3(a, b, c) for(register int a=b;a<c;a++)
#define loop4(a, b, c) for(register int a=b;a>c;a--)
#define maxn 50005
#define maxm 20005
lli l, m, n;

int main() {
    in;

    return 0;
}

