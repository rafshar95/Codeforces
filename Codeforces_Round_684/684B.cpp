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

using namespace std;
int t, n, k;

int a[2*101*1000];
int main(){
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n>>k;
    for(int i=1;i<=n*k;i++)
      cin>>a[i];
    sort(a+1, a+(n*k)+1);
    long long sum =0;
    for(int i=1;i<=k;i++){
      sum+=a[n*k - (i-1)*((n/2)+1)-n/2];
    }
    cout<<sum<<endl;
  }

  return 0;
}
