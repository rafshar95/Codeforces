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
const int maxn =1001*100;
int n, t;
long long dp1[maxn], dp2[maxn], a[maxn], b[maxn], c[maxn];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>c[i];
    for(int i=1;i<=n;i++)
      cin>>a[i];
    for(int i=1;i<=n;i++)
      cin>>b[i];
    dp1[1]=abs(a[2]-b[2]);
    dp2[1]=0;
    long long res =0;
    for(int i=2;i<=n;i++){
      dp2[i]=dp1[i-1]+2+c[i]-1;
      if(a[i+1]!=b[i+1] && i<n)
        dp1[i]=max(abs(a[i+1]-b[i+1]), dp1[i-1]+2+c[i]-1-abs(a[i+1]-b[i+1]));
      if(a[i+1]==b[i+1] && i<n)
        dp1[i]=0;
      res = max(res, dp2[i]);
    }
    cout<<res<<endl;
  }

  return 0;
}
