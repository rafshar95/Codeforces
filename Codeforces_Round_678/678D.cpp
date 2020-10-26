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

const int maxn = 200 * 1001;


int n;

long long p[maxn], a[maxn], mx[maxn], sum[maxn], cnt[maxn];
vector<int> adj[maxn];
void dfs(int v){
  sum[v]+=a[v];
  for(int i=0;i<adj[v].size();i++){
    int u = adj[v][i];
    dfs(u);
    cnt[v]+=cnt[u];
    sum[v]+=sum[u];
    mx[v]=max(mx[v], mx[u]);
  }

  if(!adj[v].size()){
    cnt[v]++;
    mx[v]= a[v];
  }
  else
    mx[v]= max(mx[v], (sum[v]+cnt[v]-1)/cnt[v]);
}

int main(){
  cin>>n;
  for(int i=2;i<=n;i++){
    cin>>p[i];
    adj[p[i]].push_back(i);
    //cout<<"p"<<endl;
  }
  for(int i=1;i<=n;i++)
    cin>>a[i];
  //cout<<"s"<<endl;
  dfs(1);
  cout<<mx[1]<<endl;

  return 0;
}
