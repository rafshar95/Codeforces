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

string s;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>s;
    int cnt1=0;
    int cnt2=0;
    int ans =0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='('){
        cnt1++;
      }
      if(s[i]==')'){
        if(cnt1>0){
          ans++;
          cnt1--;
        }
      }
      if(s[i]=='['){
        cnt2++;
      }
      if(s[i]==']'){
        if(cnt2>0){
          ans++;
          cnt2--;
        }
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}
