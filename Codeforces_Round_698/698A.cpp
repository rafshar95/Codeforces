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

int a[110];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    int mx =1;
    int cur =1;
    int cnt =1;
    for(int i=2;i<=n;i++){
      if(a[i]==a[cur]){
        cnt++;
      }
      else{
        cur = i;
        cnt =1;
      }
      mx=max(mx, cnt);
    }
    cout<<mx<<endl;
  }

  return 0;
}
