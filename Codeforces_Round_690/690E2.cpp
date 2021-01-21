#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>

using namespace std;

int t, n, m, k;
int a[2*100*1001];

long long mod = 1000*1000*1000+ 7;

long long fac[2*100*1001];

long long power_k(long long x, long long k){
  long long res = 1;
  long long cur = x;
  while(k){
    if(k%2==1)
      res = (res* cur) % mod;
    k/=2;
    cur = (cur*cur) % mod;
  }
  return res;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  fac[0]=1;
  for(int i=1;i<=200*1000;i++){
    fac[i]=(fac[i-1]*i)%mod;
  }
  for(int l=1;l<=t;l++){
    cin>>n>>m>>k;
    long long cnt=0;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
      int pos = lower_bound(a+i, a+n+1, a[i]+k+1) - a;
      //cout<<n<<" "<<i<<" "<<pos<<endl;
      if(pos-i-1 >= m-1)
        cnt = (cnt + (fac[pos-i-1])*power_k((fac[m-1]*fac[pos-i-m])%mod, mod-2))%mod;
    }
    cout<<cnt<<endl;
  }

  return 0;
}
