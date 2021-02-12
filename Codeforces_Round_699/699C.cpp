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
#include <numeric>

using namespace std;


const int maxn = 101 * 1000;

int a[maxn], b[maxn], cnt1[maxn], cnt2[maxn], c[maxn];
int t, n, m;
vector<int> v[maxn];
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      cnt1[i]=0;
      cnt2[i]=0;
      v[i].clear();
    }
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    for(int i=1;i<=n;i++){
      cin>>b[i];
      if(b[i]!=a[i])
        v[b[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
      cin>>c[i];
      cnt2[c[i]]++;
    }
    bool poss = false;
    for(int i=1;i<=n;i++)
      if(b[i]==c[m])
        poss=true;
    if(!poss){
      //cout<<"as"<<endl;
      cout<<"NO"<<endl;
      continue;
    }
    int col_temp;
    if(v[c[m]].size()>0)
      col_temp = v[c[m]][0];
    else
      for(int i=1;i<=n;i++)
        if(b[i]==c[m])
          col_temp = i;
    for(int i=1;i<=n;i++)
      if(cnt2[i]<v[i].size())
        poss=false;
    if(poss){
      cout<<"YES"<<endl;
      for(int i=1;i<=m;i++){
        if(i!=m && v[c[i]].size()>0)
          cout<<v[c[i]].back()<<" ";
        else
          cout<<col_temp<<" ";
        if(v[c[i]].size()>1)
          v[c[i]].pop_back();
      }
      cout<<endl;
    }
    else
      cout<<"NO"<<endl;
  }

  return 0;
}
