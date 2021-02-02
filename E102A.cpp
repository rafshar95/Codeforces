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

int t, n, d;

int a[110];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
      a[i]=min(a[i], a[1]+a[2]);
    int mx= 0;
    for(int i=1;i<=n;i++)
      mx=max(mx, a[i]);
    if(mx<=d)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}
