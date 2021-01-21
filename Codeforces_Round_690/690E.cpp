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

int t,n;
int a[2*100*1001];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
      int pos = lower_bound(a+i, a+n+1, a[i]+3) - a;
      //cout<<n<<" "<<i<<" "<<pos<<endl;
      if(pos-i > 2)
      cnt += 1ll * (pos-i-1)*(pos-i-2)/2;
    }
    cout<<cnt<<endl;
  }

  return 0;
}
