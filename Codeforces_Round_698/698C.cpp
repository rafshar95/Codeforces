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

long long d[2000*101];
long long diff[2000*101];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n*2;i++)
      cin>>d[i];
    sort(d+1, d+ 2*n+1);
    bool possible = true;
    for(int i=1;i<=n;i++){
      if(d[i*2-1]!=d[i*2])
        possible =false;
      if(i!=n && d[i*2+1]==d[i*2])
        possible =false;
    }
    if(n==1){
      if(!possible || d[1]%2==1)
        cout<<"NO"<<endl;
      else
        cout<<"YES"<<endl;
      continue;
    }
    for(int i=2;i<=n;i++){
      if((d[2*i]-d[2*i-2])%(2*i-2)!=0)
        possible =false;
      else
        diff[i-1]=(d[2*i]-d[2*i-2])/(2*i-2);
    }
    if(!possible){
      cout<<"NO"<<endl;
      continue;
    }
    long long sum =0;
    for(int i=1;i<n;i++){
      sum+=(diff[i]*(n-i)*2);
    }
    if(d[1]<=sum || (d[1]-sum)%(2*n)!=0)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }

  return 0;
}
