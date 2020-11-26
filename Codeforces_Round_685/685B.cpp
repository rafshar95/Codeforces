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

int t, n, q;

string s;
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n>>q;
    cin>>s;
    int a, b;
    for(int i=0;i<q;i++){
      cin>>a>>b;
      bool possible = false;
      for(int j=b;j<s.size();j++)
        if(s[j]==s[b-1])
          possible=true;
      for(int j=0;j<a-1;j++)
        if(s[j]==s[a-1])
          possible=true;
      if(possible)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
  }

  return 0;
}
