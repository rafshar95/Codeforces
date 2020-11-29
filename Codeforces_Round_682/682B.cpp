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


int t, n;
int a[1010];
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+n+1);
    bool pos = false;
    for(int i=2;i<=n;i++)
      if(a[i]==a[i-1])
        pos = true;
    if(pos)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
