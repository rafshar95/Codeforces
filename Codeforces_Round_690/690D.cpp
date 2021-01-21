
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

int t,n;
int sum[3010], a[3010];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      sum[i]=sum[i-1]+a[i];
    }
    int ans = n-1;
    for(int i=1;i<=n;i++){
      int val = sum[i];
      int cnt =1;
      int pos1 = i+1, pos2 = i+1;
      while(pos1 <=n){
        cnt++;
        while(pos2<=n && sum[pos2]-sum[pos1-1]<val)
          pos2++;
        if(sum[pos2]-sum[pos1-1]==val)
          pos1=pos2+1;
        else
          break;
        if(pos2==n)
          ans = min(ans, n - cnt);
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}
