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



int n, t;


long long k, x[201*1000];

long long g;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n>>k;
    for(int j=0;j<n;j++){
      cin>>x[j];
    }
    sort(x, x+n);
    g = x[1]- x[0];
    for(int j=2;j<n;j++){
      g= std::gcd(g, x[j]-x[0]);
    }
    if((x[0]-k)%g==0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}
