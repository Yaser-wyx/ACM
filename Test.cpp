#pragma GCC optimize(3)

#include <bits/stdc++.h>

typedef long long int lli;
#define data1  "W:\\Workspace\\data.in"
#define data2  "F:\\ACM\\data.in"
#define INF 0xfffffff
#define infinitesimal  -2100000000
using namespace std;
#define in  std::ios::sync_with_stdio(false);fstream _file;_file.open(data1,ios::in);if(_file){freopen(data1,"r",stdin);}else{_file.open(data2,ios::in);if(_file)freopen(data2,"r",stdin);}
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 100005
#define maxm 10005
lli n, sum, d;
lli nums[maxn];

int main() {
    in;
    int indexes[maxn];

    cin >> n >> d;
    loop3(i, 0, n) {
        cin >> nums[i];
    }
    loop3(i, 0, n) {
        int temp = lower_bound(nums, nums + n, nums[i] + d) - nums;
        if (temp >= n) {
            indexes[i] = n - 1;
        } else {
            if (nums[temp] - nums[i] > d) {
                temp--;
            }
            indexes[i] = temp;
        }
    }
    lli ans = 0;
    loop3(i, 0, n - 2) {
        lli temp = indexes[i] - i - 1;

        ans += ((1 + temp) * temp) / 2;
    }
    cout << ans;
    return 0;
}
