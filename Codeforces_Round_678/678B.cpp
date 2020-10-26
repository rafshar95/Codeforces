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


int t, n;

int a[101][101];


bool n_prime[100*1001];
int main(){
  n_prime[1]=true;
  for(int i=2;i<=100*1000;i++)
    if(!n_prime[i])
      for(int j=i*2;j<=100*1000;j+=i)
        n_prime[j]=true;
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    for(int i=1;i<n;i++)
      for(int j=1;j<n;j++)
        a[i][j]=4;
    int val=-1;
    for(int i= 4*n-3;i<=100*1000;i++){
      if(!n_prime[i] && n_prime[i-4*n+4]){
        val =i-4*n+4;
        break;
      }
    }
    for(int i=1;i<n;i++){
      a[i][n]=val;
      a[n][i]=val;
    }
    val *= (n-1);
    int val2=-1;
    for(int i=val+1;i<=100*1000;i++){
      if(!n_prime[i] && n_prime[i-val]){
        val2=i-val;
        break;
      }
    }
    a[n][n]=val2;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout<<a[i][j]<<" ";

      }
      cout<<endl;
    }
  }
  return 0;
}
