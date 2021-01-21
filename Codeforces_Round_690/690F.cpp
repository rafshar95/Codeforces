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

pair<int, pair<int,int> > a[4*100*1001];
int res[2*100*1001];
int t,n;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i].first;
      cin>>a[i+n].first;
      a[i].second.first = 1;
      a[i+n].second.first =2;
      a[i].second.second=i;
      a[i+n].second.second=i;
    }
    sort(a+1,a+ 2*n+1);
    int cnt =0;
    int ans = n-1;
    for(int i=1;i<=n*2;i++){
      if(a[i].second.first==2){
        cnt++;
      }
      else{
        res[a[i].second.second] = cnt;
      }
    }
    cnt =0;
    for(int i=2*n;i>=1;i--){
      if(a[i].second.first==1){
        cnt++;
      }
      else
        res[a[i].second.second] += cnt;
    }
    for(int i=1;i<=n;i++)
      ans = min(ans, res[i]);
    cout<<ans<<endl;
  }


  return 0;
}
