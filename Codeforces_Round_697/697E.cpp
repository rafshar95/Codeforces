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

int t, k, n;


int a[1010];
long long mod = 1000*1000*1000 + 7;

long long find_inv(long long m){
  long long res = 1;
  long long cur = m;
  long long p = mod - 2;
  while(p!=0){
    if(p%2==1)
      res = (res * cur) % mod;
    p/=2;
    cur = (cur * cur) %mod;
  }
  return res;
}

long long find_choose(int m, int q){
  long long res1 = 1;
  long long res2 = 1;
  for(long long i=q+1;i<=m;i++)
    res1 = (res1 * i) % mod;
  for(long long i=1;i<=m-q;i++)
    res2 = (res2 * i) % mod;
  return (res1 * find_inv(res2))%mod;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1, a+n+1, greater<int>());
    int cnt = 0, cnt1 =0;
    for(int i=1;i<=n;i++)
      if(a[i]==a[k]){
        cnt++;
        if(i<=k)
          cnt1++;
      }
    //cout<<cnt<<" "<<cnt1<<endl;
    cout<<find_choose(cnt, cnt1)<<endl;

  }

  return 0;
}
