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
long long a, b;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>a>>b;
    int mn = 30;
    for(int i=0;i<20;i++){
      long long temp = b +i;
      if(temp ==1)
        continue;
      long res = a;
      int cnt =i;
      while(res>0){
        res/=temp;
        cnt++;
      }
      mn = min(mn, cnt);
    }
    cout<<mn<<endl;
  }

  return 0;
}
