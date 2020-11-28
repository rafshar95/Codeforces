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

using namespace std;
int t, n, n0, n1, c0, c1, h;
string s;
int main(){
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>n>>c0>>c1>>h;
    cin>>s;
    n0=0;
    n1=0;
    for(int j=0;j<s.size();j++){
      if(s[j]=='0')
        n0++;
      else
        n1++;
    }
    if(c0>c1){
      swap(c0, c1);
      swap(n0, n1);
    }
    if(c0+h<=c1){
      cout<<c0*n0+(c0+h)*n1<<endl;
    }
    else
      cout<<c0*n0+c1*n1<<endl;
  }

  return 0;
}
