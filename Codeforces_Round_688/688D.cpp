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

long long k;
int t;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>k;
    if(k%2==1){
      cout<<"-1"<<endl;
      continue;
    }
    k/=2;
    vector<int> ans;
    int cnt =0;
    while(k>0){
      //cout<<k<<endl;
      for(int i=60;i>0;i--)
        if(k>=(1ll<<i)-1){
          cnt+=i;
          k-=((1ll<<i)-1);
          ans.push_back(i);
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<ans.size();i++){
      cout<<"1 ";
      for(int j=1;j<ans[i];j++)
        cout<<"0 ";
    }
    cout<<endl;
  }

  return 0;
}
