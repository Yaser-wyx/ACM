#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-23
 *  @Time: 10:20
 *  To change this template use File | Settings | File Templates.
 *  快速幂
 */
lli qp(int a,int k){
    lli ans=1,base=a;
    while(k){{
            if(k&1){
                ans*=base;
            }
            base*=base;
            k>>=1;
        }
    }
    return ans;
}

int main(){
    lli ans = qp(4,2);
    printf("%lli",ans);
    return 0;
}