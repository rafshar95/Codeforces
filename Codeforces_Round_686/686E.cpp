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

const int maxn = 2000* 101;

int t, n, p[maxn];

vector<int> adj[maxn], cycle;

bool mark[maxn], in_cycle[maxn], mark2[maxn], found;

int cnt[maxn];

void find_cycle(int st, int en){
  while(st!=en){
    in_cycle[st]=true;
    st = p[st];
    //cout<<st<<endl;
  }
  in_cycle[en]=true;
}

void dfs2(int cur, int lst_cycle){
  cnt[lst_cycle]++;
  mark2[cur]=true;
  for(int i=0;i<adj[cur].size();i++){
    int tmp = adj[cur][i];
    if(!mark2[tmp]){
      if(in_cycle[tmp])
        dfs2(tmp, tmp);
      else
        dfs2(tmp, lst_cycle);
    }
  }
}

void dfs1(int v){
  //cout<<v<<endl;
  mark[v]=true;
  for(int i=0;i<adj[v].size();i++){
    int tmp =  adj[v][i];
    if(!mark[tmp]){
      p[tmp]=v;
      dfs1(tmp);
    }
    else if(tmp!=p[v] && !found){
      found =true;
      //cout<<tmp<<" "<<v<<endl;
      find_cycle(v, tmp);
      dfs2(v, v);
    }
  }
}


int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      adj[i].clear();
      mark[i]=false;
      p[i]=-1;
      in_cycle[i]=false;
      mark2[i]=false;
      cnt[i]=0;
      found = false;
    }
    int x, y;
    for(int i=1;i<=n;i++){
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    long long ans = 1ll * n * (n-1);
    dfs1(1);
    for(int i=1;i<=n;i++)
      if(in_cycle[i]){
        ans = ans - (1ll*cnt[i]*(cnt[i]-1)/2);
      }
    cout<<ans<<endl;
  }


  return 0;
}
