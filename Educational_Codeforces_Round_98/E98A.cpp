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

int x, y, t;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>x>>y;
    if(x>y)
      swap(x,y);
    int cnt = x*2;
    y-=x;
    if(y>0)
      cnt+=(2*y-1);
    cout<<cnt<<endl;

  }

  return 0;
}
