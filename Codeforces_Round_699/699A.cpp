#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cstring>
#include <random>
#include <map>
#include <cmath>
#include <numeric>

using namespace std;

string s;
int l, u, r, d, t, px, py;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int j=1;j<=t;j++){
    cin>>px>>py;
    cin>>s;
    l =0;
    r=0;
    u=0;
    d=0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='R')
        r++;
      if(s[i]=='L')
        l++;
      if(s[i]=='U')
        u++;
      if(s[i]=='D')
        d++;
    }
    if(px>0){
      if(r<px){
        cout<<"NO"<<endl;
        continue;
      }
    }
    if(px<0){
      if(l<-px){
        cout<<"NO"<<endl;
        continue;
      }
    }
    if(py>0){
      if(u<py){
        cout<<"NO"<<endl;
        continue;
      }
    }
    if(py<0){
      if(d<-py){
        cout<<"NO"<<endl;
        continue;
      }
    }
    cout<<"YES"<<endl;
  }
  return 0;
}
