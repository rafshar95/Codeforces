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

int t, x;

int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>x;
    for(int c=1;c * (c+1)/2 <= x;c++){
      int r= x - c * (c+1)/2;
      if(r <= c){
        if(r==0)
          cout<<c<<endl;
        else if(r<=c-1)
          cout<<c+1<<endl;
        else cout<<c+2<<endl;
      }
    }
  }

  return 0;
}
