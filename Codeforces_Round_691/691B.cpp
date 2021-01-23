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


int n;
int d[2001][2001][4];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>n;
  if(n%2==0)
    cout<<((n/2)+1)*(n/2 +1)<<endl;
  else
    cout<<2*(n/2+2)*(n/2 +1)<<endl;

  return 0;
}
