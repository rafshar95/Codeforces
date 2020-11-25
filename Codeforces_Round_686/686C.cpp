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

int t, n;

int cnt[maxn], a[maxn], lst[maxn];

int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      lst[i]=-1;
      cnt[i]=0;
    }

    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]!=a[i-1] || i==1)
        cnt[a[i]]++;
    }
    if(n==1){
      cout<<"0"<<endl;
      continue;
    }
    int mn = -1;
    cnt[a[1]]--;
    cnt[a[n]]--;
    for(int i=1;i<=n;i++){
      if(mn==-1 || mn > cnt[a[i]]+1)
        mn = cnt[a[i]]+1;
    }
    cout<<mn<<endl;

  }

  return 0;
}
