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

long long a[7], n;
long long b[1000*101];
long long mn = 1<<30, mx = -1;

pair<int,int> c[6000*101];
int cnt[100*1001];
int main(){
  for(int i=1;i<=6;i++)
    scanf("%lld", &a[i]);
  scanf("%lld", &n);
  for(int i=1;i<=n;i++){
    scanf("%lld", &b[i]);
    cnt[i]=6;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
      c[i+n*(j-1)]=make_pair(b[i]-a[j], i);
    }
  }
  sort(c+1, c+n*6+1);
  int pos=n*6;
  while(true){
    int id = c[pos].second;
    if(cnt[id]>1){
      cnt[id]--;
      pos--;
    }
    else
      break;
  }
  int ans = c[pos].first - c[1].first;
  for(int i=2;i<=n*6;i++){
    int id = c[i-1].second;
    cnt[id]--;
    while(cnt[id]==0 && pos<=n*6){
      pos++;
      if(pos<=n*6){
        int id2 = c[pos].second;
        cnt[id2]++;
      }
    }
    if(pos>n*6)
      break;
    ans= min(ans, c[pos].first - c[i].first);
  }
  cout<<ans<<endl;

  return 0;
}
