#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

using namespace std;

long long mult[2000], mod = 1000 * 1000 * 1000 + 7;
int main(){
  mult[0]=1;
  mult[1]=1;
  for(int i=2;i<=1000;i++){
    mult[i]=(mult[i-1]*i)%mod;
  }
  int n, x, pos;
  cin>>n>>x>>pos;
  int a =0, b=0;
  int l=0, r=n;
  while(l<r){
    int mid = (l+r)/2;
    if(pos+1>mid){
      a++;
      l=mid+1;
    }
    else{
      r= mid;
      b++;
    }
  }
  //cout<<l<<" "<<r<<endl;
  a--;
  //cout<<a<<" "<<b<<endl;
  //cout<<a<<" "<<b<<endl;
  long long ans = mult[n-(a+b+1)];
  for(int i=x-a;i<=x-1;i++)
    ans= (ans*i)%mod;
  for(int i=n-x-b+1;i<=n-x;i++)
    ans=(ans*i)%mod;
  cout<<ans<<endl;


  return 0;
}
