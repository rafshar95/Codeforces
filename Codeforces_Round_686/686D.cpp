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

int t;

long long n;


bool n_prime[1000*101];
int main(){
  std::ios::sync_with_stdio(false);
  n_prime[1]=true;
  for(int i=2;i<=1000*100;i++)
    if(!n_prime[i])
      for(int j=i*2;j<=1000*100;j+=i)
        n_prime[j]=true;
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    int mx = -1, id = -1;
    for(long long l=2;l*l<=n;l++){
      if(!n_prime[l] && n%l==0){
        int cnt =0;
        long long tmp = l;
        while(n%tmp==0 && tmp<=n){
          cnt++;
          tmp*=l;
        }
        if(cnt>mx){
          mx = cnt;
          id = l;
        }
      }
    }
    if(mx==-1){
      cout<<1<<endl;
      cout<<n<<endl;
    }
    else{
      cout<<mx<<endl;
      for(int i=1;i<=mx-1;i++){
        cout<<id<<" ";
        n/=id;
      }
      cout<<n<<endl;
    }
  }

  return 0;
}
