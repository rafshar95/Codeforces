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
#include <numeric>

using namespace std;


int t, d;


bool n_prime[2*1000*100];
int main(){
  std::ios_base::sync_with_stdio(false);
  for(int i=2;i<=300*100;i++)
    if(!n_prime[i])
      for(int j=i*i;j<=300*100;j+=i)
        n_prime[j]=true;
  n_prime[1]=true;
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>d;
    int cnt  =0;
    long long res = 1;
    long long mn = 1;
    for(int i=d+1;cnt<2;i++){
      if(!n_prime[i] && cnt==0){
        cnt++;
        res*=i;
        mn = 1ll * i* i * i;
      }
      if(!n_prime[i] && cnt==1 && i>=d+res){
        res*=i;
        mn = min(res, mn);
        cnt++;
        cout<<mn<<endl;
      }
    }

  }


  return 0;
}
