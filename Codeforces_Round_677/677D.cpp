#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int t, n;

pair<int,int> a[5010];
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i].first;
      a[i].second = i;
    }
    sort(a+1, a+n+1);
    if(a[1].first==a[n].first){
      cout<<"NO"<<endl;
      continue;
    }
    cout<<"YES"<<endl;
    for(int i=2;i<=n;i++){
      if(a[i].first!=a[1].first){
        cout<<a[1].second<<" "<<a[i].second<<endl;
      }
      else
        cout<<a[n].second<<" "<<a[i].second<<endl;
    }
  }
  return 0;
}
