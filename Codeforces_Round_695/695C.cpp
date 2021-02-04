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

int n1, n2, n3;

long long a[301*1000];
long long b[301*1000];
long long c[301*1000];
long long sum, sum1, sum2, sum3, ans;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n1>>n2>>n3;
  for(int i=1;i<=n1;i++){
    cin>>a[i];
    sum1+=a[i];
    sum+=a[i];
  }
  for(int i=1;i<=n2;i++){
    cin>>b[i];
    sum2+=b[i];
    sum+=b[i];
  }
  for(int i=1;i<=n3;i++){
    cin>>c[i];
    sum3+=c[i];
    sum+=c[i];
  }
  ans = max(max(sum-2*sum1, sum-2*sum2), sum-2*sum3);
  sort(a+1,a+n1+1);
  sort(b+1,b+n2+1);
  sort(c+1,c+n3+1);
  long long tmp= a[1]+b[1];
  tmp=min(tmp, a[1]+c[1]);
  tmp=min(tmp, b[1]+c[1]);
  ans=max(ans, sum-2*tmp);
  cout<<ans<<endl;

  return 0;
}
