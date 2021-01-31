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

const int maxn = 1000* 101;

int n, m, k;

string p[maxn];

pair<int, string> s[maxn];

vector<int> adj[maxn];
vector<int> order;

map<string, int> mp;

bool mark[maxn];
int position[maxn];

string find_ptrn(string a, int b, int kk){
  string res = "";
  for(int i=0;i<kk;i++){
    if((b&(1<<i))==0)
      res+=a[i];
    else
      res+='_';
  }
  return res;
}

bool is_matched(string a, string b){
  for(int i=0;i<b.size();i++)
    if(a[i]!=b[i] && a[i]!='_')
      return false;
  return true;
}

void dfs(int v){
  mark[v]= true;
  for(int i=0;i<adj[v].size();i++){
    int u = adj[v][i];
    if(!mark[u])
      dfs(u);
  }
  order.push_back(v);
  position[v]=order.size();
}


int main(){
  std::ios::sync_with_stdio(false);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++){
    cin>>p[i];
    mp[p[i]]=i;
  }
  for(int i=1;i<=m;i++){
    cin>>s[i].second>>s[i].first;
    if(!is_matched(p[s[i].first], s[i].second)){
      cout<<"NO"<<endl;
      return 0;
    }
    for(int j=0;j<(1<<k);j++){
      string res = find_ptrn(s[i].second, j, k);
      if(res!=p[s[i].first] && mp.find(res)!=mp.end()){
        int v = mp[p[s[i].first]];
        int u = mp[res];
        adj[v].push_back(u);
      }
    }
  }
  for(int i=1;i<=n;i++)
    if(!mark[i])
      dfs(i);
  for(int i=1;i<=n;i++)
    for(int j=0;j<adj[i].size();j++){
      int u = adj[i][j];
      if(position[i]<position[u]){
        cout<<"NO"<<endl;
        return 0;
      }
    }
  cout<<"YES"<<endl;
  for(int i=n-1;i>=0;i--)
    cout<<order[i]<<" ";
  cout<<endl;


  return 0;
}
