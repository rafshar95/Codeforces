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
long long a[101*1000];

long long binary(long long l, long long r, long long sum){
  while(l<r){

    long long mid = (l+r)/2;
    //cout<<mid<<endl;
    if(mid*(n-1)<sum)
      l = mid+1;
    else
      r = mid;
  }
  return l;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    long long mx = 0, sum =0;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      mx=max(mx, a[i]);
      sum += a[i];
    }
    long long p = binary(mx,2ll*(1<<30), sum);
    cout<<p*(n-1)-sum<<endl;
  }

  return 0;
}
