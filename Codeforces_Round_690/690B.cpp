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

string s, t="2020";
int te, n;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>te;
  for(int j=1;j<=te;j++){
    cin>>n;
    cin>>s;
    if(s.substr(0,4)==t || s.substr(s.size()-4, 4)==t)
      cout<<"YES"<<endl;
    else if(s[0]=='2' && s[s.size()-3]=='0' && s[s.size()-2]=='2' && s[s.size()-1]=='0')
      cout<<"YES"<<endl;
      else if(s[0]=='2' && s[1]=='0' && s[s.size()-2]=='2' && s[s.size()-1]=='0')
        cout<<"YES"<<endl;
        else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[s.size()-1]=='0')
          cout<<"YES"<<endl;
        else
          cout<<"NO"<<endl;
  }


  return 0;
}
