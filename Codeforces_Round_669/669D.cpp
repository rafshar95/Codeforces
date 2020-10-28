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

const int maxn = 3 * 100 * 1001;

int n;

int dp[maxn], h[maxn];

vector<int> adj[maxn];
vector<int> v;
vector<int> u;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>h[i];
    dp[i]=n;
  }
  for(int i=n;i>=1;i--){
    while(v.size()){
      if(h[v.back()]<h[i])
        v.pop_back();
      else{
        adj[i].push_back(v.back());
        break;
      }
    }
    v.push_back(i);
  }/*
  for(int i=1;i<=n;i++){
    cout<<i<<" "<<adj[i].size()<<endl;
    for(int j=0;j<adj[i].size();j++)
      cout<<adj[i][j]<<" ";
    cout<<endl;
  }
  cout<<"hello"<<endl;
  */
  for(int i=n;i>=1;i--){
    while(u.size()){
      if(h[u.back()]>h[i])
        u.pop_back();
      else{
        adj[i].push_back(u.back());
        break;
      }
    }
    u.push_back(i);
  }/*
  for(int i=1;i<=n;i++){
    cout<<i<<" "<<adj[i].size()<<endl;
    for(int j=0;j<adj[i].size();j++)
      cout<<adj[i][j]<<" ";
    cout<<endl;
  }*/
  v.clear();
  u.clear();
  for(int i=1;i<=n;i++){
    while(v.size()){
      if(h[v.back()]<h[i])
        v.pop_back();
      else if(h[v.back()]==h[i]){
        v.pop_back();
        break;
      }
      else{
        adj[v.back()].push_back(i);
        break;
      }
    }
    while(u.size()){
      if(h[u.back()]>h[i])
        u.pop_back();
      else if(h[u.back()]==h[i])
      {
        u.pop_back();
        break;
      }
      else{
        adj[u.back()].push_back(i);
        break;
      }
    }
    v.push_back(i);
    u.push_back(i);
  }

  dp[1]=0;
  for(int i=1;i<=n;i++)
    for(int j=0;j<adj[i].size();j++)
      dp[adj[i][j]]=min(dp[adj[i][j]], dp[i]+1);
  cout<<dp[n]<<endl;

  return 0;
}

