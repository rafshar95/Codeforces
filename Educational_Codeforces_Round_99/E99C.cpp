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

int t, x, y;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>x>>y;
    cout<<x-1<<" "<<y<<endl;
  }

  return 0;
}
