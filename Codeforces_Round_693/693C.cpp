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

long long n, t, a[2*1000*101], dp[2*1000*101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    dp[n] = a[n];

    long long ans = 0;
    ans = max(ans, dp[n]);
    for(int i= n-1;i>=1;i--){
      if(a[i]+i>n)
        dp[i]=a[i];
      else
        dp[i]=dp[i+a[i]]+a[i];
      ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
  }

  return 0;
}
