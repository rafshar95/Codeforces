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
pair<pair<int,int>, int> a[2*100*1001];
int res[2*100*1001];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i].first.first>>a[i].first.second;
      if(a[i].first.first<a[i].first.second)
        swap(a[i].first.first, a[i].first.second);
      a[i].second = i;
    }
    sort(a+1, a+n+1);
    int pos1 = 1, pos2=1;
    int mn = -1, id = -1;
    while(pos1<=n){
      while(a[pos1].first.first==a[pos2].first.first && pos2<=n)
        pos2++;
      for(int i=pos1;i<pos2;i++){
        if(mn<a[i].first.second){
          res[a[i].second]=id;
        }
        else
          res[a[i].second]=-1;
      }
      for(int i=pos1;i<pos2;i++){
        if(mn>a[i].first.second || mn==-1){
          id = a[i].second;
          mn = a[i].first.second;
        }
      }
      pos1 = pos2;
    }
    for(int i=1;i<=n;i++)
      cout<<res[i]<<" ";
    cout<<endl;

  }

  return 0;
}
