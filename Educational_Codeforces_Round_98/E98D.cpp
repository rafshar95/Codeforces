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

long long mod = 998244353 ;

long long f[2*1000*101], sum0=2, sum1=1;
int n;
int z=1;


int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    return (x % m + m) % m;
}


int main(){
  std::ios::sync_with_stdio(false);
  cin>>n;
  f[0]=1;
  f[1]=1;
  f[2]=1;
  for(int i=1;i<=n;i++)
    z = (z*2)%mod;
  for(int i=3;i<=n;i++){
    if(i%2==0){
      f[i]=sum1;
      sum0=(sum0+f[i])%mod;
    }
    else{
      f[i]=(sum0)%mod;
      sum1=(sum1+f[i])%mod;
    }
  }
  cout<<(f[n]*modInverse(z, mod))%mod<<endl;



  return 0;
}
