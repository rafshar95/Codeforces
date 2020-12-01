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

int t, n, x;

int a[510];
bool hasInversionFromI[510];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>x;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    memset(hasInversionFromI, 0, sizeof hasInversionFromI);
    int mn = 600;
    for(int i=n;i>=1;i--){
      if(a[i]>mn)
        hasInversionFromI[i]=true;
      if(hasInversionFromI[i+1])
        hasInversionFromI[i]=true;
      mn = min(mn, a[i]);
    }
    int ans =0;
    for(int i=1;i<=n;i++)
      if(hasInversionFromI[i] && x<a[i]){
        swap(a[i], x);
        ans++;
      }
    bool is_sorted = true;
    for(int i=1;i<=n-1;i++)
      if(a[i]>a[i+1])
        is_sorted=false;
    if(is_sorted)
      cout<<ans<<endl;
    else
      cout<<"-1"<<endl;



  }

  return 0;
}
