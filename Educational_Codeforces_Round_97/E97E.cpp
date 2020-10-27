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

const int maxn = 5 * 100 * 1001;

int n, k;

int a[maxn], b[maxn];

int lis[maxn], p[maxn];
int my_inf = 1<<30;
int main(){
  scanf("%d %d", &n, &k);
  for(int i=1;i<=n;i++)
    scanf("%d", &a[i]);
  for(int i=1;i<=k;i++)
    scanf("%d", &b[i]);
  for(int i=2;i<=k;i++){
    if(a[b[i]]-a[b[i-1]]<b[i]-b[i-1]){
      cout<<"-1"<<endl;
      return 0;
    }
  }
  int pos = 1;
  if(k==0)
    pos = -1;
  for(int i=1;i<=n;i++)
    lis[i]=my_inf;
  int ans = n;
  for(int i=1;i<=n;i++){
    int id = lower_bound(lis+1, lis+n+1, a[i]) - lis;
    if(pos!=-1){
      if(pos<=k){
        if(b[pos]-i>a[b[pos]]-a[i])
          continue;
      }
      if(pos>1){
        if(i-b[pos-1]>a[i]-a[b[pos-1]])
          continue;
      }
      if(pos<=k && b[pos]==i)
        pos++;
    }
    if((id==1 || i-p[id-1]<=a[i]-lis[id-1])){
      lis[id]= a[i];
      p[id]=i;
      ans = min(ans, n-id);
    }
  }
  cout<<"hello"<<endl;
  for(int i=1;i<=n;i++)
    cout<<lis[i]<<" ";
  cout<<endl;
  cout<<ans<<endl;


  return 0;
}
