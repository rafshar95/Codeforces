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
#include <array>

using namespace std;

const int maxn = 201 *1000;

int n, m;

long long d[maxn][2][2];

vector<long long> adj[maxn], w[maxn];


set <pair<long long, array<int, 3>>> st;

void dijkstra(int v){
  d[v][0][0]=0;
  st.insert(make_pair(d[v][0][0] , array<int,3>{v , 0, 0}));
  while(st.size()){
    auto [u, mx, mn] = st.begin() -> second;
    st.erase(st.begin());
    for(int i=0;i<adj[u].size();i++){
      int tmp = adj[u][i];
      if(d[tmp][mx][mn]>d[u][mx][mn]+w[u][i]){
        st.erase(make_pair(d[tmp][mx][mn], array<int,3>{tmp, mx, mn}));
        d[tmp][mx][mn]=d[u][mx][mn]+w[u][i];
        st.insert(make_pair(d[tmp][mx][mn], array<int,3>{tmp, mx, mn}));
      }
      if(mx!=1 && d[tmp][mx|1][mn]>d[u][mx][mn]){
        st.erase(make_pair(d[tmp][mx|1][mn], array<int,3>{tmp, mx|1, mn}));
        d[tmp][mx|1][mn]=d[u][mx][mn];
        st.insert(make_pair(d[tmp][mx|1][mn], array<int,3>{tmp, mx|1, mn}));
      }
      if(mn!=1 && d[tmp][mx][mn|1]>d[u][mx][mn]+2*w[u][i]){
        st.erase(make_pair(d[tmp][mx][mn|1], array<int,3>{tmp, mx, mn|1}));
        d[tmp][mx][mn|1]=d[u][mx][mn]+2*w[u][i];
        st.insert(make_pair(d[tmp][mx][mn|1], array<int,3>{tmp, mx, mn|1}));
      }
      if(mx!=1 && mn!=1 && d[tmp][mx|1][mn|1]>d[u][mx][mn]+w[u][i]){
        st.erase(make_pair(d[tmp][mx|1][mn|1], array<int,3>{tmp, mx|1, mn|1}));
        d[tmp][mx|1][mn|1]=d[u][mx][mn]+w[u][i];
        st.insert(make_pair(d[tmp][mx|1][mn|1], array<int,3>{tmp, mx|1, mn|1}));
      }

    }
  }

}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int a, b, c;
    cin>>a>>b>>c;
    adj[a].push_back(b);
    adj[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
  for(int i=1;i<=n;i++){
    d[i][0][0]=1ll * n * (1<<30);
    d[i][0][1]=1ll * n * (1<<30);
    d[i][1][0]=1ll * n * (1<<30);
    d[i][1][1]=1ll * n * (1<<30);
  }
  dijkstra(1);
  for(int i=2;i<=n;i++)
    cout<<d[i][1][1]<<endl;

  return 0;
}
