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

int t, n, d[201*1000], mark[201*1000];

vector<int> adj[201*1000];

int dfs(int v){
  d[v] = 0;
  mark[v]=true;
  int res = -1;
  int mx = -1;
  int mn = n;
  int cnt =0;
  for(int i=0;i<adj[v].size();i++){
    int u = adj[v][i];

    if(!mark[u]){
      res = max(res,dfs(u));
      cnt++;
      mn = min(mn, d[u]);
      mx = max(mx, d[u]);
    }
  }
  if(cnt>0)
    d[v] = mn +1;
  if(cnt>1 && v!=1)
    res = max(res, mx+2);
  if(cnt>1 && v==1){
    int cnt2 = 0;
    for(int i=0;i<adj[1].size();i++){
      int u = adj[1][i];
      if(d[u]==mx)
        cnt2++;
    }
    if(cnt2==1)
      res=max(res, mx+1);
    else
      res = max(res, mx+2);
  }
  //cout<<v<<" "<<d[v]<<endl;
  res = max(d[v], res);
  return res;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      adj[i].clear();
      mark[i]=false;
    }
    int edge_x, edge_y;
    for(int i=1;i<=n-1;i++){
      cin>>edge_x>>edge_y;
      adj[edge_x].push_back(edge_y);
      adj[edge_y].push_back(edge_x);
    }
    cout<<dfs(1)<<endl;
  }

  return 0;
}
