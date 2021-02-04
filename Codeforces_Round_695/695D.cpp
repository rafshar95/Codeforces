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

int n, k, q;


long long a[5010];

long long dp[5010][5010], mod = 1000*1000*1000+7, sum[5010], ans;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>k>>q;
  for(int i=1;i<=n;i++){
    dp[0][i]=1;
  }
  for(int i=1;i<=k;i++)
    for(int j=1;j<=n;j++){
      dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1])%mod;
    }
  for(int i=0;i<=k;i++)
      for(int j=1;j<=n;j++){
        sum[j]= (sum[j]+dp[i][j]*dp[k-i][j])%mod;
      }
  //for(int i=1;i<=n;i++)
    //cout<<sum[i]<<" ";
  //cout<<endl;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    ans = (((ans + sum[i]*a[i])%mod)+mod)%mod;
  }
  //cout<<ans<<endl;
  for(int i=1;i<=q;i++){
    long long pos, val;
    cin>>pos>>val;
    ans = (((ans + sum[pos]*(val-a[pos]))%mod)+mod)%mod;
    a[pos]=val;
    cout<<ans<<endl;
  }

  return 0;
}
