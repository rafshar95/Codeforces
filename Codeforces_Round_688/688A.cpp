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

int t, n, m;
int a[101], b[101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n>>m;
    for(int j=1;j<=n;j++)
      cin>>a[j];
    for(int j=1;j<=m;j++)
      cin>>b[j];
    int res=0;
    for(int j=1;j<=n;j++)
      for(int l=1;l<=m;l++)
        if(a[j]==b[l])
          res++;
    cout<<res<<endl;

  }

  return 0;
}
