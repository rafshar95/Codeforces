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

const int maxn = 1001 * 100;

int n, k;

long long a[maxn];
long long ans = 0;

set< pair<long long, pair<int,int> > > st;

long long amount(int pos, int level){
  long long res= 0;
  res+=((a[pos]%level)*(a[pos]/level + 1)*(a[pos]/level + 1));
  res+=((level - a[pos]%level)*(a[pos]/level)*(a[pos]/level));
  return res;
}

long long saving(int pos, int level){
  if(a[pos]<level+1)
    return 0;
  return amount(pos, level) - amount(pos, level + 1);
}
int main(){
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    ans+=(a[i]*a[i]);
    long long val = saving(i, 1);
    //cout<<val<<endl;
    if(val>0)
      st.insert(make_pair(val, make_pair(i, 1)));
  }
  for(int i=n+1;i<=k;i++){
    pair<long long, pair<int,int> > x = *st.rbegin();
    st.erase(x);
    ans-=(x.first);
    //cout<<x.second.first<<" "<<x.first<<endl;
    x.second.second++;
    x.first = saving(x.second.first, x.second.second);
    if(x.first>0)
      st.insert(x);
  }
  cout<<ans<<endl;

  return 0;
}
