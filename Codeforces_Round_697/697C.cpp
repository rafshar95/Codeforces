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

int a, b, k, t;

int deg1[2*1000*101];
int deg2[2*1000*101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>a>>b>>k;
    for(int i=1;i<=a;i++)
      deg1[i]=0;
    for(int i=1;i<=b;i++)
      deg2[i]=0;
    for(int i=1;i<=k;i++){
      int x;
      cin>>x;
      deg1[x]++;
    }
    for(int i=1;i<=k;i++){
      int x;
      cin>>x;
      deg2[x]++;
    }
    long long ans = 1ll * k * (k-1) / 2;
    for(int i=1;i<=a;i++)
      if(deg1[i]>=2)
        ans -= (1ll * deg1[i] * (deg1[i]-1) / 2);
    for(int i=1;i<=b;i++)
      if(deg2[i]>=2)
        ans -= (1ll * deg2[i] * (deg2[i]-1) / 2);
    cout<<ans<<endl;
  }


  return 0;
}
