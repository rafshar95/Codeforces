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

const int maxn = 100 * 1001;

int n, a[maxn];

int mn[maxn*4];
int lst[maxn];
bool mark[maxn];

int find_min(int node, int l, int r, int pos){
  if(pos<l)
    return n;
  if(pos>=r)
    return mn[node];
  int tmp1 = find_min(node<<1, l, (l+r)/2, pos);
  int tmp2 = find_min(1+ (node<<1), (l+r)/2+1, r, pos);
  return min(tmp1, tmp2);
}
void set_at(int node, int l, int r, int pos, int val){
  if(pos<l || pos>r)
    return;
  if(l==r){
    mn[node]=val;
    return;
  }
  set_at(node<<1, l, (l+r)/2, pos, val);
  set_at(1+(node<<1), (l+r)/2+1, r, pos, val);
  mn[node]=min(mn[node<<1],mn[1+(node<<1)]);
}
int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++)
    scanf("%d", &a[i]);
  for(int i=1;i<=n;i++){
    if(a[i]>1){
      int pos = find_min(1, 1, n, a[i]-1);
      //cout<<i<<endl;
      if(pos>lst[a[i]])
        mark[a[i]]=true;
      mark[1]=true;
    }
    lst[a[i]]=i;
    set_at(1, 1, n, a[i], i);
  }
  for(int i=1;i<=n;i++){
    int pos = find_min(1,1,n,i);
    if(pos>lst[i+1])
      mark[i+1]=true;
  }
  for(int i=1;i<=n+2;i++)
    if(!mark[i]){
      printf("%d\n", i);
      return 0;
    }

  return 0;
}
