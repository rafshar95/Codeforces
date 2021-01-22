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

int q[201*1000], d[201*1000], ans[201*1000],n, m, t;
vector<int> adj[201*1000];
void bfs(int v){
  d[v]= 0;

  int head= 1, tail=2;
  q[head]=v;
  while(head!=tail){
    int u = q[head];
    for(int i=0;i<adj[u].size();i++){
      int tmp = adj[u][i];
      if(d[tmp]==-1){
        d[tmp] = d[u]+1;
        q[tail++]=tmp;
      }
    }
    head++;
  }
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      adj[i].clear();
      d[i]=-1;
    }
    for(int i=1;i<=m;i++){
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
    }

    bfs(1);
    for(int i=n;i>=1;i--){
      int v = q[i];
      ans[v] = d[v];
      for(int j=0;j<adj[v].size();j++){
        int u = adj[v][j];
        if(d[u]<d[v])
          ans[v]=min(ans[v],d[u]);
        else if(d[u]>d[v])
          ans[v]=min(ans[v], ans[u]);
      }
    }
    for(int i=1;i<=n;i++)
      cout<<ans[i]<<" ";
    cout<<endl;

  }

  return 0;
}
