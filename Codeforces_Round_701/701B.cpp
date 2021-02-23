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

int n, q, k;

int cnt[1000*101], a[1000*101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>q>>k;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=2;i<n;i++){
    cnt[i]= (a[i]- a[i-1]-1) + (a[i+1]-a[i] -1 );
    cnt[i]+=cnt[i-1];
  }
  for(int i=1;i<=q;i++){
    int l, r;
    cin>>l>>r;
    if(l==r){
      cout<<k-1<<endl;
      continue;
    }
    int res = cnt[r-1] - cnt[l];
    if(a[r]!=k)
      res+=(k-a[r]);
    res+=a[r]-a[r-1]-1;
    if(a[l]!=1)
      res+=(a[l]-1);
    res+=a[l+1]-a[l]-1;
    cout<<res<<endl;
  }


  return 0;
}
