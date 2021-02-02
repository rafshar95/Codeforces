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

int q;

string s, t;

bool is_divisible(string a, string b){
  if(a.size()%b.size()!=0)
    return false;
  for(int i=0;i<a.size();i++)
    if(a[i]!=b[i%b.size()])
      return false;
  return true;
}
int main(){
  std::ios::sync_with_stdio(false);
  cin>>q;
  for(int l=0;l<q;l++){
    cin>>s>>t;
    bool found =false;
    for(int i=s.size();i>=1;i--){
      string d = s.substr(0, i);
      if(is_divisible(s,d) && is_divisible(t,d)){
        found =true;
        string res="";
        int cnt = (s.size()*t.size())/(d.size()*d.size());
        for(int i=1;i<=cnt;i++)
          res+=d;
        cout<<res<<endl;
        break;
      }
    }
    if(!found)
      cout<<"-1"<<endl;
  }

  return 0;
}
