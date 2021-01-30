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

string s;
int cnt[4*1000*100];
int main(){
  std::ios::sync_with_stdio(false);
  cin>>t;
  for(int l=0;l<t;l++){
    cin>>n>>s;
    for(int i=0;i<=n+1;i++)
      cnt[i]=1;
    int cur =1;
    for(int i=0;i<s.size();i++){
        if(i!=0 && s[i]!=s[i-1])
          cur++;
        if(i!=0 && s[i]==s[i-1])
          cur=1;
        if(s[i]=='L')
          cnt[i+1]+=cur;
    }
    cur =1;
    for(int i=s.size()-1;i>=0;i--){
        if(i!=s.size()-1 && s[i]!=s[i+1])
          cur++;
        if(i!=s.size()-1 && s[i]==s[i+1])
          cur=1;
        if(s[i]=='R')
          cnt[i]+=cur;
    }
    for(int i=0;i<=n;i++)
      cout<<cnt[i]<<" ";
    cout<<endl;

  }

  return 0;
}
