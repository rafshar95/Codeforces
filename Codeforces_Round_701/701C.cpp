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

long long t, a, b;

int cnt[101*1000];

long long binary_search(long long val){
  if(val >= b)
    return 0;
  long long l = val +1;
  if(val *(l+1)>a)
    return 0;
  long long r = b;
  long long mid;
  while(l<r){
    mid = (l+r+1)/2;
    if(mid*val+val>a)
      r =mid-1;
    else
      l = mid;
  }
  return r-val;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>a>>b;
    int s = sqrt(a);
    long long ans =0;
    for(int i=1;i<=s;i++){
      ans+=binary_search(i);
    }
    cout<<ans<<endl;
  }

  return 0;
}
