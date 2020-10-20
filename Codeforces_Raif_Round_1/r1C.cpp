#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int t;
string s;
vector<char> v;
int main(){
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>s;
    v.clear();
    for(int i=0;i<s.size();i++){
      if(s[i]=='A')
        v.push_back('A');
      else{
        if(v.size()>0)
          v.pop_back();
        else
          v.push_back('B');
      }
    }
    cout<<v.size()<<endl;
  }

  return 0;
}
