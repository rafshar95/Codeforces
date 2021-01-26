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
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    bool printed = false;
    for(int i=0;i*2020<=n;i++){
      int m = n - i*2020;
      if(m%2021==0){
        cout<<"YES"<<endl;
        printed= true;
        break;
      }
    }
    if(!printed)
      cout<<"NO"<<endl;
  }

  return 0;
}
