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

int t;

int n, k;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n>>k;
    int num = n- k +1;
    for(int i=1;i<= k - num;i++)
      cout<<i<<" ";
    for(int i=0;i<num;i++)
      cout<<k - i<<" ";
    cout<<endl;
  }

  return 0;
}
