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

const int maxn = 201 * 1000;

int dp1[maxn], dp2[maxn], dp3[maxn], dp4[maxn],  t, n, m, sum[maxn], sum2[maxn];
string s;

int find_ans(int a, int b){
  int mx =0;
  int mn =0;
  if(a!=1){
    mx = sum[a-2];
    mn = -sum[a-2];
  }
  if(b!=s.size()){
    mx += dp3[b];
    mn += dp4[b];
  }
  if(a!=1){
    mx = max(mx, dp1[a-2]);
    mn = max(mn, dp2[a-2]);
  }
  mx = max(mx, 0);
  mn = max(mn, 0);
  //cout<<mx<<" "<<mn<<endl;
  return mx + mn + 1;
}

int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
      dp1[i]=0;
      dp2[i]=0;
      sum[i]=0;
      if(i!=0)
        sum[i]+=sum[i-1];
      if(s[i]=='+'){
        sum[i]++;
      }
      else{
        sum[i]--;
      }
      if(i!=0){
        dp1[i]=dp1[i-1];
        dp2[i]=dp2[i-1];
      }
      dp1[i]=max(dp1[i], sum[i]);
      dp2[i]=max(dp2[i], -sum[i]);
    }
    for(int i=s.size()-1;i>=0;i--){
      dp3[i]=0;
      dp4[i]=0;
      if(i!=s.size()-1){
        dp3[i]=dp3[i+1];
        dp4[i]=dp4[i+1];
      }
      if(s[i]=='+'){
        dp3[i]++;
        dp4[i]--;
      }
      else{
        dp3[i]--;
        dp4[i]++;
      }
      dp3[i]=max(0, dp3[i]);
      dp4[i]=max(0, dp4[i]);
    }

    for(int i=1;i<=m;i++){
      int a, b;
      cin>>a>>b;
      cout<<find_ans(a,b)<<endl;
    }
  }



  return 0;
}
