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
const int maxn = 201 * 1000;

pair<int,int> a[maxn];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n;
    for(int j=1;j<=n;j++){
      cin>>a[j].first;
      a[j].second=j;
    }
    if(n==1){
      cout<<"1"<<endl;
      continue;
    }
    sort(a+1,a+n+1);
    bool has_printed = false;
    for(int j=1;j<=n;j++){
      if(j==1){
        if(a[j].first!=a[j+1].first){
          cout<<a[j].second<<endl;
          has_printed=true;
          break;
        }
      }
      else if(j==n){
        if(a[j].first!=a[j-1].first){
          cout<<a[j].second<<endl;
          has_printed=true;
          break;
        }
      }
      else{
        if(a[j].first!=a[j-1].first && a[j].first!=a[j+1].first){
          cout<<a[j].second<<endl;
          has_printed=true;
          break;
        }
      }
    }
    if(!has_printed)
      cout<<"-1"<<endl;
  }

  return 0;
}
