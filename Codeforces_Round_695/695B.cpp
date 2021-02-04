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

int t, n;

int a[301*1000];
int check_val(int pos){
  if(pos==1 || pos==n)
    return 0;
  return (a[pos]>a[pos+1] & a[pos]>a[pos-1]) | (a[pos]<a[pos+1] & a[pos]<a[pos-1]);
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    int cnt =0;
    //for(int i=1;i<=n;i++)
    //  cout<<check_val(i)<<endl;
    for(int i=2;i<=n-1;i++){
      if(check_val(i))
        cnt++;
    }
    int mn_tot = cnt;
    for(int i=2;i<=n-1;i++){
      int prev_val = a[i];
      int sum1 = check_val(i)+check_val(i+1)+check_val(i-1);
      a[i]=a[i-1];
      int sum2=check_val(i)+check_val(i+1)+check_val(i-1);
      a[i]=a[i+1];
      int sum3=check_val(i)+check_val(i+1)+check_val(i-1);
      a[i]=prev_val;
      mn_tot = min(mn_tot, cnt + min(0, min(sum2- sum1, sum3 - sum1)));
    }
    cout<<mn_tot<<endl;
  }

  return 0;
}
