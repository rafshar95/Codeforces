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

const int maxn = 1010;

int n, m, k;

vector<int> adj[maxn], w[maxn];


int a[maxn], b[maxn];

int d[maxn][maxn];

bool mark[maxn];

int sum = 0;


set<pair<int,int> > st;

bool visited[maxn];

void dijkstra(int v){
  d[v][v]= 0;
  st.insert(make_pair(d[v][v], v));
  while(st.size()){
    int u = st.begin() -> second;
    visited[u]=true;
    st.erase(st.begin());
    for(int i=0;i<adj[u].size();i++){
      int tmp = adj[u][i];
      if(d[v][tmp]==-1 || d[v][tmp]>d[v][u]+w[u][i]){
        st.erase(make_pair(d[v][tmp], tmp));
        d[v][tmp]= d[v][u] + w[u][i];
        st.insert(make_pair(d[v][tmp], tmp));
      }
    }
  }
}



int main(){
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
    int x, y, z;
    cin>>x>>y>>z;
    adj[x].push_back(y);
    adj[y].push_back(x);
    w[x].push_back(z);
    w[y].push_back(z);
  }
  for(int i=1;i<=k;i++){
    cin>>a[i]>>b[i];
    mark[a[i]]=true;
    mark[b[i]]=true;
  }
  memset(d, -1, sizeof d);
  for(int i=1;i<=n;i++)
    if(mark[i])
      dijkstra(i);
  for(int i=1;i<=k;i++)
    sum+=(d[a[i]][b[i]]);
  int ans = sum;
  for(int i=1;i<=n;i++)
    for(int j=0;j<adj[i].size();j++){
      int u = adj[i][j];
      int we = w[i][j];
      int tmp = 0;
      for(int l=1;l<=k;l++){
        int di = min(d[a[l]][i], d[a[l]][u])+ min(d[b[l]][i], d[b[l]][u]);
        if(di<d[a[l]][b[l]])
          tmp += d[a[l]][b[l]] - di;
      }
      ans = min(ans, sum - tmp);
    }
  cout<<ans<<endl;


  return 0;
}
