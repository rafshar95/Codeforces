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

int t, n, k;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n>>k;
    if(n%k==0)
      cout<<1<<endl;
    else{
      if(k<n)
        cout<<2<<endl;
      else
        cout<<(k+n-1)/n<<endl;

    }
  }

  return 0;
}
