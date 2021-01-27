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

int n, m, t;
int a[2*1000*101];
int b[2*1000*101];
vector<int> v;
vector<int> u;
vector<long long> sum;
int find_val(long long mem){
  long long residual = m - mem;
  int pos = lower_bound(sum.begin(), sum.end(), residual) - sum.begin();
  if(pos==sum.size())
    return -1;
  else
    return (pos+1)*2;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;

  for(int l=1;l<=t;l++){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    v.clear();
    u.clear();
    sum.clear();
    for(int i=1;i<=n;i++){
      cin>>b[i];
      if(b[i]==1)
        v.push_back(a[i]);
      else
        u.push_back(a[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    sort(u.begin(), u.end(), greater<int>());
    for(int i=0;i<u.size();i++){
      sum.push_back(u[i]);
      if(i!=0)
        sum[i]+=sum[i-1];
    }
    long long best = -1;
    long long memory1 = 0;
    int res = find_val(memory1);
    if(res!=-1)
      best=res;
    for(int i=0;i<v.size();i++){
      memory1+=v[i];
      if(memory1>=m){
        if(best==-1 || best > (i+1))
          best = i+1;
        break;
      }
      res = find_val(memory1);
      if(res!=-1)
        if(best==-1 || best > res + (i+1))
          best = res + i+1;
    }
    cout<<best<<endl;

  }

  return 0;
}
