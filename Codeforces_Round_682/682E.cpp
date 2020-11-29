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

long long n, a[2*101*1000], b[2*101*1000];

long long sum[2*101*1000];
int find_sig_bit(int i){
  int id =-1;
  for(int j=0;j<30;j++)
    if(((1<<j)& i)!=0)
      id = j;
  return id;
}
int ans =0;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
    b[i] = find_sig_bit(a[i]);
  //  cout<<b[i]<<endl;
  }
  //cout<<a[3]<<" "<<b[3]<<endl;
  for(int i=1;i<=n-2;i++){
    int id = b[i];
    for(int j=i+1;j<n;j++){
      if(sum[j]-sum[i] > (1<<(id+1)))
        break;
      if((a[i]^a[j+1])==sum[j]-sum[i]){
        ans++;
        //cout<<i<<" "<<j<<endl;
      }
    }
  }
//  cout<<b[8]<<endl;
  for(int i=1;i<=n/2;i++){
    swap(a[i], a[n-i+1]);
    swap(b[i], b[n-i+1]);
  }
  for(int i=1;i<=n;i++)
    sum[i]=sum[i-1]+a[i];
  for(int i=1;i<=n-2;i++){
    int id = b[i];
    for(int j=i+1;j<n;j++){
      if(sum[j]-sum[i] > (1<<(id+1)))
        break;
      //cout<<a[i]<<" "<<b[i]<<" "<<i<<" "<<j+1<<endl;
      if((a[i]^a[j+1])==sum[j]-sum[i] && sum[j]-sum[i] > (1<<(b[j+1]+1)))
        ans++;
    }
  }
  cout<<ans<<endl;


  return 0;
}
