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

int n, m, k;

int a[72][72];

int dp[72][72][72];

int mx[72][72];

int res[72];


int res_copy[72];
void fill_dp(int row){
    for(int i=1;i<=m;i++)
      dp[i][0][0]=0;
    if(m>1)
      dp[1][1][a[row][1]%k]=a[row][1];
    for(int i=2;i<=m;i++)
      for(int j=1;j<=m/2;j++)
        for(int l=0;l<k;l++){
          dp[i][j][l]=dp[i-1][j][l];
          if(dp[i-1][j-1][(l-(a[row][i]%k)+k)%k]!=-1)
            dp[i][j][l]=max(dp[i][j][l], dp[i-1][j-1][(l-(a[row][i]%k)+k)%k] + a[row][i]);
        }
    for(int i=1;i<=m;i++)
      for(int j=0;j<=m/2;j++)
        for(int l=0;l<k;l++)
          mx[row][l]=max(mx[row][l], dp[i][j][l]);
  //  cout<<row<<endl;
    //for(int i=0;i<k;i++)
      //cout<<i<<" "<<mx[row][i]<<endl;
}

int main(){
  cin>>n>>m>>k;
  //cout<<n<<m<<k<<endl;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[i][j];
  memset(res, -1, sizeof res);
  memset(mx, -1, sizeof mx);
  res[0]=0;
  for(int i=1;i<=n;i++){
    memset(dp, -1, sizeof dp);
    fill_dp(i);
    memset(res_copy, -1, sizeof res_copy);
    for(int j=0;j<k;j++)
      for(int l=0;l<k;l++)
        if(res[j]!=-1 && mx[i][l]!=-1)
          res_copy[(j+l)%k]=max(res_copy[(j+l)%k], res[j]+mx[i][l]);
    for(int j=0;j<k;j++)
      res[j]=res_copy[j];
    //for(int j=0;j<k;j++)
    //  cout<<res[j]<<" ";
    //cout<<endl;
  }
  cout<<res[0]<<endl;
  return 0;
}
