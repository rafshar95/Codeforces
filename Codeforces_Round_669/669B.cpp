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

const int maxn = 1010;

int t, n;

int a[maxn];

int b[maxn];
bool mark[maxn];
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    for(int i=1;i<=n;i++){
      b[i]=0;
      mark[i]=0;
      cin>>a[i];
      b[1]=max(b[1], a[i]);
    }
    for(int i=1;i<=n;i++)
      if(a[i]==b[1]){
        mark[i]=true;
        break;
      }
    int cur = b[1];
    for(int i=2;i<=n;i++){
      int mx = 0, id = -1;
      for(int j=1;j<=n;j++)
        if(!mark[j]){
          int tmp = std::gcd(cur, a[j]);
          if(mx<tmp){
            mx = tmp;
            id = j;
          }
        }
      cur = mx;
      b[i] = a[id];
      mark[id]=true;
    }
    for(int i=1;i<=n;i++)
      cout<<b[i]<<" ";
    cout<<endl;
  }
  return 0;
}
