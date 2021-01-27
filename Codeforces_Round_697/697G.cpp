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
int t, n;
int a[2*1000*101];
int d[2*1000*101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      d[a[i]]=0;
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
      int val = a[i];
      int dValPrev= d[val];
      for(int j=1;j*j<=a[i];j++){
        if(val%j==0){
          d[val]=max(d[val], d[j]+1);
          if(j!=1)
          d[val]=max(d[val], d[val/j]+1);
        }
      }
      d[val]=max(d[val], dValPrev+1);
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
      mx= max(mx, d[a[i]]);
      d[a[i]]=0;
    }
    cout<<n-mx<<endl;
  }

  return 0;
}
