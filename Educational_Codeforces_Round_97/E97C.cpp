#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int dp[210][420];

int q, n, t[210];
int main(){
  cin>>q;
  for(int l=0;l<q;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=2*n;j++)
        dp[i][j]=n*2*n;
    for(int i=1;i<=n;i++)
      cin>>t[i];
    sort(t+1, t+n+1);
    for(int i=1;i<=2*n;i++){
      dp[1][i]=min(dp[1][i], abs(i-t[1]));
      if(i>1)
        dp[1][i]=min(dp[1][i], dp[1][i-1]);
    }
    for(int i=2;i<=n;i++)
      for(int j=i;j<=2*n;j++){
        dp[i][j]=min(dp[i][j], dp[i-1][j-1]+abs(j-t[i]));
        dp[i][j]=min(dp[i][j], dp[i][j-1]);
      }
    int ans = n*n;
    for(int i=1;i<=n*2;i++)
      ans=min(dp[n][i], ans);
    cout<<ans<<endl;
  }

  return 0;
}
