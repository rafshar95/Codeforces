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

long long p[200], k;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>k;
    for(int i=0;i<n;i++)
      cin>>p[i];
    long long mx =0;
    long long sum= p[0];
    for(int i=1;i<n;i++){
      mx=max(mx, (p[i]*100+k-1)/k - sum);
      sum+=p[i];
    }
    cout<<mx<<endl;
  }

  return 0;
}
