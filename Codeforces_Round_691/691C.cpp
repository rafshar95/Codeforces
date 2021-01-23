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

long long a[2*100*1001], b[2*100*1001], n,m;

int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=m;i++)
    cin>>b[i];
  if(n==1){
    for(int i=1;i<=m;i++)
      cout<<b[i]+a[1]<<" ";
  }
  if(n==2){
    for(int i=1;i<=m;i++)
      cout<<std::gcd(b[i]+a[1], b[i]+a[2])<<" ";
  }
  if(n>2){
    sort(a+1, a+n+1);
    long long tmp = a[2] - a[1];
    for(int i=3;i<=n;i++)
      tmp = std::gcd(tmp, a[i] - a[i-1]);
    for(int i=1;i<=m;i++)
      cout<<std::gcd(tmp, b[i]+a[1])<<" ";
  }

  cout<<endl;

  return 0;
}
