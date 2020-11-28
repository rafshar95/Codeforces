#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cstring>
#include <random>
#include <map>
#include <cmath>

using namespace std;



set<pair<int,int> >st;

int d[101*1000];

vector<int> adj[101*1000];

int t, n, m, k;

vector <pair<int,int> > edges;

bool contained(int v1, int v2){
  int pos = lower_bound(adj[v1].begin(), adj[v1].end(), v2) - adj[v1].begin();
  if(pos<adj[v1].size() && adj[v1][pos]==v2)
    return true;
  return false;
}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
      adj[i].clear();
      d[i]=0;
    }
    int u, v;
    st.clear();
    edges.clear();
    for(int i=1;i<=m;i++){
      cin>>u>>v;
      edges.push_back(make_pair(u,v));
      adj[u].push_back(v);
      adj[v].push_back(u);
      d[u]++;
      d[v]++;
    }
    for(int i=1;i<=n;i++){
      st.insert(make_pair(d[i], i));
      sort(adj[i].begin(), adj[i].end());
    }
    bool found = false;
    while(st.size()>0){
      int x = st.begin() -> second;
      if(d[x]>=k){
        cout<<1<<" "<<st.size()<<endl;
        for (std::set<pair<int,int> >::iterator it=st.begin(); it!=st.end(); ++it)
          cout<<it->second<<" ";
        cout<<endl;
        found =true;
        break;
      }
      else if(d[x]==k-1 && 1ll* m>=1ll * k*(k-1)/2){
        int cnt=0;
        for(int i=0;i<edges.size();i++){
          int y = edges[i].first;
          int z = edges[i].second;
          if( st.find(make_pair(d[y],y))!=st.end() && st.find(make_pair(d[z],z))!=st.end() && ((contained(x, y) && contained(x, z)) || y==x || z==x))
            cnt++;
        }
        //cout<<cnt<<endl;
        //cout<<l<<" "<<cnt<<endl;
        if(cnt== k*(k-1)/2){
          cout<<2<<endl;
          cout<<x<<" ";
          for(int i=0;i<adj[x].size();i++){
            int tmp = adj[x][i];
            if(st.find(make_pair(d[tmp], tmp))!=st.end())
              cout<<tmp<<" ";
          }
          cout<<endl;
          found =true;
          break;
        }
      }
      st.erase(st.begin());
      for(int i=0;i<adj[x].size();i++){
        int y = adj[x][i];
        if(st.find(make_pair(d[y], y))!=st.end()){
          d[x]--;
          st.erase(make_pair(d[y], y));
          d[y]--;
          st.insert(make_pair(d[y], y));
        }
      }
    }
    if(!found)
      cout<<"-1"<<endl;

  }

  return 0;
}
