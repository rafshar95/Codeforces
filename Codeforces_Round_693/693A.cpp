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

int t, w, h, n;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>w>>h>>n;
    long long res = 1;
    while(w%2==0){
      w/=2;
      res*=2;
    }
    while(h%2==0){
      h/=2;
      res*=2;
    }
    if(res>=n)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }

  return 0;
}
