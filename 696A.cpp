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


int t, n;
string s;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin>>t;
  for(int l=1;l<=t;l++){
    cin>>n;
    cin>>s;

    string res="";
    for(int i=0;i<n;i++){
      if(i==0)
        res+="1";
      else
        if(res[i-1]-'0'+s[i-1]-'0'==s[i]-'0'+1)
          res+="0";
        else
          res+="1";
    }
    cout<<res<<endl;
  }


  return 0;
}
