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

int n;

int a[110], b[110];
int dp[2][101][10001];
double sum;
double ans[101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    sum+=b[i];
  }
  memset(dp, -1, sizeof dp);
  dp[0][0][0]=0;
  dp[1][0][0]=0;
  for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++){
      for(int c=1;c<=n*100;c++){
        dp[i%2][k][c]=dp[(i-1)%2][k][c];
        if(c>=a[i] && dp[(i-1)%2][k-1][c-a[i]]!=-1)
          dp[i%2][k][c]=max(dp[i%2][k][c], dp[(i-1)%2][k-1][c-a[i]]+b[i]);
      }
    }
  for(int k=1;k<=n;k++)
    for(int c=1;c<=n*100;c++)
      if(dp[n%2][k][c]!=-1)
      ans[k] = max(ans[k], min(1.0 * c,1.0 * sum / 2 + 1.0 * dp[n%2][k][c] / 2));
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}
