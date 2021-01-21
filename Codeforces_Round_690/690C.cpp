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
void find_num(int n, int pos){
  //cout<<n<<" "<<pos<<endl;
  if(n==0){
    return;
  }
  if(n> pos*(pos+1)/2){
    cout<<"-1";
    return;
  }
  pos = min(n, pos);
  find_num(n-pos, pos-1);
  cout<<pos;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    find_num(n, 9);
    cout<<endl;
  }

  return 0;
}
